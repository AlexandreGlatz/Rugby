#pragma once
#include "Entity.h"
#include "Player.h"

class Ball : public Entity
{
    enum state
    {
        holded,
        passed
    };
    
public:
    Ball(float radius, const sf::Color& color);
    float mPassCadence = 1.0f;

protected:
    void OnUpdate() override;
    void Pass(Player* a);
};
