#include "Bats.h"

Bat::Bat(sf::RenderWindow & wnd, TextureCodex & texture, Vef2 & startpos_in)
	:
	sprite( texture.GetTexture(int(TextureType::Bat)) ),
	pos_offset(startpos_in)
{
	wndptr = &wnd;
	sprite.setPosition( pos_offset.x, 0.0f);
}

void Bat::Draw()
{
	wndptr->draw(sprite);
}

void Bat::Update(float new_vel, float new_xpos)
{
	sprite.move( { 0.0f, velocity_y} );
	ResetPositionAndVelocity( new_vel, new_xpos );
}

void Bat::ResetPositionAndVelocity( float vel_in, float xpos_in )
{
	if (sprite.getPosition().y + Height >= wndptr->getSize().y)
	{
		sprite.setPosition( xpos_in, 0.0f);
		velocity_y = vel_in;
		respawn_count += 1;
	}
}

bool Bat::Hurts()
{
	return HurtsKids;
}

int Bat::GetRespawnCount()
{
	return respawn_count;
}

sf::Sprite & Bat::GetSprite()
{
	return sprite;
}
