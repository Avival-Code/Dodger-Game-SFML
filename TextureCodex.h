#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextureCodex
{
public:
	TextureCodex();

public:
	sf::Texture& GetTexture(int TextureType);

private:
	void SetTextures();

private:
	std::string FileNames[5] = { "Kid.png", "EyeBall.png", "Batty.png", "SimpleBone.png", "SmallSimpleHeart.png" };
	sf::Texture Textures[5];
};