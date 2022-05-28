#pragma once
#include "Sizes.h"

class CPlayGround
{
public:
	CPlayGround();
	~CPlayGround();

	bool* getPlayGround();

private:
	bool m_play_ground[pg_sizes::PG_WIDTH][pg_sizes::PG_HEIGHT] = { false };

};

