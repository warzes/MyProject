// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Image.h"

//=============================================================================
Image::Image(const std::string &fileName, SDL_Renderer *render)
{
	const auto fullName = "data/images/" + fileName + ".bmp";
	SDL_Surface *loadedSurface = SDL_LoadBMP(fullName.c_str());
	if ( !loadedSurface ) throw std::string("load ") + fullName + std::string(" failed!!!");
	
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));

	m_tex = SDL_CreateTextureFromSurface(render, loadedSurface);

	int width, height;
	SDL_QueryTexture(m_tex, NULL, NULL, &width, &height);
	m_rect = {0, 0, width, height };

	SDL_FreeSurface(loadedSurface);
}
//=============================================================================
Image::~Image()
{
	SDL_DestroyTexture(m_tex);
}
//=============================================================================
void Image::Draw(SDL_Renderer *render, int XOffset, int YOffset)
{
	m_rect.x = XOffset;
	m_rect.y = YOffset;
	SDL_RenderCopy(render, m_tex, NULL, &m_rect);
}
//=============================================================================
void Image::Draw(SDL_Renderer *render, int XOffset, int YOffset, bool rotate)
{
	m_rect.x = XOffset;
	m_rect.y = YOffset;
	if ( !rotate )
		SDL_RenderCopy(render, m_tex, NULL, &m_rect);
	else
		SDL_RenderCopyEx(render, m_tex, NULL, &m_rect, 180.0, NULL, SDL_FLIP_VERTICAL);
}
//=============================================================================
void Image::DrawVert(SDL_Renderer *render, int XOffset, int YOffset)
{
	m_rect.x = XOffset;
	m_rect.y = YOffset;
	SDL_RenderCopyEx(render, m_tex, NULL, &m_rect, 180.0, NULL, SDL_FLIP_HORIZONTAL);
}
//=============================================================================
void Image::Draw(SDL_Renderer *render, const SDL_Rect &Crop, const SDL_Rect &Rect)
{
	SDL_RenderCopy(render, m_tex, &Crop, &Rect);
}
//=============================================================================
SDL_Texture* Image::GetImage()
{
	return m_tex;
}
//=============================================================================