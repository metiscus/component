#include "event.h"
#include <sstream>

Event::Event (const std::string& name)
    : name_(name)
{
    
}
    
const std::string& Event::GetName() const
{
    return name_;
}

void Event::SetValueString(const std::string& key, const std::string& value)
{
    if(values_.count(key) == 0)
    {
        values_.insert(std::make_pair(key, value));
    }
    else
    {
        values_[key] = value;
    }
}

void Event::SetValueInteger(const std::string& key, int32_t id)
{
    std::stringstream ss;
    ss<<id;

    if(values_.count(key) == 0)
    {
        values_.insert(std::make_pair(key, ss.str()));
    }
    else
    {
        values_[key] = ss.str();
    }
}

std::string Event::GetValue(const std::string& key) const
{
    std::string value;
    auto itr = values_.find(key);
    if(itr != values_.end())
    {
        value = itr->second;
    }
    return value;
}

int32_t Event::GetValueAsInteger(const std::string& key) const
{
    int32_t result = 0;
    
    auto itr = values_.find(key);
    if(itr != values_.end())
    {
        std::stringstream ss;
        ss<<itr->second;
        ss>>result;
    }
    
    return result;
}

bool Event::ContainsKey(const std::string& key) const
{
    return values_.count(key) != 0;
}
