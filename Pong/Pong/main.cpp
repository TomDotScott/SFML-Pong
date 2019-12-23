#include "game_state.h"
#include "main_menu.h"
#include <thread>

game_state core_state;
bool quitGame = false;

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

	core_state.SetWindow(&window);
	core_state.SetState(new main_menu());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color::Black);

		core_state.Update();
		core_state.Render();

		window.display();

		if (quitGame) {
			window.close();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	return 0;
}