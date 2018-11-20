#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TextureList.h"
#include "TextureCodex.h"
#include "Vec.h"
#include "Bats.h"

class EyeBall : public TextureList
{
public:
	EyeBall() = default;
	EyeBall(sf::RenderWindow& wnd, TextureCodex& texture, Vef2& startpos_in);

public:
	void Draw();
	void Update(float new_vel, float new_xpos, Bat& any);
	void ResetPositionAndVelocity(float vel_in, float xpos_in);
	bool Hurts();
	int GetRespawnCount();
	sf::Sprite& GetSprite();

private:
	sf::RenderWindow* wndptr = nullptr;
	sf::Sprite sprite;
	Vef2 pos_offset = { 0.0f, 0.0f };
	static constexpr int Width = 30;
	static constexpr int Height = 30;
	float velocity_y = 2.0f;
	int respawn_count = 0;
	bool HurtsKids = false;
};