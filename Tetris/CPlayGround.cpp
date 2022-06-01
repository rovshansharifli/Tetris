#include "CPlayGround.h"
#include <iostream>

CPlayGround::CPlayGround()
{
}

CPlayGround::~CPlayGround()
{
}

int* CPlayGround::getPlayGround()
{
	return *m_play_ground;
}

void CPlayGround::spawnPieceOnPG()
{
	CPiece piece;

	for (int i = 0; i < 4; i++) {
		m_points[i].x = piece.getPiecePoint(i) % 2;
		m_points[i].y = piece.getPiecePoint(i) / 2;
	}
}

Cell* CPlayGround::getPiecePoints()
{
	return m_points;
}

void CPlayGround::movePiece(int direction)
{

	for (int i = 0; i < 4; i++) {
		m_previous_points[i] = m_points[i];
		m_points[i].x += direction;
	}

	if (checkCollision()) {
		for (int i = 0; i < 4; i++) {
			m_points[i] = m_previous_points[i];
		}
	}
}

void CPlayGround::rotatePiece()
{
	for (int i = 0; i < 4; i++) {
		m_previous_points[i] = m_points[i];

		int x_part = m_points[i].y - m_points[1].y;
		int y_part = m_points[i].x - m_points[1].x;

		m_points[i].x = m_points[1].x - x_part;
		m_points[i].y = m_points[1].y + y_part;
	}

	if (checkCollision()) {
		for (int i = 0; i < 4; i++) {
			m_points[i] = m_previous_points[i];
		}
	}
}

void CPlayGround::slidePiece()
{
	for (int i = 0; i < 4; i++) {
		m_previous_points[i] = m_points[i];
		m_points[i].y += 1;
	}
}

bool CPlayGround::checkCollision()
{
	for (int i = 0; i < 4; i++) {
		//collision with the frame
		if (m_points[i].x < 0 || 
			m_points[i].x >= pg_sizes::PG_WIDTH || 
			m_points[i].y >= pg_sizes::PG_HEIGHT) 
		{
			std::cout << "true" << std::endl;
			return true;
		}
		//collision with the cells
		else if (m_play_ground[m_points[i].x][m_points[i].y]) 
		{
			return true;
		}
	}
	
	return false;
}

void CPlayGround::putFrames(sf::RenderWindow &t_window, sf::Sprite &t_sprite)
{
	for (int i = 0; i < pg_sizes::PG_WIDTH; i++) {
		for (int j = 0; j < pg_sizes::PG_HEIGHT; j++) {
			if (m_play_ground[i][j] != 0) {
				t_sprite.setPosition(i * 18, j * 18);
				t_window.draw(t_sprite);
			}
		}
	}
}

void CPlayGround::leavePieceOnPG()
{
	for (int i = 0; i < 4; i++) {
		m_play_ground[m_previous_points[i].y][m_previous_points[i].x] = 1;
	}
}
