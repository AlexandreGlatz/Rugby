#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	int mLane = -1;
	void SetLane(int lane) { mLane = lane; }
	Player(float, sf::Color);
};

