#include "global.h"
#pragma once

#include "property.h"

class Event;

class Object;
class Component
{
private:
    uint32_t priority_;
    Object *parent_;
    uint32_t id_;

    std::vector<Property> properties_;

    static uint32_t GetNextId();
public:
    Component(Object* parent, uint32_t priority);
    virtual ~Component() = default;
    virtual bool HandleEvent(Event& event) = 0;
    const uint32_t& GetPriority() const;

    const Property* GetProperty(const std::string& name) const;
    Property* GetProperty(const std::string& name);
    bool HasProperty(const std::string& name) const;
    
    const std::vector<Property>& GetProperties() const;
    
    uint32_t GetId() const;

protected:
    Object* GetParent();
    void AddProperty(Property property);
};
