#include "core/global.h"
#include "core/system.h"


class InputComponent;

class InputSystem : public System
{
public:
    InputSystem();
    virtual ~InputSystem();

    const static uint32_t Id = 0x1002;

    virtual void ObjectAdded(Object* obj);
    virtual void ObjectRemoved(Object* obj);

    virtual void Update(uint32_t frame, float dt);

private:

    std::list<InputComponent*> components_;
};
