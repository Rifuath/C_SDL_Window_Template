
#include "window.h"
#include "colors.h" //colors 

//other defines

#define WINDOW_WIDTH	800 
#define WINDOW_HEIGHT	800 
#define WINDOW_X (1920 / 2) - (WINDOW_WIDTH / 2) //middle of screen
#define WINDOW_Y  (1080 / 2)  - (WINDOW_HEIGHT / 2) //middle of screen

int main()
{
	Window window = create_window(
		"The Window", 
		WINDOW_X, WINDOW_Y, 
		WINDOW_WIDTH, WINDOW_HEIGHT
	);



	while (!window.m_should_quit) {

		window_event(&window);

		//clear the screen
		SDL_RenderClear(window.m_Renderer);
		//Loop start 


		//Loop end
		SDL_SetRenderDrawColor(window.m_Renderer, GREY);
		SDL_RenderPresent(window.m_Renderer);

	}//----------end of while loop


	//destroy the window
	window_destroy(&window);
	return 0;

}//-----end of main
