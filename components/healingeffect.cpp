#include "healingeffect.h"
#include "core/event.h"
#include "core/object.h"

HealingEffect::HealingEffect(Object* parent)
    : Component(parent, 100)
    , duration_(0)
    , quantity_(0)
{
    AddProperty(Property(Property_Integer, "duration", &duration_));
    AddProperty(Property(Property_Integer, "quantity", &quantity_));
}
    
bool HealingEffect::HandleEvent(Event& event)
{
    if(!Component::HandleEvent(event))
    {
        return false;
    }

    if(event.GetName() == "event_start_frame" && (duration_ > 0))
    {
        --duration_;

        Event heal("heal_damage");
        heal.SetValueInteger("quantity", quantity_);
        GetParent()->HandleEvent(heal);
        
        if(duration_ == -1)
        {
            Event remove_me("remove_component");
            remove_me.SetValueInteger("component_id", GetId());
            GetParent()->HandleEvent(remove_me);
        }
    }
    return true;
}
