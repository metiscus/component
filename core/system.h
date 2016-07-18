#pragma once

#include "global.h"

class Object;

class System
{
public:
    typedef uint32_t Type;
    
    System(Type id);
    virtual ~System();
    virtual void ObjectAdded(Object* obj);
    virtual void ObjectRemoved(Object* obj);
    
    uint32_t GetType() const;
    
    virtual void Update(uint32_t frame, float dt);
    
private:
    const Type type_;
};
