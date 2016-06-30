#pragma once
#include "core/global.h"
#include "core/component.h"

class LivingComponent : public Component
{
private:
    int32_t health_;
    int32_t max_health_;

public:
    LivingComponent(Object* parent);
    
    virtual bool HandleEvent(Event& event);
};
