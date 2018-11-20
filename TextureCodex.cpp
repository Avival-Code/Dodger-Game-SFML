#include "TextureCodex.h"
#include <cassert>

TextureCodex::TextureCodex()
{
	SetTextures();
}

void TextureCodex::SetTextures()
{
	for(int i = 0; i < 5; i++)
	{
		Textures[i].loadFromFile( FileNames[i]);
	}
}

sf::Texture & TextureCodex::GetTexture(int TextureType)
{
	assert(TextureType >= 0 && TextureType < 5);

	return Textures[TextureType];
}
