#include "core/global.h"
#include "core/system.h"
#include "render/texture.h"


class Window;
class RenderComponent;


class RenderSystem : public System
{
public:
    RenderSystem();
    virtual ~RenderSystem();

    const static uint32_t Id = 0x1001;

    virtual void ObjectAdded(Object* obj);
    virtual void ObjectRemoved(Object* obj);
    void Draw();
    
    virtual void Update(uint32_t frame, float dt);

    void LoadDataFile(const std::string& filename);

private:
    std::unique_ptr<Window> window_;
    std::list<RenderComponent*> components_;
    std::map<std::string, TexturePtr> textures_;
};
