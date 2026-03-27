#include <SDL3/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void drawCircle(SDL_Renderer* renderer,int xcnt,int ycnt,int radius)
{
    for (int w=0;w< radius*2;w++)
    {
        for (int h=0;h<radius*2;h++)
        {
            int x=radius-w;
            int y=radius-h;
            if((x*x+y*y)<=(radius*radius))
            {
                SDL_RenderPoint(renderer,xcnt+x,ycnt+y);
            }
        }
    }
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    int width=800;
    int height=600;

    SDL_Window* window=SDL_CreateWindow("Draw a circle", width,height,0);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,NULL);

    int xcnt = width / 2;
    int ycnt = height / 2;
    int radius = 100;

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        drawCircle(renderer, xcnt, ycnt, radius);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}