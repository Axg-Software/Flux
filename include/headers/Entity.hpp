#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Entity
{
    public:
        Entity(float p_x, float p_y, SDL_Texture* p_tex);
        float getX();
        float getY();
        void changeX(float p_x);
        void changeY(float p_y);
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();
    private:
        float x, y;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};