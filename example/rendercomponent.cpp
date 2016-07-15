#include "rendercomponent.h"
#include "core/event.h"

RenderComponent::RenderComponent(Object* parent)
    : Component(parent, 0)
{
    ;
}
    
bool RenderComponent::HandleEvent(Event& event)
{
    if(!Component::HandleEvent(event))
    {
        return false;
    }
    
    if("event_died" == event.GetName())
    {
        printf("Changing representation to dead\n");
    }
    return true;
}

uint32_t RenderComponent::GetType() const 
{ 
    return 0x2001; 
}
