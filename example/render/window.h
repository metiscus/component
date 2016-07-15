#pragma once

#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include "glad/glad.h"
#include <SDL.h>

class Window
{
public:
    Window(const std::string& title, uint32_t width, uint32_t height);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(Window&) = delete;

    void SetTitle(const std::string& title);
    void SetSize(uint32_t width, uint32_t height);
    void ShowCursor();
    void HideCursor();

    void MakeCurrent();
    void SwapBuffers();

    static void SetOpenGLHint(uint32_t hint, uint32_t value);

private:
    SDL_Window *window_;
    SDL_GLContext context_;
    std::string title_;
    uint32_t width_;
    uint32_t height_;

    static std::once_flag sdl_init_video_;
    static std::once_flag glad_init_;
};

typedef std::shared_ptr<Window> WindowPtr;
