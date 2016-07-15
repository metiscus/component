#include "window.h"
#include <cassert>
#include <cstdio>

#include "glad/glad.h"
#include <GL/gl.h>

std::once_flag Window::sdl_init_video_;
std::once_flag Window::glad_init_;

Window::Window(const std::string& title, uint32_t width, uint32_t height)
    : window_(nullptr)
    , title_(title)
    , width_(width)
    , height_(height)
{
    std::call_once(sdl_init_video_, [] () {
        if(SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            fprintf(stderr, "Failed to initialize SDL Video\n");
            assert(false);
        }
    });
    
    if(title.length() == 0)
    {
        title_ = "SDL Demo";
    }
    
    window_ = SDL_CreateWindow(
        title_.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width_,
        height_,
        SDL_WINDOW_OPENGL
    );

    if(!window_)
    {
        fprintf(stderr, "Failed to create the SDL window\n");
        assert(false);
    }
    
    context_ = SDL_GL_CreateContext(window_);

    std::call_once(glad_init_, [] () {
        if(!gladLoadGL())
        {
            fprintf(stderr, "Failed to initialize OpenGL libraries\n");
            assert(false);
        }
    });
    
    SDL_GL_SetSwapInterval(1);
}

Window::~Window()
{
    if(window_)
    {
        SDL_GL_DeleteContext(context_);
        SDL_DestroyWindow(window_);
    }
}

void Window::SetTitle(const std::string& title)
{
    if(window_)
    {
        SDL_SetWindowTitle(window_, title.c_str());
    }
    else
    {
        assert(window_);
    }
}

void Window::SetSize(uint32_t width, uint32_t height)
{
    if(window_)
    {
        SDL_SetWindowSize(window_, width, height);
        width_ = width;
        height_ = height;
    }
    else
    {
        assert(window_);
    }
}

void Window::ShowCursor()
{
    if(window_)
    {
        SDL_ShowCursor(1);
    }
    else
    {
        assert(window_);
    }
}

void Window::HideCursor()
{
    if(window_)
    {
        SDL_ShowCursor(0);
    }
    else
    {
        assert(window_);
    }
}

void Window::MakeCurrent()
{
    if(window_)
    {
        SDL_GL_MakeCurrent(window_, context_);
    }
    else
    {
        assert(window_);
    }
}

void Window::SwapBuffers()
{
    if(window_)
    {
        SDL_GL_SwapWindow(window_);
    }
    else
    {
        assert(window_);
    }
}

void Window::SetOpenGLHint(uint32_t hint, uint32_t value)
{
    SDL_GL_SetAttribute((SDL_GLattr)hint, value);
}
