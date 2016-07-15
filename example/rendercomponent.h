#pragma once

#include "core/global.h"
#include "core/component.h"

class RenderComponent : public Component
{
public:
    RenderComponent(Object* parent);
    
    virtual bool HandleEvent(Event& event);
    virtual uint32_t GetType() const;
};
