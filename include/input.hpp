//
// Created by stewa on 15/06/2024.
//
#pragma once
#include <SDL3/SDL.h>

namespace Input
{
    class Keyboard
    {
    public:
        static Uint32 press(const SDL_Event& evt);
    };

    class Mouse
    {
    public:
        static Uint32 click(const SDL_Event& evt);
    };

    class Event
    {
    public:
        static Uint32 trigger();
    };
} // namespace Input
