#pragma once

#include "global.h"

#include "system.h"

class Event;

class World
{
public:
    void AddSystem(std::shared_ptr<System> system);

    void AddObject(std::unique_ptr<Object>);
    void RemoveObject(uint32_t id);
    Object* GetObjectById(uint32_t id);

    bool HandleEvent(Event& event);

private:
    typedef std::shared_ptr<System> SystemPtr;
    std::map<System::Type, SystemPtr> systems_;
    
    typedef std::unique_ptr<Object> ObjectPtr;
    std::map<uint32_t, ObjectPtr> objects_;
};
