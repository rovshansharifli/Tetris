#pragma once

class CPiece
{
public:
	CPiece();
	~CPiece();
	
	int getPiecePoint(int point_number);
	
private:
	int piece_points[4];
};
