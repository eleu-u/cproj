#include <iostream>
#include <string>
#include <vector>

#include <SDL2/include/SDL2/SDL.h>
#include <SDL2/include/SDL2/SDL_timer.h>
#include <SDL2/include/SDL2/SDL_image.h>
#undef main // i dont know why it errors when i dont put this but it Does

using namespace std;

SDL_Window* WINDOW = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 500, 0);
SDL_Renderer* RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED);

class Vector2{
	public:
		int x;
		int y;
		Vector2(){ // default no arguments constructor (doesnt compile if i dont put this here)
			x = 0;
			y = 0;
		}
		Vector2(int x_, int y_){ // with arguments constructor
			x = x_;
			y = y_;
		}
		string to_string(){
			return std::to_string(x) + ", " + std::to_string(y);
		}
};

class ENTITY {
	public:
		string name;
		Vector2 position;
		
		SDL_Texture* TEXTURE;
		SDL_Rect RECT;
		
		virtual void update(){};
		virtual void render(){};
};

class PLAYER: public ENTITY{ // extends entity
	public:
		int SPEED;
	
		PLAYER(Vector2 starting_position, SDL_Surface* SURFACE){
			name = "PLAYER";
			position = starting_position;
			
			TEXTURE = SDL_CreateTextureFromSurface(RENDERER, SURFACE);
			
			RECT.x = position.x;
			RECT.y = position.y;
			
			SDL_QueryTexture(TEXTURE, NULL, NULL, &RECT.w, &RECT.h);
			
			SPEED = 4;
		}
		
		void render(){
			SDL_RenderCopy(RENDERER, TEXTURE, NULL, &RECT);
		}
		 
		void update(){
			const Uint8 *keystate = SDL_GetKeyboardState(NULL);
			if (keystate[SDL_SCANCODE_W]) {
				RECT.y -= SPEED;
			}
			else if (keystate[SDL_SCANCODE_S]) {
				RECT.y += SPEED;
			}
			if (keystate[SDL_SCANCODE_A]) {
				RECT.x -= SPEED;
			}
			else if  (keystate[SDL_SCANCODE_D]) {
				RECT.x += SPEED;
			}
		}
};

vector<ENTITY*> ENTITIES; // every object in the game is in this vector which is iterated over to run the render and update functions

int main(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
	
    SDL_Surface* CUBE_SURFACE = IMG_Load("assets/cube.png");
	PLAYER player(Vector2(300, 250), CUBE_SURFACE);
	ENTITIES.push_back(&player);
 
    SDL_FreeSurface(CUBE_SURFACE); // FREES FROM MEMORY
	
    bool close = false;
    while (!close) {
        SDL_Event event;
 
        // events!!!
        while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				close = true;
			}
        }
		
        // clears the screen
        SDL_RenderClear(RENDERER);
		
        for (size_t i=0; i<ENTITIES.size(); i++){
			ENTITIES[i]->render();
			ENTITIES[i]->update();
		}
 
        SDL_RenderPresent(RENDERER); // triggers the double buffers for multiple rendering
 
        SDL_Delay(1000 / 60); // 60 FPS cap
    }
     
    SDL_Quit();
 
    return 0;
}