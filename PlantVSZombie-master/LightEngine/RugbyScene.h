#pragma once
#include "Ball.h"
#include "Player.h"
#include "Scene.h"
#include "array"
#include <list>

namespace sf
{
    class Event;
}

struct AABB1
{
    int xMin;
    int yMin;
    int xMax;
    int yMax;
};


class RugbyScene : public Scene
{
public:
    enum TAG
    {
        TEAM_BLUE,
        TEAM_RED,
        BALL,
        PLAYER
    };
    
    std::array<Player*, 5> m_team1; 
    std::array<Player*, 5> m_team2;
    Ball* m_ball;

    int mLaneZombieCount[3] = { 0, 0, 0 };
    AABB1 mAreas[3];

private:
    int GetClickedArea(int x, int y) const;

public:
    void OnInitialize() override;
    void OnEvent(const sf::Event& event) override;
    void OnUpdate() override;
};

