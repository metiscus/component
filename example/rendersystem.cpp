#include "rendersystem.h"
#include "render/window.h"
#include "render/image.h"
#include "core/object.h"
#include "core/component.h"
#include "core/log.h"

RenderSystem::RenderSystem()
    : System(RenderSystem::Id)
{
    log_info("RenderSystem::RenderSystem()");
    window_.reset(new Window("Example Game", 640, 480));
}

RenderSystem::~RenderSystem()
{
    window_.release();
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
    window_->MakeCurrent();
    
    window_->SwapBuffers();
}


void RenderSystem::Update(uint32_t frame, float dt)
{
    Draw();
}

void RenderSystem::LoadDataFile(const std::string& filename)
{
    Image img;
    if(!img.LoadFile("data/sprites/man0.png"))
    {
        log_warn("Unable to load an example texture.");
    }
    else
    {
        TexturePtr texPtr;
        texPtr.reset(new Texture(img));
        log_info("Loaded some demo texture.");
    }
}
