#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <Entity.hpp>

Entity::Entity(float p_x, float p_y, float p_w, float p_h, SDL_Texture* p_tex)
:x(p_x), y(p_y), w(p_w), h(p_h), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_w;
    currentFrame.h = p_h;
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

float Entity::getW()
{
    return w;
}

float Entity::getH()
{
    return h;
}

void Entity::changeX(float p_x) 
{
    x = p_x;
}

void Entity::changeY(float p_y) 
{
    y = p_y;
}

bool Entity::overlaps(Entity &p_e)
{
    if (currentFrame.x + currentFrame.w < p_e.x || currentFrame.x > p_e.x + p_e.w
    || currentFrame.y + currentFrame.h < p_e.y || currentFrame.y > p_e.y + p_e.h)
    {
        return false;
    }
    else
    {
        return true;
    }
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return(currentFrame);
}