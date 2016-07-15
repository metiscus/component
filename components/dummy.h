#pragma once
#include "core/global.h"
#include "core/component.h"

class DummyComponent : public Component
{
public:
    DummyComponent(Object* parent);
    virtual bool HandleEvent(const Event& event);
    virtual uint32_t GetType() const { return 0x1002; }
};
