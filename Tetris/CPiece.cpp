#include "CPiece.h"
#include <cstdlib>
#include <time.h>

CPiece::CPiece()
{
    // type of pieces
    int pieces[7][4] =
    {
        1, 3, 5, 7, 
        2, 4, 5, 7, 
        3, 5, 4, 6, 
        3, 5, 4, 7, 
        2, 3, 5, 7, 
        3, 5, 7, 6, 
        2, 3, 4, 5, 
    };

    // making pieces spawn randomly
    srand(time(0));
    int piece_type = rand() % 7;

    // puting pieces into an array
    for (int i = 0; i < 4; i++) {
        m_piece_points[i] = pieces[piece_type][i];
    }
}

CPiece::~CPiece()
{

}

int CPiece::getPiecePoint(int point_number)
{
    return m_piece_points[point_number];
}

