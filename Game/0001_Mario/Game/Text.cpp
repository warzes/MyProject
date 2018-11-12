// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "stdafx.h"
#include "Text.h"
#include "Image.h"
#include "App.h"

//=============================================================================
Text::~Text()
{
	SafeDelete(m_font);
}
//=============================================================================
void Text::SetFont(SDL_Renderer *render, const std::string &fileName)
{
	m_font = new Image(fileName, render);
}
//=============================================================================
void Text::Draw(SDL_Renderer *render, const std::string &text, int X, int Y, int fontSize)
{
	m_fontSize = fontSize;
	m_extraLeft = 0;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < text.size(); i++ )
	{
		m_crop.x = getPos(text.at(i));

		m_rect.x = X + fontSize * i - m_extraLeft;
		m_rect.y = Y;
		m_rect.w = fontSize;
		m_rect.h = fontSize;
		m_font->Draw(render, m_crop, m_rect);
		m_extraLeft += m_nextExtraLeft;
		m_nextExtraLeft = 0;
	}
}
//=============================================================================
void Text::Draw(SDL_Renderer *render, const std::string &text, int X, int Y, int fontSize, int R, int G, int B)
{
	m_fontSize = fontSize;
	m_extraLeft = 0;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < text.size(); i++ )
	{
		SDL_SetTextureColorMod(m_font->GetImage(), R, G, B);
		m_crop.x = getPos(text.at(i));

		m_rect.x = X + fontSize * i - m_extraLeft;
		m_rect.y = Y;
		m_rect.w = fontSize;
		m_rect.h = fontSize;
		m_font->Draw(render, m_crop, m_rect);
		m_extraLeft += m_nextExtraLeft;
		m_nextExtraLeft = 0;
		SDL_SetTextureColorMod(m_font->GetImage(), 255, 255, 255);
	}
}
//=============================================================================
void Text::DrawCenterX(SDL_Renderer *render, const std::string &text, int Y, int fontSize, int R, int G, int B)
{
	const int X = App::GameWidth / 2 - GetTextWidth(text, fontSize) / 2;
	Draw(render, text, X, Y, fontSize, R, G, B);
}
//=============================================================================
void Text::Draw(SDL_Renderer *render, const std::string &text, int X, int Y, int width, int height)
{
	for ( size_t i = 0; i < text.size(); i++ )
	{
		m_crop.x = getPos(text.at(i));

		m_rect.x = X + width * i - m_extraLeft;
		m_rect.y = Y;
		m_rect.w = width;
		m_rect.h = height;
		m_font->Draw(render, m_crop, m_rect);
	}
}
//=============================================================================
void Text::DrawWS(SDL_Renderer *render, const std::string &text, int X, int Y, int R, int G, int B, int fontSize)
{
	m_fontSize = fontSize;
	m_extraLeft = 0;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < text.size(); i++ )
	{
		SDL_SetTextureColorMod(m_font->GetImage(), 0, 0, 0);
		m_crop.x = getPos(text.at(i));

		m_rect.x = X + fontSize * i - m_extraLeft - 1;
		m_rect.y = Y + 1;
		m_rect.w = fontSize;
		m_rect.h = fontSize;
		m_font->Draw(render, m_crop, m_rect);
		SDL_SetTextureColorMod(m_font->GetImage(), 255, 255, 255);
		m_rect.x = X + fontSize * i - m_extraLeft + 1;
		m_rect.y = Y - 1;
		m_font->Draw(render, m_crop, m_rect);
		m_extraLeft += m_nextExtraLeft;
		m_nextExtraLeft = 0;
	}
}
//=============================================================================
int Text::GetTextWidth(const std::string &text, int fontSize)
{
	int output = text.size() * fontSize;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < text.size(); i++ )
		checkExtra(text.at(i));

	output -= m_nextExtraLeft;

	return output;
}
//=============================================================================
int Text::getPos(int iChar)
{
	if ( iChar >= 43 && iChar < 91 )
	{
		checkExtra(iChar);
		return (iChar - 43) * m_crop.w + m_crop.w;
	}

	if ( iChar >= 118 && iChar < 123 )
		return (iChar - 70) * m_crop.w + m_crop.w;

	return 0;
}
//=============================================================================
void Text::checkExtra(int iChar)
{
	switch ( iChar )
	{
	case 44: case 46: case 58: case 59:
		m_nextExtraLeft += 4 * m_fontSize / m_rect.w;
		break;
	}
}
//=============================================================================