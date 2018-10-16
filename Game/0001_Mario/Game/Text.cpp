#include "stdafx.h"
#include "Text.h"
#include "Image.h"
#include "Global.h"

Text::Text()
{
	m_crop.x = 0;
	m_crop.y = 0;
	m_crop.w = 8;
	m_crop.h = 8;

	m_rect.x = 0;
	m_rect.y = 0;
	m_rect.w = 16;
	m_rect.h = 16;
}

Text::~Text(void)
{
	SafeDelete(m_font);
}

void Text::Draw(SDL_Renderer *r, const std::string &Text, int X, int Y, int fontSize)
{
	m_fontSize = fontSize;
	m_extraLeft = 0;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < Text.size(); i++ )
	{
		m_crop.x = getPos(Text.at(i));

		m_rect.x = X + fontSize * i - m_extraLeft;
		m_rect.y = Y;
		m_rect.w = fontSize;
		m_rect.h = fontSize;
		m_font->Draw(r, m_crop, m_rect);
		m_extraLeft += m_nextExtraLeft;
		m_nextExtraLeft = 0;
	}
}

void Text::Draw(SDL_Renderer *r, const std::string &Text, int X, int Y, int fontSize, int R, int G, int B)
{
	m_fontSize = fontSize;
	m_extraLeft = 0;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < Text.size(); i++ )
	{
		SDL_SetTextureColorMod(m_font->GetIMG(), R, G, B);
		m_crop.x = getPos(Text.at(i));

		m_rect.x = X + fontSize * i - m_extraLeft;
		m_rect.y = Y;
		m_rect.w = fontSize;
		m_rect.h = fontSize;
		m_font->Draw(r, m_crop, m_rect);
		m_extraLeft += m_nextExtraLeft;
		m_nextExtraLeft = 0;
		SDL_SetTextureColorMod(m_font->GetIMG(), 255, 255, 255);
	}
}

void Text::DrawCenterX(SDL_Renderer *r, const std::string &Text, int Y, int fontSize, int R, int G, int B)
{
	const int X = Global::GameWidth / 2 - GetTextWidth(Text, fontSize) / 2;
	Draw(r, Text, X, Y, fontSize, R, G, B);
}

void Text::Draw(SDL_Renderer *r, const std::string &Text, int X, int Y, int Width, int Height)
{
	for ( size_t i = 0; i < Text.size(); i++ )
	{
		m_crop.x = getPos(Text.at(i));

		m_rect.x = X + Width * i - m_extraLeft;
		m_rect.y = Y;
		m_rect.w = Width;
		m_rect.h = Height;
		m_font->Draw(r, m_crop, m_rect);
	}
}

void Text::DrawWS(SDL_Renderer *r, const std::string &Text, int X, int Y, int R, int G, int B, int fontSize)
{
	m_fontSize = fontSize;
	m_extraLeft = 0;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < Text.size(); i++ )
	{
		SDL_SetTextureColorMod(m_font->GetIMG(), 0, 0, 0);
		m_crop.x = getPos(Text.at(i));

		m_rect.x = X + fontSize * i - m_extraLeft - 1;
		m_rect.y = Y + 1;
		m_rect.w = fontSize;
		m_rect.h = fontSize;
		m_font->Draw(r, m_crop, m_rect);
		SDL_SetTextureColorMod(m_font->GetIMG(), 255, 255, 255);
		m_rect.x = X + fontSize * i - m_extraLeft + 1;
		m_rect.y = Y - 1;
		m_font->Draw(r, m_crop, m_rect);
		m_extraLeft += m_nextExtraLeft;
		m_nextExtraLeft = 0;
	}
}

int Text::GetTextWidth(const std::string &Text, int fontSize)
{
	int iOutput = Text.size() * fontSize;
	m_nextExtraLeft = 0;

	for ( size_t i = 0; i < Text.size(); i++ )
	{
		checkExtra(Text.at(i));
	}

	iOutput -= m_nextExtraLeft;

	return iOutput;
}

int Text::getPos(int iChar)
{
	if ( iChar >= 43 && iChar < 91 )
	{
		checkExtra(iChar);
		return (iChar - 43) * m_crop.w + m_crop.w;
	}

	if ( iChar >= 118 && iChar < 123 )
	{ // v w x y z
		return (iChar - 70) * m_crop.w + m_crop.w;
	}

	return 0;
}

void Text::checkExtra(int iChar)
{
	switch ( iChar )
	{
	case 44: case 46: case 58: case 59:
		m_nextExtraLeft += 4 * m_fontSize / m_rect.w;
		break;
	}
}

void Text::SetFont(SDL_Renderer *r, const std::string &fileName)
{
	m_font = new Image(fileName, r);
}