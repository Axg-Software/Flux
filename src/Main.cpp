#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <RenderWindow.hpp>
#include <Entity.hpp>
#include <Utils.hpp>

int main(int argc, char* argv[])
{
    // USE THIS TO COMPILE: mingw32-make -f MakeFile

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init  HAS FAILED. ERROR: " << SDL_GetError() << std::endl;

    RenderWindow window("Flux v1.0", 1280, 720);

    bool gameRunning = true;

    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while (gameRunning)
    {
        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    gameRunning = false;
            }

            accumulator -= timeStep;

        }

        const float aplha = accumulator / timeStep; 

        window.clear();
        window.display(); 

        int frameTicks = SDL_GetTicks() - startTicks;

        if (frameTicks < 1000 / window.getRefreshRate())
            SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
    }
    

    window.cleanUp();
    SDL_Quit();

    return 0;
}