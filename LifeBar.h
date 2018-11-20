#pragma once
#include "Kid.h"

class LifeBar : TextureList
{
public:
	LifeBar(TextureCodex& any, sf::RenderWindow& wnd);

public:
	void Draw( Kid& any );

private:
	sf::RenderWindow* wndptr;
	sf::Sprite sprite;
	const int Width = 16;
	const int Height = 14;
};