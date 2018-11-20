#include "Eyeball.h"

EyeBall::EyeBall(sf::RenderWindow & wnd, TextureCodex & texture, Vef2 & startpos_in)
	:
	sprite(texture.GetTexture(int(TextureType::Eyeball))),
	pos_offset(startpos_in)
{
	wndptr = &wnd;
	sprite.setPosition(pos_offset.x, 0.0f);
}

void EyeBall::Draw()
{
	if( HurtsKids )
	{
		wndptr->draw(sprite);
	}
}

void EyeBall::Update(float new_vel, float new_xpos, Bat& any)
{
	if( any.GetRespawnCount() > 3)
	{
		HurtsKids = true;
	}

	if ( HurtsKids )
	{
		sprite.move({ 0.0f, velocity_y });
		ResetPositionAndVelocity(new_vel, new_xpos);
	}
}

void EyeBall::ResetPositionAndVelocity(float vel_in, float xpos_in)
{
	if (sprite.getPosition().y + Height >= wndptr->getSize().y)
	{
		sprite.setPosition(xpos_in, 0.0f);
		velocity_y = vel_in;
		respawn_count += 1;
	}
}

bool EyeBall::Hurts()
{
	return HurtsKids;
}

int EyeBall::GetRespawnCount()
{
	return respawn_count;
}

sf::Sprite & EyeBall::GetSprite()
{
	return sprite;
}
