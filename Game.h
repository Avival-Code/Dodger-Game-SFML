/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/****************************************************
/	This class is basically a wrapper for the game
/	logic. I didn't want the Mainwindow to handle
/	everything directly.
*****************************************************/
#pragma once
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <random>
#include "TextureCodex.h"
#include "Kid.h"
#include "Bats.h"
#include "Eyeball.h"
#include "Bones.h"
#include "LifeBar.h"
#include "FrameTimer.h"
#include "ScoreBoard.h"

class Game
{
public:
	Game(sf::RenderWindow& in_wnd, TextureCodex& in_textures);
	~Game();

private:
	sf::RenderWindow* wnd;
	TextureCodex& textures;

public:
	void ExecuteGameLogic();
	void UpdateModel();
	void ComposeFrame();

private:
	sf::Texture readyButtonTexture;
	sf::Texture deadScreenTexture;
	sf::Sprite buttonsprite;
	sf::Sprite deadsprite;
	bool GameStart = false;
	////////////////////////////////////////////////
	///////// Game Variables + Objects /////////////
	////////////////////////////////////////////////
	unsigned int Size = 45;
	FrameTimer Timer;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	std::uniform_int_distribution<int> vDist;
	LifeBar Hearts;
	ScoreBoard ScoreBoard;

	Kid* Kid1;
	Bat* Bats;
	EyeBall* EyeBalls;
	Bone* BonesLeft;
	Bone* BonesRight;
};