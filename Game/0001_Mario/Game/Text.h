#pragma once

class Image;

class Text
{
public:
	~Text();

	void SetFont(SDL_Renderer *render, const std::string &fileName);

	void Draw(SDL_Renderer *render, const std::string &text, int X, int Y, int fontSize = 16);
	void Draw(SDL_Renderer *render, const std::string &text, int X, int Y, int fontSize, int R, int G, int B);
	void DrawCenterX(SDL_Renderer *render, const std::string &text, int Y, int fontSize = 16, int R = 255, int G = 255, int B = 255);
	void Draw(SDL_Renderer *render, const std::string &text, int X, int Y, int width, int height);
	void DrawWS(SDL_Renderer *render, const std::string &text, int X, int Y, int R, int G, int B, int fontSize = 16);

	int GetTextWidth(const std::string &text, int fontSize = 16);

private:
	int getPos(int Char);
	void checkExtra(int Char);

	Image *m_font = nullptr;

	SDL_Rect m_crop = { 0,0,8,8 };
	SDL_Rect m_rect = { 0, 0, 16, 16 };

	int m_fontSize = 16;
	int m_extraLeft = 0;
	int m_nextExtraLeft = 0;
};