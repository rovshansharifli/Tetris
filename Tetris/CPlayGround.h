#pragma once
#include "Sizes.h"
#include "PointPG.h"
#include "CPiece.h"

class CPlayGround
{
public:
	CPlayGround();
	~CPlayGround();

	bool* getPlayGround();

	void putPieceOnPG(CPiece t_piece);
	PointPG* getPiecePoints();

	void movePiece(int direction);

private:
	bool m_play_ground[pg_sizes::PG_WIDTH][pg_sizes::PG_HEIGHT] = { false };
	PointPG m_points[4];
};

