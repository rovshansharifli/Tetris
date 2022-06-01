#pragma once
#include "Sizes.h"
#include "Cell.h"
#include "CPiece.h"
#include <SFML/Graphics.hpp>

class CPlayGround
{
public:
	CPlayGround();
	~CPlayGround();

	int* getPlayGround();

	void spawnPieceOnPG();

	Cell* getPiecePoints();

	void movePiece(int direction);

	void rotatePiece();

	void slidePiece();

	bool checkCollision();

	void putFrames(sf::RenderWindow &t_window, sf::Sprite &t_sprite);

	void leavePieceOnPG();

	void removeFullLines();

	bool playGroundIsFull();

private:

	int m_play_ground[pg_sizes::PG_WIDTH][pg_sizes::PG_HEIGHT] = { 0 };
	Cell m_points[4];
	Cell m_previous_points[4];
};

