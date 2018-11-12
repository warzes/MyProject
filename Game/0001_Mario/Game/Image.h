#pragma once

class Image
{
public:
	Image(const std::string &fileName, SDL_Renderer *render);
	~Image();

	void Draw(SDL_Renderer *render, int XOffset, int YOffset);
	void Draw(SDL_Renderer *render, int XOffset, int YOffset, bool rotate);
	void DrawVert(SDL_Renderer *render, int XOffset, int YOffset);
	void Draw(SDL_Renderer *render, const SDL_Rect &crop, const SDL_Rect &rect);

	SDL_Texture* GetImage();
private:
	SDL_Texture *m_tex = nullptr;
	SDL_Rect m_rect;
};