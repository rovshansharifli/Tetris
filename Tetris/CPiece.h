#pragma once

class CPiece
{
public:
	CPiece();
	~CPiece();
	
	int getPiecePoint(int point_number);
	
	// main point is the second cell (index 1) of a piece - for rotation
	int getPieceMainPoint();

private:
	int piece_points[4];
};
