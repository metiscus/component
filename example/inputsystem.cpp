#include "core/global.h"
#include "core/log.h"
#include "inputsystem.h"

#include <SDL.h>
#include <cstdlib>

InputSystem::InputSystem()
    : System(InputSystem::Id)
{
    log_info("InputSystem::InputSystem()");
}

InputSystem::~InputSystem()
{
    
}

void InputSystem::ObjectAdded(Object* obj)
{
    
}

void InputSystem::ObjectRemoved(Object* obj)
{
    
    
}

void InputSystem::Update(uint32_t frame, float dt)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
        }
    }
}
