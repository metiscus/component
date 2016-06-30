#pragma once
#include "core/global.h"
#include "core/component.h"

class DummyComponent : public Component
{
public:
    DummyComponent(Object* parent);
    virtual bool HandleEvent(const Event& event);
};
