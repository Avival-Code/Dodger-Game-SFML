#include "Game.h"

Game::Game(sf::RenderWindow& in_wnd, TextureCodex & in_textures)
	:
	wnd( &in_wnd ),
	textures( in_textures ),
	Kid1( new Kid( *wnd, textures, Vef2(float(wnd->getSize().x / 2), float(wnd->getSize().y / 2))) ),
	Bats( new Bat[10]),
	EyeBalls( new EyeBall[10] ),
	BonesLeft( new Bone[10]),
	BonesRight( new Bone[10]),
	xDist(0, ((wnd->getSize().x - 1) - 50)),
	yDist(0, ((wnd->getSize().y - 1) - 50)),
	vDist(1, 7),
	Hearts( textures, *wnd )
{ 
	readyButtonTexture.loadFromFile("Ready.png");
	deadScreenTexture.loadFromFile("dead.png");

	for(int i = 0; i < 10; i++)
	{
		Bats[i] = { *wnd, textures, Vef2( float(xDist(rng)), 0.0f)};
	}
	for (int i = 0; i < 10; i++)
	{
		EyeBalls[i] = { *wnd, textures, Vef2(float(xDist(rng)), 0.0f) };
	}
	for (int i = 0; i < 10; i++)
	{
		BonesLeft[i] = { *wnd, textures, Vef2( 0.0f, float(yDist(rng))) };
	}
	for (int i = 0; i < 10; i++)
	{
		BonesRight[i] = { *wnd, textures, Vef2( float( wnd->getSize().x - BonesRight[i].GetWidth() ), float(yDist(rng))), true };
	};
}

Game::~Game()
{
	delete Kid1;
	delete [] Bats;
	delete [] EyeBalls;
	delete [] BonesLeft;
	delete [] BonesRight;
}

void Game::ExecuteGameLogic()
{
	UpdateModel();
	ComposeFrame();
}

void Game::UpdateModel()
{
	if (GameStart)
	{
		ScoreBoard.CalculateScore( Timer, *Kid1 );
		for (int i = 0; i < 10; i++)
		{
			Kid1->Update(Timer);
			Kid1->TakeDamage(Bats[i], EyeBalls[i], BonesLeft[i], Timer);
		}
		for (int i = 0; i < 10; i++)
		{
			Bats[i].Update(float(vDist(rng)), float(xDist(rng)));
		}
		for (int i = 0; i < 10; i++)
		{
			EyeBalls[i].Update(float(vDist(rng)), float(xDist(rng)), Bats[0]);
		}
		for (int i = 0; i < 10; i++)
		{
			BonesLeft[i].Update(float(vDist(rng)), float(yDist(rng)), EyeBalls[0]);
		}
		for (int i = 0; i < 10; i++)
		{
			BonesRight[i].Update(float(vDist(rng)), float(yDist(rng)), EyeBalls[0]);
		};
	}
	else
	{
		buttonsprite.setTexture( readyButtonTexture );
		buttonsprite.setPosition( float((wnd->getSize().x / 2) - 27), float((wnd->getSize().y / 2) - 27) );
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			GameStart = true;
		}
	}
}

void Game::ComposeFrame()
{
	if(GameStart)
	{
		if (!Kid1->GetDeadStatus())
		{
			Kid1->Draw();
			Hearts.Draw(*Kid1);
			ScoreBoard.WriteMessage( *wnd, *Kid1, Size);
			for (int i = 0; i < 10; i++)
			{
				Bats[i].Draw();
			}
			for (int i = 0; i < 10; i++)
			{
				EyeBalls[i].Draw();
			}
			for (int i = 0; i < 10; i++)
			{
				BonesLeft[i].Draw();
			}
			for (int i = 0; i < 10; i++)
			{
				BonesRight[i].Draw();
			};
		}
		else
		{
			deadsprite.setTexture(deadScreenTexture);
			deadsprite.setPosition(float((wnd->getSize().x / 2) - 188), float((wnd->getSize().y / 2) - 41));
			wnd->draw(deadsprite);
			ScoreBoard.WriteMessage(*wnd, *Kid1, Size);
		}
	}
	else
	{
		wnd->draw(buttonsprite);
	}
}
