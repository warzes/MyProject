#pragma once

class Image;

class Text
{
public:
	Text();
	~Text();

	void Draw(SDL_Renderer *r, const std::string &Text, int X, int Y, int fontSize = 16);
	void Draw(SDL_Renderer *r, const std::string &Text, int X, int Y, int fontSize, int R, int G, int B);
	void DrawCenterX(SDL_Renderer *r, const std::string &Text, int Y, int fontSize = 16, int R = 255, int G = 255, int B = 255);
	void Draw(SDL_Renderer *r, const std::string &Text, int X, int Y, int Width, int Height);
	void DrawWS(SDL_Renderer *r, const std::string &Text, int X, int Y, int R, int G, int B, int fontSize = 16);

	int GetTextWidth(const std::string &Text, int fontSize = 16);

	void SetFont(SDL_Renderer *r, const std::string &fileName);

private:
	int getPos(int Char);
	void checkExtra(int Char);

	Image *m_font = nullptr;

	SDL_Rect m_crop;
	SDL_Rect m_rect;

	int m_fontSize = 16;
	int m_extraLeft = 0;
	int m_nextExtraLeft = 0;
};