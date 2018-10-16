#pragma once

class Image
{
public:
	Image() = default;
	Image(const std::string &fileName, SDL_Renderer *r);
	~Image();

	void Draw(SDL_Renderer *r, int XOffset, int YOffset);
	void Draw(SDL_Renderer *r, int XOffset, int YOffset, bool Rotate);
	void DrawVert(SDL_Renderer *r, int XOffset, int YOffset);
	void Draw(SDL_Renderer *r, SDL_Rect Crop, SDL_Rect Rect);

	SDL_Texture* GetIMG();	
	SDL_Rect GetRect();
	
	void SetIMG(std::string fileName, SDL_Renderer *r);

private:
	SDL_Texture *m_tex = nullptr;
	SDL_Rect m_rect;
};