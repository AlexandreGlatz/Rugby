#pragma once
#include "Action.h"
#include "Player.h"
class PlayerAction_Idle : public Action<Player>
{
public:
	void Start(Player* pPlayer) override;
	void Update(Player* pPlayer) override;
	void End(Player* pPlayer) override;
};

class PlayerAction_HasBall : public Action<Player>
{
public:
	void Start(Player* pPlayer) override;
	void Update(Player* pPlayer) override;
	void End(Player* pPlayer) override;
};

class PlayerAction_TeamHasBall : public Action<Player>
{
public:
	void Start(Player* pPlayer) override;
	void Update(Player* pPlayer) override;
	void End(Player* pPlayer) override;
};

class PlayerAction_Passing : public Action<Player>
{
public:
	void Start(Player* pPlayer) override;
	void Update(Player* pPlayer) override;
	void End(Player* pPlayer) override;
};