#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // This turns the main function in this file into a macro which SDL replaces with WinMain in Windows
#include <iostream>
#include "constants.hpp"
#include "errors.hpp"
#include "input.hpp"
#include "renderer.hpp"
#include "window.hpp"
#include "vulkan/vulkan_core.h"

int main(int, char*[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return Error::InitializingSdl;
    }

    constexpr uint64_t SDL_WINDOW_FLAGS = SDL_WINDOW_VULKAN; // for now only flag we want is Vulkan rendering
    const Window window{Constants::WINDOW_TITLE.data(),
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        1280,
                        720,
                        SDL_WINDOW_FLAGS};
    if (!window.m_sdl)
    {
        return Error::CreatingSdlWindow;
    }

    const Renderer renderer{window};
    if (!renderer.m_sdl)
    {
        return Error::CreatingSdlRenderer;
    }

    while (Input::Event::trigger() != SDL_EVENT_QUIT)
    {
        renderer.renderRectangle(Colors::GREEN, Transparency::OPAQUE);
    }

    SDL_Quit();
    return 0;
}
