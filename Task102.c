#include <SDL3/SDL.h>
#include <math.h>
#include <stdbool.h>

void drawCircle(SDL_Renderer* renderer,int xcnt,int ycnt,int radius)
{
    for(int w=-radius;w<radius;w++)
    {
        for(int h=-radius;h<=radius;h++)
        {
            if(w*w+h*h<=radius*radius)
            {
                SDL_RenderPoint(renderer,xcnt+w,ycnt+h);
            }
        }
    }
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);

    int width=800;
    int height=600;

    int radius=2;
    int maxradius=2;

    int xcnt=width/2;
    int ycnt=height/2;

    SDL_Window* window=SDL_CreateWindow("Growing Circle", width, height, 0);
    SDL_Renderer* renderer=SDL_CreateRenderer(window, NULL);

    bool ok=true;
    SDL_Event event;

    while(ok)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type==SDL_EVENT_QUIT)
            {
                ok=false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        drawCircle(renderer,xcnt,ycnt,radius);

        SDL_RenderPresent(renderer);

        radius+=2;
        if(xcnt+radius>=width||xcnt-radius<=0||ycnt+radius>=height||ycnt-radius<=0)
        {
            radius=maxradius;
        }

        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}