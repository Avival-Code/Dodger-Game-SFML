#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "TextureList.h"
#include "TextureCodex.h"
#include "Vec.h"
#include "EyeBall.h"

class Bone : public TextureList
{
public:
	Bone() = default;
	Bone(sf::RenderWindow& wnd, TextureCodex& texture, Vef2& startpos_in);
	Bone(sf::RenderWindow& wnd, TextureCodex& texture, Vef2& startpos_in, bool Reversed_in);

public:
	void Draw();
	void Update(float new_vel, float new_ypos, EyeBall& any);
	void ResetPositionAndVelocity(float vel_in, float ypos_in);
	bool Hurts();
	int GetWidth();
	sf::Sprite& GetSprite();

private:
	sf::RenderWindow* wndptr = nullptr;
	sf::Sprite sprite;
	Vef2 pos_offset = { 0.0f, 0.0f };
	static constexpr int Width = 13;
	static constexpr int Height = 22;
	float velocity_x = 2.0f;
	bool HurtsKids = false;
	bool Reversed = false;
};