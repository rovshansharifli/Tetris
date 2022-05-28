#include "CEngine.h"
#include "CPlayGround.h"
#include "Sizes.h"
#include <SFML/Graphics.hpp>

CEngine::CEngine()
{

	CPlayGround myPlayground;

	play_ground_matrix = myPlayground.getPlayGround();
}

CEngine::~CEngine()
{

}

void CEngine::drawPlayGround()
{
	sf::RenderWindow window(sf::VideoMode(w_sizes::W_WIDTH, w_sizes::W_HEIGHT), "Tetris");

	sf::Texture my_texture;
	my_texture.loadFromFile("images/tiles.png");

	sf::Sprite my_sprite;

	while (window.isOpen()) {
		sf::Event my_event;
		while (window.pollEvent(my_event)) {
			if (my_event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.draw(my_sprite);
		window.display();
	}
}
