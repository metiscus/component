#include "global.h"
#pragma once

#include "event.h"

class Component;

class Object
{
private:
    static uint32_t GetNextId();
    typedef std::unique_ptr<Component> ComponentPtr;
    std::list<ComponentPtr> components_;
    
    uint32_t id_;

public:
    Object(uint32_t id = GetNextId());
    bool HandleEvent(Event event);
    
    void AddComponent(std::unique_ptr<Component>& component);
    uint32_t GetId() const;
};
