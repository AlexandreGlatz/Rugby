#include "BallAction.h"
#include "Ball.h"

#include "GameManager.h"
#include "Projectile.h"
#include "GameScene.h"

void BallAction_Idle::Start(Ball* pBall)
{
	//
}

void BallAction_Idle::Update(Ball* pBall)
{
	//
}

void BallAction_Idle::End(Ball* pBall)
{
	//
}


void BallAction_Passing::Start(Ball* pBall)
{
	mShootTimer = pBall->mPassCadence;
}

void BallAction_Passing::Update(Ball* pBall)
{
	mShootTimer += GameManager::Get()->GetDeltaTime();

	if (mShootTimer < pBall->mPassCadence)
		return;

	mShootTimer -= pBall->mPassCadence;

	GameScene* pScene = pBall->GetScene<GameScene>();

	const sf::Vector2f& position = pBall->GetPosition();

	Projectile* pProjectile = pScene->CreateEntity<Projectile>(5.0f, sf::Color::Red);
	pProjectile->SetPosition(position.x, position.y);
}

void BallAction_Passing::End(Ball* pBall)
{

}
