#include "Game.h"

int main()
{
	sf::RenderWindow* MainWindow;
	MainWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Test SFML Window");
	MainWindow->setFramerateLimit(60);
	TextureCodex Codex;

	Game Game( *MainWindow, Codex );
	

	while (MainWindow->isOpen())
	{
		sf::Event event;
		while (MainWindow->pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				MainWindow->close();
		}


		MainWindow->clear();

		Game.ExecuteGameLogic();

		MainWindow->display();
	}

	delete MainWindow;
	return EXIT_SUCCESS;
}