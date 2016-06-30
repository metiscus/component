#pragma once
#include "core/global.h"
#include "core/component.h"

class HealingEffect : public Component
{
private:
    int32_t duration_;
    int32_t quantity_;

public:
    HealingEffect(Object* parent);
    
    virtual bool HandleEvent(Event& event);
};
