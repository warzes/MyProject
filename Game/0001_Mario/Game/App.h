#pragma once

class App
{
public:
	App();
	~App();

	void MainLoop();

	static bool quitGame;

private:
	void loadIcon();
	SDL_Window *m_window = nullptr;
	SDL_Renderer *m_render = nullptr;
	SDL_Event m_mainEvent;
};