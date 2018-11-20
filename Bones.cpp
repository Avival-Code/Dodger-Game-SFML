#include "Bones.h"

Bone::Bone(sf::RenderWindow& wnd, TextureCodex & texture, Vef2 & startpos_in)
	:
	sprite( texture.GetTexture( int(TextureType::Bone) ) ),
	pos_offset( startpos_in )
{
	wndptr = &wnd;
	sprite.setPosition(pos_offset.x, pos_offset.y);
}

Bone::Bone(sf::RenderWindow & wnd, TextureCodex & texture, Vef2 & startpos_in, bool Reversed_in)
	:
	sprite( texture.GetTexture( int(TextureType::Bone) ) ),
	pos_offset( startpos_in ),
	Reversed( Reversed_in )
{
	wndptr = &wnd;
	sprite.setPosition( pos_offset.x, pos_offset.y );

}

void Bone::Draw()
{
	if( HurtsKids )
	{
		wndptr->draw(sprite);
	}
}

void Bone::Update(float new_vel, float new_ypos, EyeBall& any)
{
	if( Reversed && velocity_x > 0.0f)
	{
		velocity_x = -velocity_x;
	}

	if( Reversed && any.GetRespawnCount() > 7)
	{
		HurtsKids = true;
	}

	if ( !Reversed && any.GetRespawnCount() > 3)
	{
		HurtsKids = true;
	}

	if (HurtsKids)
	{
		sprite.move({ velocity_x , 0.0f });
		ResetPositionAndVelocity(new_vel, new_ypos);
	}
}

void Bone::ResetPositionAndVelocity(float vel_in, float ypos_in)
{
	if( !Reversed )
	{
		if (sprite.getPosition().x + Width >= wndptr->getSize().x)
		{
			sprite.setPosition(0.0f, ypos_in);
			velocity_x = vel_in;
		}
	}
	else
	{
		if (sprite.getPosition().x < 0.0f)
		{
			sprite.setPosition( float( wndptr->getSize().x - Width ), ypos_in);
			velocity_x = vel_in;
		}
	}
}

bool Bone::Hurts()
{
	return HurtsKids;
}

int Bone::GetWidth()
{
	return Width;
}

sf::Sprite & Bone::GetSprite()
{
	return sprite;
}
