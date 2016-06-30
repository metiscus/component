#pragma once
#include "core/global.h"
#include "core/component.h"

class DamageReductionEffect : public Component
{
private:
    int32_t percent_;

public:
    DamageReductionEffect(Object* parent);
    
    virtual bool HandleEvent(Event& event);
};
