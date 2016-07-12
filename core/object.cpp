#include "object.h"
#include "component.h"

uint32_t Object::GetNextId()
{
    static uint32_t id = 1;
    return ++id;
}

Object::Object(World* world, uint32_t id)
    : id_(id)
    , world_(world)
{
    
}

bool Object::HandleEvent(Event event)
{
    std::list<ComponentPtr>::iterator itr;
    for(itr=components_.begin(); itr!=components_.end(); ++itr)
    {
        if(!(*itr)->HandleEvent(event)) 
        {
            return false;
        }
    }
    
    return true;
}

bool Object::HandleEvent(const std::string& name)
{
    return HandleEvent(Event(name));
}

void Object::AddComponent(std::unique_ptr<Component>& component)
{
    std::list<ComponentPtr>::iterator itr;
    for(itr=components_.begin(); itr!=components_.end(); ++itr)
    {
        if((*itr)->GetPriority() < component->GetPriority())
        {
            components_.emplace(itr, std::move(component));
            return;
        }
    }
    
    components_.emplace_back(std::move(component));
}

void Object::RemoveComponent(uint32_t component_id)
{
    std::list<ComponentPtr>::iterator itr;
    for(itr=components_.begin(); itr!=components_.end(); ++itr)
    {
        if((*itr)->GetId() == component_id)
        {
            components_.remove(*itr);
            break;
        }
    }
}

uint32_t Object::GetId() const
{
    return id_;
}
