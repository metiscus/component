#include "rendersystem.h"
#include "render/window.h"
#include "core/object.h"
#include "core/component.h"

RenderSystem::RenderSystem()
    : System(RenderSystem::Id)
{
    window_.reset(new Window("Example Game", 640, 480));
}

RenderSystem::~RenderSystem()
{
    
}

void RenderSystem::ObjectAdded(Object* obj)
{
    RenderComponent* render_comp = (RenderComponent*)obj->GetComponentByType(0x2001);
}

void RenderSystem::ObjectRemoved(Object* obj)
{
    
}

void RenderSystem::Draw()
{
    
}
