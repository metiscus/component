#include "global.h"
#pragma once

#include "event.h"

class Component;
class World;

class Object
{
private:
    static uint32_t GetNextId();
    typedef std::unique_ptr<Component> ComponentPtr;
    std::vector<ComponentPtr> components_;
    
    uint32_t id_;
    World *world_;

public:
    Object(World* world, uint32_t id = GetNextId());
    bool HandleEvent(Event event);
    bool HandleEvent(const std::string& name);
    
    void AddComponent(std::unique_ptr<Component>& component);
    uint32_t GetComponentCount() const;
    Component* GetComponent(uint32_t idx);
    Component* GetComponentByType(uint32_t type);

    uint32_t GetId() const;
    
    const World* GetWorld() const;
    World* GetWorld();

protected:
    void RemoveComponent(uint32_t component_id);
};
