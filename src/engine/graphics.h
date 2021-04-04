//
// Created by Diego Santos Seabra on 31/03/21.
//

#ifndef MARIO_GRAPHICS_H
#define MARIO_GRAPHICS_H

#include <SDL.h>
#include "color.h"

struct WindowSize
{
    int width, height;
    WindowSize(int width, int height) : width(width), height(height) {};
};

namespace Graphics
{
    void init();
    void initSpriteRenderData();

    void frame();

    // Clearing
    void clear();
    void clear(Color color);

    // Drawing
    void draw();

    // Cleanup
    void shutdown();
    // TODO: Implement
    void cleanUpRenderData();

    // Getters
    WindowSize getWindowSize();
    unsigned int getQuadVAO();
}


#endif //MARIO_GRAPHICS_H
