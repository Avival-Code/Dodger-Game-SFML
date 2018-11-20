#include "Kid.h"

Kid::Kid(sf::RenderWindow& wnd, TextureCodex& texture, Vef2& startpos_in)
	:
	wnd(wnd),
	sprite(texture.GetTexture(int(TextureType::Kid))),
	pos_offset(Vef2(startpos_in.x - (Width / 2), startpos_in.y - (Height / 2)))
{
	grunt.openFromFile("grunt.wav");
	dead.openFromFile("Deathy.wav");
}

void Kid::Draw()
{
	wnd.draw(sprite);
}

void Kid::Update( FrameTimer& Timer)
{
	float dt = Timer.Mark();

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up))
	{
		pos_offset.y -= 3.0f * (dt * 60);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pos_offset.y += 3.0f * (dt * 60);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		pos_offset.x -= 3.0f * (dt * 60);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		pos_offset.x += 3.0f * (dt * 60);
	}

	sprite.move( { pos_offset.x, pos_offset.y} );

	pos_offset.x = 0.0f;
	pos_offset.y = 0.0f;

	if( JustHit )
	{
		if(Timer.ReturnTimerDifference() >= 2)
		{
			JustHit = false;
		}
	}

	if( HP <= 0 )
	{
		IsDead = true;
	}
}

void Kid::TakeDamage(Bat & anyBat, EyeBall & anyEye, Bone & anyBone, FrameTimer& Timer)
{
	if(!JustHit)
	{
		if ((anyBat.GetSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) && anyBat.Hurts()) ||
			(anyEye.GetSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) && anyEye.Hurts())||
			(anyBone.GetSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()) && anyBone.Hurts()) )
		{
			HP -= 1;
			JustHit = true;
			Timer.SetTimer();
			if( HP >= 1)
			{
				grunt.play();
			}
			else if( HP <= 0 && !PlayedSound)
			{
				dead.play();
				PlayedSound = true;
			}
		}
	}
}

bool Kid::GetDeadStatus()
{
	return IsDead;
}

int Kid::GetHP()
{
	return HP;
}

sf::Sprite& Kid::GetSprite()
{
	return sprite;
}
