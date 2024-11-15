#pragma once

#include "Action.h"
#include "Ball.h"

class BallAction_Idle : public Action<Ball>
{
public:
	void Start(Ball* pBall) override;
	void Update(Ball* pBall) override;
	void End(Ball* pBall) override;
};

class BallAction_Passing : public Action<Ball>
{
	float mShootTimer = 0.0f;

public:
	void Start(Ball* pBall) override;
	void Update(Ball* pBall) override;
	void End(Ball* pBall) override;
};
