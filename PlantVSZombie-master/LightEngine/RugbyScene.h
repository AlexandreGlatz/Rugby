#pragma once
#include "Scene.h"
#include "Ball.h"
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

    Ball* m_pBall;
    void OnInitialize() override {}
    void OnUpdate() override {}
    void OnEvent(const sf::Event& event) override {}
};

