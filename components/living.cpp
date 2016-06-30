#include "living.h"
#include "core/event.h"
#include "core/object.h"

LivingComponent::LivingComponent(Object* parent)
    : Component(parent, 100)
    , health_(100)
    , max_health_(100)
{
    AddProperty(Property(Property_Integer, "health", &health_));
    AddProperty(Property(Property_Integer, "max_health", &max_health_));
}
    
bool LivingComponent::HandleEvent(Event& event)
{
    if(!Component::HandleEvent(event))
    {
        return false;
    }

    if(event.GetName() == "take_damage")
    {
        health_ -= event.GetValueAsInteger("damage");
        
        if(health_ <= 0)
        {
            Object* parent = GetParent();
            printf("[object: %u] i'm dead!\n", parent->GetId());

            Event evnt("event_died");
            parent->HandleEvent(evnt);
        }
    }
    return true;
}
