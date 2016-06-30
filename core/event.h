#include "global.h"
#pragma once

class Event
{
private:
    std::map<std::string, std::string> values_;
    std::string name_;
public:
    Event (const std::string& name);
    
    const std::string& GetName() const;
    void SetValueString(const std::string& key, const std::string& value);
    void SetValueInteger(const std::string& key, int32_t id);
    std::string GetValue(const std::string& key) const;
    int32_t GetValueAsInteger(const std::string& key) const;
    bool ContainsKey(const std::string& key) const;
};

