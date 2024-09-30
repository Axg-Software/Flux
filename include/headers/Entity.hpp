#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Entity
{
    public:
        Entity(float p_x, float p_y, float p_w, float p_h, SDL_Texture* p_tex);
        float getX();
        float getY();
        float getW();
        float getH();
        void changeX(float p_x);
        void changeY(float p_y);
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();
    private:
        float x, y, w, h;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};