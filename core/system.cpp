#include "system.h"

System::System(Type id)
    : type_(id)
{
    ;
}

System::~System()
{
    ;
}

void System::ObjectAdded(Object* obj)
{
    // ignore
}

void System::ObjectRemoved(Object* obj)
{
    // ignore
}

void System::Update(uint32_t frame, float dt)
{
    // ignore
}

uint32_t System::GetType() const
{
    return type_;
}
