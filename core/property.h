#pragma once

#include "global.h"
#include <typeinfo>
#include <type_traits>

enum PropertyType
{
    Property_String,
    Property_Integer,
    Property_Real,
    Property_Boolean,
};

class Property
{
private:
    PropertyType type_;
    union {
        int32_t* integer_;
        double* real_;
        std::string* string_;
        bool* boolean_;
        void *data_;
    };
    
    std::string name_;
public:
    Property(PropertyType type, const std::string& name, void* ptr);
    
    const std::string& GetName() const;
    const PropertyType& GetType() const;

    const char* GetTypeCString() const;

    std::string GetValueAsString() const;
    int32_t GetValueAsInteger() const;
    double GetValueAsReal() const;
    bool GetValueAsBoolean() const;
    
    void SetValue(double real);
    void SetValue(int32_t integer);
    void SetValue(const std::string& string);
    void SetValue(bool value);
    void SetValueFromString(const std::string& string);
    
};
