#include "Player.h"
#include "RugbyScene.h"
#include "PlayerAction.h"
#include "PlayerCondition.h"
#include "Debug.h"

Player::Player(sf::Color color, float radius) : Entity(radius, color), m_stateMachine(this, Count),
	m_pBall(nullptr)
{
	SetTag(RugbyScene::TAG::PLAYER);
	

	//IDLE
	{
		Behaviour<Player>* pIdle = m_stateMachine.CreateBehaviour(State::Idle);
		pIdle->AddAction(new PlayerAction_Idle());

		//-> PASSING
		{
			auto transition = pIdle->CreateTransition(State::Passing);

			auto condition = transition->AddCondition<PlayerCondition_Surrounded>();
		}

		//-> HASBALL
		{
			auto transition = pIdle->CreateTransition(State::HasBall);

			auto condition1 = transition->AddCondition<PlayerCondition_GetBall>();
			condition1->expected = false;
		}

		//-> TEAMHASBALL
		{
			auto transition = pIdle->CreateTransition(State::TeamHasBall);

			auto condition1 = transition->AddCondition<PlayerCondition_TeamGetBall>();
			condition1->expected = false;
		}
	}

	//PASSING
	{
		Behaviour<Player>* pPassing = m_stateMachine.CreateBehaviour(State::Passing);
		pPassing->AddAction(new PlayerAction_Passing());

		//-> IDLE
		{
			auto transition = pPassing->CreateTransition(State::Idle);

			auto condition = transition->AddCondition<PlayerCondition_GetBall>();
			condition->expected = false;
		}
	}

	//TEAMHASBALL
	{
		Behaviour<Player>* pShooting = m_stateMachine.CreateBehaviour(State::TeamHasBall);
		pShooting->AddAction(new PlayerAction_TeamHasBall());

		//-> IDLE
		{
			auto transition = pShooting->CreateTransition(State::Idle);

			auto condition = transition->AddCondition<PlayerCondition_TeamGetBall>();
		}
	}

	//HASBALL
	{
		Behaviour<Player>* pShooting = m_stateMachine.CreateBehaviour(State::TeamHasBall);
		pShooting->AddAction(new PlayerAction_TeamHasBall());

		//-> IDLE
		{
			auto transition = pShooting->CreateTransition(State::Idle);

			auto condition = transition->AddCondition<PlayerCondition_TeamGetBall>();
		}

	}

	m_stateMachine.SetState(State::Idle);
}

Player::~Player()
{
}

void Player::OnUpdate()
{
	//const sf::Vector2f& position = GetPosition();
	m_stateMachine.Update();
}


