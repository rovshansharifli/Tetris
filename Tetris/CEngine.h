#pragma once
#include <SFML/Graphics.hpp>

class CEngine
{
public:
	CEngine();
	~CEngine();

	void start();

private:
	//private functions
	void checkEvent(sf::RenderWindow &t_window);

	/*variables*/
	int* play_ground_matrix;

	//this will check the rotation
	bool upPressed = false;

	//pressing down - make the pieces faster to slide down
	bool downPressed = false;
	
	//if pressed left value is -1 if pressed right value will be 1; default 0;
	int leftRightTurn = 0;

	//variables to slide the pieces
	float timer = 0;
	// speed
	float delay = 0.6;

	//game over - cannot spawn a new piece
	bool gameOver = false;

};

