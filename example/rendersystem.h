#include "core/global.h"
#include "core/system.h"


class Window;
class RenderComponent;


class RenderSystem : public System
{
public:
    RenderSystem();
    virtual ~RenderSystem();

    const static uint32_t Id = 0x1000;

    virtual void ObjectAdded(Object* obj);
    virtual void ObjectRemoved(Object* obj);
    void Draw();

private:
    std::unique_ptr<Window> window_;
    std::list<RenderComponent*> components_;
};
