#pragma once
#include "Entity.h"
#include "Ball.h"
#include "StateMachine.h"
class Player : public Entity
{
public:
	Player(sf::Color color, float radius = 50);
	~Player();
	
	void OnUpdate() override;
	Player* pPlayerWithBall;

	StateMachine<Player> m_stateMachine;

	enum State
	{
		Idle,
		HasBall,
		TeamHasBall,
		Passing,

		Count
	};
	
private:

};

