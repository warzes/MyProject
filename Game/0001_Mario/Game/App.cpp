#include "stdafx.h"
#include "App.h"

bool App::quitGame = false;

App::App()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

	m_window = SDL_CreateWindow("Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);
	if ( !m_window )
		quitGame = true;

	m_render = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	loadIcon();
}

App::~App()
{
	SDL_DestroyRenderer(m_render);
	SDL_DestroyWindow(m_window);
}

void App::MainLoop()
{
	while ( !quitGame && m_mainEvent.type != SDL_QUIT )
	{
		SDL_PollEvent(&m_mainEvent);
		SDL_RenderClear(m_render);


		SDL_RenderPresent(m_render);
	}
}

void App::loadIcon()
{
	const std::string fileName = "data/ico22.bmp";
	SDL_Surface *loadedSurface = SDL_LoadBMP(fileName.c_str());
	if ( !loadedSurface ) return; TODO("icon warning");	
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
	SDL_SetWindowIcon(m_window, loadedSurface);
	SDL_FreeSurface(loadedSurface);
}