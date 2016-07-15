#include "world.h"
#include "event.h"
#include "object.h"
#include "system.h"
#include "component.h"

void World::AddSystem(std::shared_ptr<System> system)
{
    systems_.insert(std::make_pair(system->GetType(), std::move(system)));
}

bool World::HandleEvent(Event& event)
{
    bool ret = true;
    for(auto& itr : objects_)
    {
        if(!itr.second->HandleEvent(event))
        {
            return false;
        }
    }

    return true;
}

void World::AddObject(std::unique_ptr<Object> object)
{
    auto itr = objects_.find(object->GetId());
    if(itr == objects_.end())
    {
        // Notify the systems that the object is being added
        Object *obj = itr->second.get();
        std::map<System::Type, SystemPtr>::iterator system = systems_.begin();
        for( ; system!=systems_.end(); ++system)
        {
            system->second->ObjectAdded(object.get());
        }

        objects_.emplace(std::make_pair(object->GetId(), std::move(object)));
    }
    else
    {
        assert(false);
    }
}

void World::RemoveObject(uint32_t id)
{
    std::map<uint32_t, ObjectPtr>::iterator itr = objects_.find(id);
    if(itr != objects_.end())
    {
        // Notify the systems that the object is being removed
        Object *obj = itr->second.get();
        std::map<System::Type, SystemPtr>::iterator system = systems_.begin();
        for( ; system!=systems_.end(); ++system)
        {
            system->second->ObjectRemoved(obj);
        }

        objects_.erase(itr);
    }
}

Object* World::GetObjectById(uint32_t id)
{
    Object *obj = nullptr;
    std::map<uint32_t, ObjectPtr>::iterator itr = objects_.find(id);
    if(itr != objects_.end())
    {
        obj = itr->second.get();
    }
    return obj;
}
