#include "CEngine.h"
#include "CPlayGround.h"
#include "CPiece.h"
#include "Sizes.h"
#include "PointPG.h"

#include <iostream>

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

	CPlayGround playGround;

	// every point of a piece in 2d play ground
	PointPG * pointPG;
	
	CPiece piece;
	
	playGround.putPieceOnPG(piece);

	while (window.isOpen()) {
		
		checkEvent(window);

		if (leftRightTurn != 0) {
			playGround.movePiece(leftRightTurn);
			leftRightTurn = 0;
		}

		if (upPressed) {
			playGround.rotatePiece();
			upPressed = false;
		}

		pointPG = playGround.getPiecePoints();

		window.clear(sf::Color::White);

		for (int i = 0; i < 4; i++) {
			my_sprite.setPosition(pointPG[i].x * 18, pointPG[i].y * 18);

			window.draw(my_sprite);
		}

		window.display();
	}
}

void CEngine::checkEvent(sf::RenderWindow &t_window)
{
	sf::Event my_event;
	while (t_window.pollEvent(my_event))
	{
		if (my_event.type == sf::Event::Closed)
		{
			t_window.close();
		}

		if (my_event.type == sf::Event::KeyPressed) {

			if (my_event.key.code == sf::Keyboard::Up) {
				upPressed = true;
			}
			else if (my_event.key.code == sf::Keyboard::Left) {
				leftRightTurn = -1;
			}
			else if (my_event.key.code == sf::Keyboard::Right) {
				leftRightTurn = 1;
			}
			else {
				// nothing handled here: think about it - but probably not needed
			}
		}
	}
}
