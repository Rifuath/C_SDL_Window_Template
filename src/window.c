#include "window.h"

Window create_window(const char* title, int x, int y, int width, int height )
{
	Window m;
	m.m_Title = title;
	m.m_X = x;
	m.m_Y = y;
	m.m_Width = width;
	m.m_Height = height;
	m.m_should_quit = false;

	//Initialize Sdl init video
	if(SDL_INIT_VIDEO < 0) {
		fprintf(stderr, "Error: SDL_INIT_VIDEO\n");
	}


	//Declaring m_Window & Window creation
	m.m_Window = SDL_CreateWindow(
		m.m_Title,
		m.m_X,
		m.m_Y,
		m.m_Width,
		m.m_Height,
		SDL_WINDOW_BORDERLESS
	);

	//checking the Window creation
	if(!m.m_Window) {
		fprintf(stderr, "Error: !m_Window\n");
	}

	//Declaring m_Renderer
	m.m_Renderer = SDL_CreateRenderer(m.m_Window, -1, SDL_RENDERER_ACCELERATED);

	//checking the Renderer creation
	if(!m.m_Renderer) {
		fprintf(stderr, "Error: !m_Renderer\n");
	}
	

	return m;

} // --------------end of create_window

void window_event(Window *m)
{
	//poll event
	while(SDL_PollEvent(&m->m_Event)) {
		switch (m->m_Event.type) {
			case SDL_QUIT:
				m->m_should_quit = true;
				break;
			case SDL_KEYUP:
				break;
			case SDL_KEYDOWN:
				switch (m->m_Event.key.keysym.sym) {
					case SDLK_ESCAPE:
					m->m_should_quit = true;
					break;

				}//-------------end of switch statement 2
		}//---------end of switch statement 1 

	}//----------end of while loop



	return;
}

void window_destroy(Window *m)
{
	SDL_DestroyRenderer(m->m_Renderer);
	SDL_DestroyWindow(m->m_Window);
	SDL_Quit();

	return;
}



