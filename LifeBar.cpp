#include "LifeBar.h"

LifeBar::LifeBar(TextureCodex & any, sf::RenderWindow & wnd)
	:
	sprite(any.GetTexture(int(TextureType::Heart)))
{
	wndptr = &wnd;
}

void LifeBar::Draw( Kid& any)
{
	for( int i = 0; i < any.GetHP(); i++)
	{
		sprite.setPosition(0.0f + float( i * ( Width + 5)), 50.0f);
		wndptr->draw(sprite);
	}
}
