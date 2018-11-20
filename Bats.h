#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TextureList.h"
#include "TextureCodex.h"
#include "Vec.h"

class Bat : public TextureList
{
public:
	Bat() = default;
	Bat(sf::RenderWindow& wnd, TextureCodex& texture, Vef2& startpos_in);

public:
	void Draw();
	void Update( float new_vel, float new_xpos );
	void ResetPositionAndVelocity( float vel_in, float xpos_in );
	bool Hurts();
	int GetRespawnCount();
	sf::Sprite& GetSprite();

private:
	sf::RenderWindow* wndptr = nullptr;
	sf::Sprite sprite;
	Vef2 pos_offset = { 0.0f, 0.0f };
	static constexpr int Width = 41;
	static constexpr int Height = 20;
	float velocity_y = 2.0f;
	bool HurtsKids = true;
	int respawn_count = 0;
};