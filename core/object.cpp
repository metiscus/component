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
    std::vector<ComponentPtr>::iterator itr;
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
    std::vector<ComponentPtr>::iterator itr;
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

uint32_t Object::GetComponentCount() const
{
    return components_.size();
}

Component* Object::GetComponent(uint32_t idx)
{
    return components_.at(idx).get();
}

Component* Object::GetComponentByType(uint32_t type)
{
    Component* ptr = nullptr;
    std::vector<ComponentPtr>::iterator itr;
    for(itr=components_.begin(); itr!=components_.end(); ++itr)
    {
        if((*itr)->GetType() == type)
        {
            ptr = (*itr).get();
            break;
        }
    }
    return ptr;
}

const World* Object::GetWorld() const
{
    return world_;
}

World* Object::GetWorld()
{
    return world_;
}

void Object::RemoveComponent(uint32_t component_id)
{
    std::vector<ComponentPtr>::iterator itr;
    for(itr=components_.begin(); itr!=components_.end(); ++itr)
    {
        if((*itr)->GetId() == component_id)
        {
            components_.erase(itr);
            break;
        }
    }
}

uint32_t Object::GetId() const
{
    return id_;
}
