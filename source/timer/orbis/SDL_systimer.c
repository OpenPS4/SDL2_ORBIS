/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2015 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#ifdef SDL_TIMERS_ORBIS

#include "SDL_thread.h"
#include "SDL_timer.h"
#include "SDL_error.h"
#include "../SDL_timer_c.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <orbis/libkernel.h>

static uint64_t start;
static SDL_bool ticks_started = SDL_FALSE;

void
SDL_TicksInit(void)
{
    if (ticks_started) {
        return;
    }
    ticks_started = SDL_TRUE;

    start = sceKernelGetProcessTime();
}

void
SDL_TicksQuit(void)
{
    ticks_started = SDL_FALSE;
}

Uint32 SDL_GetTicks(void)
{
    if (!ticks_started) {
        SDL_TicksInit();
    }

    uint64_t now;
    Uint32 ticks;

    now = sceKernelGetProcessTime();
    ticks = (now - start)/1000;
    return (ticks);
}

Uint64
SDL_GetPerformanceCounter(void)
{
    return SDL_GetTicks();
}

Uint64
SDL_GetPerformanceFrequency(void)
{
    return 1000;
}

void SDL_Delay(Uint32 ms)
{
    const Uint32 max_delay = 0xffffffffUL / 1000;
    if(ms > max_delay)
        ms = max_delay;
    sceKernelUsleep(ms * 1000);
}

#endif /* SDL_TIMERS_ORBIS */

/* vim: ts=4 sw=4
 */
