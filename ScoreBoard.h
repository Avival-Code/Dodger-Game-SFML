#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "FrameTimer.h"
#include "Kid.h"

class ScoreBoard
{
public:
	ScoreBoard()
	{
		Font.loadFromFile( "Amatic.ttf" );
	}
	std::string ConvertScore();
	void CalculateScore( FrameTimer& Timer, Kid& any);
	sf::Text SetText( Kid& any, unsigned int& size_characters );
	void WriteMessage( sf::RenderWindow& wnd, Kid& any, unsigned int& size_characters);

private:
	std::string scorestring;
	sf::Font Font;
	int score = 0;

};