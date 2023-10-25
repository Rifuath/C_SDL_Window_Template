#ifndef WINDOW_H
#define WINDOW_H

//std libraries
#include <stdbool.h> // booleans
#include <stdio.h> //	printf , fprintf 

//SDL libraries
#include <SDL.h>



typedef struct {

	//SDL 
	SDL_Window *m_Window;
	SDL_Renderer *m_Renderer;
	SDL_Event m_Event;



	int m_X, m_Y;
	int m_Width, m_Height;
	const char* m_Title;
	
	bool m_should_quit;

	
}Window;


Window create_window(const char* title, int x, int y, int width, int height );
void window_event(Window *m);
void window_destroy(Window *m);

#endif // !WINDOW_H

