#include "dummy.h"
#include "core/event.h"

DummyComponent::DummyComponent(Object* parent)
    : Component(parent, 100)
{
    
}

bool DummyComponent::HandleEvent(const Event& event)
{
    if(event.GetName() == "event_start_frame")
    {
        printf("[DummyComponent] : Starting frame!\n");
    }
    return true;
}
