#include "PlayerAction.h"
#include "RugbyScene.h"

void PlayerAction_HasBall::Start(Player* pPlayer)
{
	pPlayer->SetSpeed(2.0);
}

void PlayerAction_HasBall::Update(Player* pPlayer)
{
	
}

void PlayerAction_Idle::Start(Player* pPlayer)
{
	pPlayer->SetSpeed(1.0);
}

void PlayerAction_Idle::Update(Player* pPlayer)
{
	pPlayer->GoToDirection(pPlayer->pPlayerWithBall->GetPosition().x, pPlayer->pPlayerWithBall->GetPosition().y);
}

void PlayerAction_TeamHasBall::Start(Player* pPlayer)
{
	pPlayer->SetSpeed(1.0);
}

void PlayerAction_TeamHasBall::Update(Player* pPlayer)
{
	if (pPlayer->pPlayerWithBall->GetPosition().x > pPlayer->GetPosition().x)
		pPlayer->SetSpeed(-1.0);

	else
		pPlayer->SetSpeed(1.0);
}

void PlayerAction_Passing::Start(Player* pPlayer)
{
	//static_cast<RugbyScene*>(pPlayer->GetScene())->m_pBall->m_stateMachine->SetState(Ball::State::Passing)
	pPlayer->m_stateMachine.SetState(Player::State::Idle);
}
