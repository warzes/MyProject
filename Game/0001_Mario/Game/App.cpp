#include "stdafx.h"
#include "App.h"
#include "Global.h"

static constexpr int MIN_FRAME_TIME = 16;

bool App::quitGame = false;
bool App::mouseLeftPressed = false;
bool App::mouseRightPressed = false;
int App::mouseX = 0;
int App::mouseY = 0;
bool App::m_movePressed = false;
bool App::m_keyMenuPressed = false;
bool App::m_keyS = false;
bool App::m_keyW = false;
bool App::m_keyA = false;
bool App::m_keyD = false;
bool App::m_keyShift = false;
bool App::m_keyAPressed = false;
bool App::m_keyDPressed = false;

App::App()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);

	m_window = SDL_CreateWindow("Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Global::GameWidth, Global::GameHeight, SDL_WINDOW_SHOWN);
	if ( !m_window )
		quitGame = true;

	m_render = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	
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

		SDL_RenderFillRect(m_render, NULL);


		SDL_RenderPresent(m_render);
	}
}

void App::loadIcon()
{
	const std::string fileName = "data/ico.bmp";
	SDL_Surface *loadedSurface = SDL_LoadBMP(fileName.c_str());
	if ( !loadedSurface ) return; TODO("icon warning");	
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
	SDL_SetWindowIcon(m_window, loadedSurface);
	SDL_FreeSurface(loadedSurface);
}