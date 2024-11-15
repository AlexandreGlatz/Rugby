#pragma once
#include "Condition.h"
#include "Player.h"
class PlayerCondition_GetBall : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_TeamGetBall : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_TakeBall : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_Surrounded : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};