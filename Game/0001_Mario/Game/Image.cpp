#include "stdafx.h"
#include "Image.h"

Image::Image(const std::string &fileName, SDL_Renderer *r)
{
	SetIMG(fileName, r);
}

Image::~Image()
{
	SDL_DestroyTexture(m_tex);
}

void Image::Draw(SDL_Renderer *r, int XOffset, int YOffset)
{
	m_rect.x = XOffset;
	m_rect.y = YOffset;

	SDL_RenderCopy(r, m_tex, NULL, &m_rect);
}

void Image::Draw(SDL_Renderer *r, int XOffset, int YOffset, bool Rotate)
{
	m_rect.x = XOffset;
	m_rect.y = YOffset;

	if ( !Rotate )
	{
		SDL_RenderCopy(r, m_tex, NULL, &m_rect);
	}
	else
	{
		SDL_RenderCopyEx(r, m_tex, NULL, &m_rect, 180.0, NULL, SDL_FLIP_VERTICAL);
	}
}

void Image::DrawVert(SDL_Renderer *r, int XOffset, int YOffset)
{
	m_rect.x = XOffset;
	m_rect.y = YOffset;

	SDL_RenderCopyEx(r, m_tex, NULL, &m_rect, 180.0, NULL, SDL_FLIP_HORIZONTAL);
}

void Image::Draw(SDL_Renderer *r, SDL_Rect Crop, SDL_Rect Rect)
{
	SDL_RenderCopy(r, m_tex, &Crop, &Rect);
}

void Image::SetIMG(std::string fileName, SDL_Renderer *r)
{
	fileName = "data/images/" + fileName + ".bmp";
	SDL_Surface *loadedSurface = SDL_LoadBMP(fileName.c_str());
	if ( !loadedSurface ) return; TODO("non load");
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));

	m_tex = SDL_CreateTextureFromSurface(r, loadedSurface);
	
	int Width, Height;
	SDL_QueryTexture(m_tex, NULL, NULL, &Width, &Height);

	m_rect.x = 0;
	m_rect.y = 0;
	m_rect.w = Width;
	m_rect.h = Height;
	SDL_FreeSurface(loadedSurface);
}

SDL_Texture* Image::GetIMG()
{
	return m_tex;
}

SDL_Rect Image::GetRect()
{
	return m_rect;
}