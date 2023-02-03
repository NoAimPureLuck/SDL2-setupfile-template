#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>
#include "RenderWindow.hpp"

int main(int argc, char* args[])
{
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "HEY.. SDL_INIT HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    
    if(!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_INIT has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME v1.0", 500, 300);
    
    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        
        // Uint64 start = SDL_GetPerformanceCounter();
        while (SDL_PollEvent(&event))  
        {                     
            if(event.type == SDL_QUIT)  
                gameRunning = false;
        }    
        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        if(keystates[SDL_SCANCODE_UP]) {
            continue;
        }
        if(keystates[SDL_SCANCODE_DOWN]) {
            continue;

        }
        
        window.clear();
        window.render();
        window.display();
        /*
        Uint64 end = SDL_GetPerformanceCounter();
        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        if (gameRunning)
            SDL_Delay(floor(16.666f - elapsedMS));
        */
        
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}