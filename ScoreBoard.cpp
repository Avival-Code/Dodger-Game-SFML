#include "ScoreBoard.h"

std::string ScoreBoard::ConvertScore()
{
	std::string score( std::to_string(score));
	return score;
}

void ScoreBoard::CalculateScore( FrameTimer& Timer, Kid& any )
{
	if( !any.GetDeadStatus() )
	{
		score = int(Timer.GetTime() * 100.0f);
	}
}

sf::Text ScoreBoard::SetText( Kid& any, unsigned int& size_characters )
{
	if( !any.GetDeadStatus() )
	{
		std::string BeginningMessageText = { "Current score: " };
		scorestring = BeginningMessageText + ConvertScore();
		
		sf::Text Message( scorestring, Font, size_characters);
		return Message;
	}
	else
	{
		std::string BeginningMessageText = { "Total score: " };
		scorestring = BeginningMessageText + ConvertScore();

		sf::Text Message( scorestring, Font, size_characters);
		Message.setPosition( 300.0f, 335.0f );
		return Message;
	}
}

void ScoreBoard::WriteMessage(sf::RenderWindow & wnd, Kid& any, unsigned int& size_characters)
{
	wnd.draw( SetText(any, size_characters));
}
