#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TextureList.h"
#include "TextureCodex.h"
#include "Vec.h"
#include "Bats.h"
#include "EyeBall.h"
#include "Bones.h"
#include "FrameTimer.h"

class Kid : public TextureList
{
public:
	Kid( sf::RenderWindow& wnd, TextureCodex& texture, Vef2& startpos_in);

public:
	void Draw();
	void Update(FrameTimer& Timer);
	void TakeDamage( Bat& anyBat, EyeBall& anyEye, Bone& anyBone, FrameTimer& Timer );
	bool GetDeadStatus();
	int GetHP();
	sf::Sprite& GetSprite();

private:
	static constexpr int Width = 26;
	static constexpr int Height = 40;
	bool PlayedSound = false;
	bool JustHit = false;
	bool IsDead = false;
	int HP = 5;
	sf::RenderWindow& wnd;
	sf::Sprite sprite;
	sf::Music grunt;
	sf::Music dead;
	Vef2 pos_offset;
};