#include "component.h"
#include <algorithm>
#include "event.h"
#include <typeinfo>

#if CompilerGCC
#include <cxxabi.h>
#endif

uint32_t Component::GetNextId()
{
    static uint32_t id = 1;
    return ++id;
}

Component::Component(Object* parent,uint32_t priority)
    : priority_(priority)
    , parent_(parent)
    , id_(GetNextId())
{
    
}

bool Component::HandleEvent(Event& event)
{
    if(event.GetName() == "debug")
    {
        
#if CompilerGCC
        int status;
        char *name = abi::__cxa_demangle(typeid(*this).name(),0,0,&status);
        printf("[Component %s]\n", name);
        free(name);
#else
        printf("[Component %s]\n", typeid(*this).name());
#endif        
        for(auto& prop: properties_)
        {
            std::string val = prop.GetValueAsString();
            printf("\t[Property: '%s': Type: '%s',  Value: %s]\n", 
                prop.GetName().c_str(), 
                prop.GetTypeCString(),
                val.c_str()
                );
        }
    }
    else if(event.GetName() == "set_property")
    {
        if(!event.ContainsKey("property") || !event.ContainsKey("value"))
        {
            assert(false);
        }
        else
        {
            std::string property_name = event.GetValue("property");
            Property *pProperty = GetProperty(property_name);
            if(pProperty == nullptr)
            {
                assert(false);
            }
            else
            {
                pProperty->SetValueFromString(event.GetValue("value"));
            }
        }
    }
    
    return true;
}

const uint32_t& Component::GetPriority() const
{
    return priority_;
}

const Property* Component::GetProperty(const std::string& name) const
{
    for(auto& itr : properties_)
    {
        if(itr.GetName() == name)
        {
            return (const Property*)&itr;
        }
    }
    return nullptr;
}

Property* Component::GetProperty(const std::string& name)
{
    for(auto& itr : properties_)
    {
        if(itr.GetName() == name)
        {
            return (Property*)&itr;
        }
    }
    return nullptr;
}

bool Component::HasProperty(const std::string& name) const
{
    for(auto& itr : properties_)
    {
        if(itr.GetName() == name)
        {
            return true;
        }
    }
    return false;
}

const std::vector<Property>& Component::GetProperties() const
{
    return properties_;
}

Object* Component::GetParent()
{
    return parent_;
}

void Component::AddProperty(Property property)
{
    properties_.emplace_back(property);
}

uint32_t Component::GetId() const
{
    return id_;
}
