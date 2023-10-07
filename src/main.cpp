
#include "include.hpp"
#include "define.hpp"
#include "structs.hpp"

#include "init.hpp"
#include "images.hpp"
#include "baseHud.hpp"

App app;  // Creating main varables

// Global numbers
uint32_t oldTickTime=0;

// Global running flags
bool running = true;
bool game_over = true;

// Texts variables and constants
SDL_Texture *Textures[IMG_count];  // Array of all textures
//Mix_Music* Musics[MUS_count];  // Array of all music
//Mix_Chunk* Sounds[SND_count];  // Array of all sound effects

// Global statick texts


// Main function
int main(int argv, char** args){
    initSDL();  // Initialasing of main SDL library
    loadAllTextures();  // Loading sprites to the game
    //loadAllAudio();  // Loading music and sounds to the game
    //loadInitFile();  // Load initialasing file file with settings


    // Initializing all objects at screen


    //Mix_PlayMusic( Musics[MUS_main], -1 );  // Infinite playing music

    // Cycle variables
    SDL_Event event;

	while(running)  // Main game cycle
	{
        // Loading screen

        // Getting events
        while( SDL_PollEvent(&event) != 0 ){  
            if (event.type == SDL_QUIT){
                running = false;  // Exit from program
            }
            /*if (event.type == SDL_KEYDOWN) {
                // Resseting field and next new generation
                if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a){
                    player.moveLeft();
                }
                if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d){
                    player.moveRight();
                }
                if (event.key.keysym.sym == SDLK_r){
                    game_over = true;
                }
            }*/
            /*if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT 
                || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d) {
                    player.stop();
                }
            }*/
            /*if (event.type == SDL_MOUSEBUTTONDOWN){
                // Getting mouse position
                int MouseX, MouseY;
                SDL_GetMouseState(&MouseX, &MouseY);
                if(esc.in(MouseX, MouseY)){  // Clicking on escape button
                    pause();
                }
            }*/
        }
        // Updating positions of objects

        // Drawing objects at screen
        SDL_RenderCopy(app.renderer, Textures[IMG_background], NULL, NULL);  // Drawing background at screen

        
        
        SDL_RenderPresent(app.renderer);  // Blitting textures on screen

        if( 1000/FPS > (SDL_GetTicks() - oldTickTime) ){  //
            SDL_Delay( 1000/FPS - (SDL_GetTicks() - oldTickTime) );  // Delaying constant time between ticks to decrease CPU loading
        }
        oldTickTime = SDL_GetTicks();  // Setting time of previous tick
	}
    // Exiting program
    //saveInitFile();  // Saving all data to setting file for next start

    // Clearing dinamic structs


    // Cleaning all data
    //unloadAllAudio();
    unloadTextures();
    cleanup();
	return 0;
}