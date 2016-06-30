#include "core/global.h"

#include "core/event.h"
#include "core/object.h"
#include "components/living.h"
#include "components/damagereductioneffect.h"
#include "components/healingeffect.h"

int main(int argc, char** argv)
{
    typedef std::unique_ptr<Object> ObjectPtr;
    std::vector<ObjectPtr> objects;
    
    //create an object
    {
        ObjectPtr myObject;
        myObject.reset(new Object());

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

        objects.emplace_back(std::move(myObject));
    }

    //create an object 2
    {
        ObjectPtr myObject;
        myObject.reset(new Object());

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
    
    for(uint32_t ii=0; ii<20; ++ii)
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
    }

    return 0;
}
