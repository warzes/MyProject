#pragma once

class App
{
public:
	App();
	~App();

	void MainLoop();

	static bool quitGame;

	static bool mouseLeftPressed, mouseRightPressed;
	static int mouseX, mouseY;

private:
	void loadIcon();
	SDL_Window *m_window = nullptr;
	SDL_Renderer *m_render = nullptr;
	SDL_Event m_mainEvent;

	// ----- INPUT
	static bool m_movePressed, m_keyMenuPressed, m_keyS, m_keyW, m_keyA, m_keyD, m_keyShift;
	static bool m_keyAPressed, m_keyDPressed;
};