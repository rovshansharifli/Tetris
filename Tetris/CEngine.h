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
	bool* play_ground_matrix;

	//this will check the rotation
	bool upPressed = false;
	
	//if pressed left value is -1 if pressed right value will be 1; default 0;
	int leftRightTurn = 0;

};

