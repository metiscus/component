#include "core/global.h"

#include "core/event.h"
#include "core/object.h"
#include "core/world.h"
#include "components/living.h"
#include "components/damagereductioneffect.h"
#include "components/healingeffect.h"
#include "rendersystem.h"
#include "inputsystem.h"
#include "rendercomponent.h"

int main(int argc, char** argv)
{
    typedef std::unique_ptr<Object> ObjectPtr;
    std::vector<ObjectPtr> objects;
    
    World theWorld;
    
    std::shared_ptr<RenderSystem> render;
    render.reset(new RenderSystem());
    
    theWorld.AddSystem(render);
    
    std::shared_ptr<System> input;
    input.reset(new InputSystem());
    
    theWorld.AddSystem(std::static_pointer_cast<System>(input));
    
    
    render->LoadDataFile("data/data.txt");

    //create an object
    {
        ObjectPtr myObject;
        myObject.reset(new Object(&theWorld));

        std::unique_ptr<Component> component;
        component.reset(new LivingComponent(myObject.get()));
        myObject->AddComponent(component);
        
        std::unique_ptr<Component> component2;
        component2.reset(new HealingEffect(myObject.get()));
        
        Event buffness("set_property");
        buffness.SetValueString("property", "duration");
        buffness.SetValueString("value", "5");
        component2->HandleEvent(buffness);
        
        buffness.SetValueString("property", "quantity");
        buffness.SetValueString("value", "20");
        component2->HandleEvent(buffness);
        
        myObject->AddComponent(component2);
        
        std::unique_ptr<Component> component3;
        component3.reset(new RenderComponent(myObject.get()));
        myObject->AddComponent(component3);

        objects.emplace_back(std::move(myObject));
    }

    //create an object 2
    {
        ObjectPtr myObject;
        myObject.reset(new Object(&theWorld));

        std::unique_ptr<Component> component;
        component.reset(new LivingComponent(myObject.get()));
        myObject->AddComponent(component);

        std::unique_ptr<Component> component2;
        component2.reset(new DamageReductionEffect(myObject.get()));

        Event buffness("set_property");
        buffness.SetValueString("property", "max_health");
        buffness.SetValueString("value", "150");
        component2->HandleEvent(buffness);
        
        buffness.SetValueString("property", "health");
        buffness.SetValueString("value", "150");
        component2->HandleEvent(buffness);

        myObject->AddComponent(component2);


        objects.emplace_back(std::move(myObject));
    }

    Event debug("debug");

    for(auto &obj : objects)
    {
        obj->HandleEvent(debug);
    }

    Event startFrame("event_start_frame");
    
    for(uint32_t ii=0; ii<2000; ++ii)
    {
        printf("==========[ %5d ]==========\n", ii);
        for(auto& object : objects)
        {
            Event damage("take_damage");
            damage.SetValueInteger("damage", 20);
            
            object->HandleEvent(startFrame);
            object->HandleEvent(damage);
            //object->HandleEvent(debug);
        }
        
        theWorld.Update(ii, 1.0/60.0);
    }

    return 0;
}
