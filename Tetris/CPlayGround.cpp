#include "CPlayGround.h"


CPlayGround::CPlayGround()
{
}

CPlayGround::~CPlayGround()
{
}

bool* CPlayGround::getPlayGround()
{
	return *m_play_ground;
}

void CPlayGround::putPieceOnPG(CPiece t_piece)
{
	for (int i = 0; i < 4; i++) {
		m_points[i].x = t_piece.getPiecePoint(i) % 2;
		m_points[i].y = t_piece.getPiecePoint(i) / 2;
	}
}

PointPG* CPlayGround::getPiecePoints()
{
	return m_points;
}

void CPlayGround::movePiece(int direction)
{
	for (int i = 0; i < 4; i++) {
		m_points[i].x += direction;
	}
}
