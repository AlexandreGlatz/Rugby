
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "GameScene.h"

#include <cstdlib>
#include <crtdbg.h>

#include "RugbyScene.h"

int main() 
{
    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "yippee.mp4", 60, sf::Color::Blue);
	
	pInstance->LaunchScene<RugbyScene>();

	return 0;
}
