#pragma once
#include "Ball.h"
#include "Player.h"
#include "Scene.h"
#include "array"

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
    RugbyScene();
    
    std::array<Player*, 5> m_team1; 
    std::array<Player*, 5> m_team2;
    Ball* m_ball;

    
};

