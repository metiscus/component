#include "property.h"

Property::Property(PropertyType type, const std::string& name, void* data)
    : type_(type)
    , data_(data)
    , name_(name)
{
    ;
}

const char* Property::GetTypeCString() const
{
    const char* strings[] = 
    {
        "Invalid",
        "String",
        "Integer",
        "Real",
        nullptr
    };
    
    return strings[type_];
}

const std::string& Property::GetName() const
{
    return name_;
}

const PropertyType& Property::GetType() const
{
    return type_;
}

std::string Property::GetValueAsString() const
{
    switch(type_)
    {
        case Property_String:
        {
            return *string_;
            break;
        }
        
        case Property_Integer:
        {
            return std::to_string(*integer_);
            break;
        }
        
        case Property_Real:
        {
            return std::to_string(*real_);
            break;
        }
        
        case Property_Boolean:
        {
            return *boolean_ ? "true" : "false";
            break;
        }
        
        default:
            assert(false);
    }
    
    return "";
}

int32_t Property::GetValueAsInteger() const
{
    switch(type_)
    {
        case Property_String:
        {
            return std::stol(*string_);
            break;
        }
        
        case Property_Integer:
        {
            return *integer_;
            break;
        }
        
        case Property_Real:
        {
            return int32_t(*real_);
            break;
        }

        case Property_Boolean:
        {
            return *boolean_ ? 1 : 0;
            break;
        }

        default:
            assert(false);
    }
    
    return 0;
}

double Property::GetValueAsReal() const
{
    switch(type_)
    {
        case Property_String:
        {
            return std::stod(*string_);
            break;
        }
        
        case Property_Integer:
        {
            return double(*integer_);
            break;
        }
        
        case Property_Real:
        {
            return *real_;
            break;
        }
        
        case Property_Boolean:
        {
            return *boolean_ ? 1. : 0.;
            break;
        }
        
        default:
            assert(false);
    }
    
    return 0.;
}

bool Property::GetValueAsBoolean() const
{
    switch(type_)
    {
        case Property_String:
        {
            return string_->size() > 0;
            break;
        }
        
        case Property_Integer:
        {
            return *integer_ != 0;
            break;
        }
        
        case Property_Real:
        {
            return *real_ != 0.0;
            break;
        }
        
        case Property_Boolean:
        {
            return *boolean_;
            break;
        }
        
        default:
            assert(false);
    }
    
    return 0.;
}

void Property::SetValue(double real)
{
    assert(type_ == Property_Real);
    *real_ = real;
}

void Property::SetValue(int32_t integer)
{
    assert(type_ == Property_Integer);
    *integer_ = integer;
}

void Property::SetValue(const std::string& string)
{
    assert(type_ == Property_String);
    *string_ = string;
}

void Property::SetValue(bool value)
{
    assert(type_ == Property_Boolean);
    *boolean_ = value;
}

void Property::SetValueFromString(const std::string& string)
{
    switch(type_)
    {
        case Property_String:
            *string_ = string;
            break;
        case Property_Integer:
            *integer_ = std::stol(string);
            break;
        case Property_Real:
            *real_ = std::stod(string);
            break;
        default:
            assert(false);
    }
}
