#include "CEngine.h"
#include "CPlayGround.h"
#include "CPiece.h"
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

void CEngine::start()
{
	sf::RenderWindow window(sf::VideoMode(w_sizes::W_WIDTH, w_sizes::W_HEIGHT), "Tetris");

	sf::Texture my_texture;
	my_texture.loadFromFile("images/tiles.png");

	sf::Sprite my_sprite(my_texture);
	my_sprite.setTextureRect(sf::IntRect(0, 0, 18, 18));

	CPiece piece;

	while (window.isOpen()) {
		sf::Event my_event;
		while (window.pollEvent(my_event)) 
		{
			if (my_event.type == sf::Event::Closed) 
			{
				window.close();
			}

			// put the keys on here to control the pieces

		}

		window.clear(sf::Color::White);
		
		for (int i = 0; i < 4; i++) {
			my_sprite.setPosition((piece.getPiecePoints(i) % 2) * 18, (piece.getPiecePoints(i) / 2) * 18);
			
			window.draw(my_sprite);
		}

		window.display();
	}
}
