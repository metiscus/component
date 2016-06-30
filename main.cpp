#include "core/global.h"

#include "core/event.h"
#include "core/object.h"
#include "components/living.h"
#include "components/damagereductioneffect.h"

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
        myObject->AddComponent(component2);
        
        Event buffness("set_property");
        buffness.SetValueString("property", "max_health");
        buffness.SetValueString("value", "150");
        myObject->HandleEvent(buffness);
        
        buffness.SetValueString("property", "health");
        buffness.SetValueString("value", "150");

        objects.emplace_back(std::move(myObject));
    }

    Event debug("debug");

    for(auto &obj : objects)
    {
        obj->HandleEvent(debug);
    }

    Event startFrame("event_start_frame");
    
    for(uint32_t ii=0; ii<10; ++ii)
    {
        for(auto& object : objects)
        {
            Event damage("take_damage");
            damage.SetValueInteger("damage", 20);
            
            object->HandleEvent(damage);
            object->HandleEvent(debug);
        }
    }

    return 0;
}
