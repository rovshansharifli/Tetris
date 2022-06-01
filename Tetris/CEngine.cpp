#include "CEngine.h"
#include "CPlayGround.h"
#include "CPiece.h"
#include "Sizes.h"
#include "Cell.h"
#include <time.h>

#include <iostream>

CEngine::CEngine()
{

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

	sf::Clock clock;

	CPlayGround playGround;

	//the first piece of the game
	playGround.spawnPieceOnPG();

	// every point of a piece in 2d play ground
	Cell * CellPG;

	while (window.isOpen()) {

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		
		checkEvent(window);

		if (leftRightTurn != 0) {
			playGround.movePiece(leftRightTurn);
			leftRightTurn = 0;
		}
		
		if (upPressed) {
			playGround.rotatePiece();
			upPressed = false;
		}

		if (downPressed) {
			delay = default_delay/10;
			downPressed = false;
		}

		if (timer > delay) {
			playGround.slidePiece();

			if (playGround.checkCollision()) {
				playGround.leavePieceOnPG();

				// check game over
				if (playGround.playGroundIsFull()) {
					gameOver = true;

					std::cout << "Game Over!" << std::endl;

					break;
				}
				else {
					playGround.spawnPieceOnPG();

				}
			}

			timer = 0;
		}

		CellPG = playGround.getPiecePoints();

		playGround.removeFullLines(score, default_delay);

		delay = default_delay;

		window.clear(sf::Color::White);

		playGround.putFrames(window, my_sprite);

		for (int i = 0; i < 4; i++) {
			my_sprite.setPosition(CellPG[i].x * 18, CellPG[i].y * 18);

			window.draw(my_sprite);
		}

		window.display();
	}

	std::cout << "Score: " << score << std::endl;
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
			else if (my_event.key.code == sf::Keyboard::Down) {
				downPressed = true;
			}
		}
	}
}
