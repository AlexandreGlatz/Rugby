#include "Ball.h"
#include "RugbyScene.h"

Ball::Ball(float radius, const sf::Color& color)
    : Entity(radius, color)
{
    SetTag(RugbyScene::TAG::BALL);
    SetDirection(1.0f, 0.0f, 100.0f);
}

void Ball::OnUpdate()
{
    sf::Vector2f position = GetPosition(0.f, 0.f);
}

void Ball::Pass(Player* Reciever)
{
    passed;
    GoToDirection(Reciever->x, Reciever->y , 16);
}