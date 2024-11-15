#include "RugbyScene.h"
#include "Player.h"
#include "Debug.h"

void RugbyScene::OnInitialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();
	//GameManager::clear(sf::Color::Green);

	float playerRadius = 50.f;
	float playerHeight = playerRadius * 2;
	float spaceBetweenPlayers = 20;

	float totalHeight = (spaceBetweenPlayers * 2) + (playerHeight * 3);
	float spacing = height - totalHeight;

	float startX = playerRadius * 2;
	float startY = playerRadius + (spacing / 2);

	Player* m_team1[3];

	for (int i = 0; i < 3; i++)
	{
		m_team1[i] = CreateEntity<Player>(playerRadius, sf::Color::Green);
		m_team1[i]->SetPosition(startX, startY, 0.5f, 0.5f);

		float xMin = startX + playerHeight;
		float yMin = startY - playerRadius;
		float xMax = width;
		float yMax = startY + playerRadius;

		mAreas[i] = { xMin, yMin, xMax, yMax };

		startY += playerHeight + spaceBetweenPlayers;
	}

	for (int i = 0; i < 2; i++)
	{
		mTouchDownAreas[i] = { 10.0f + (i*1150), 10, (125.0f +(i * 1150)), ((spacing / 2) * 3.75f)};
	}
}

void RugbyScene::OnUpdate()
{
	for (int i = 0; i < 3; i++)
	{
		const AABB1& aabb = mAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Red);
	}
	for (int i = 0; i < 2; i++)
	{
		const AABB1& aabb = mTouchDownAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Red);
	}
}

int RugbyScene::GetClickedArea(int x, int y) const
{
	for (int i = 0; i < 3; i++)
	{
		const AABB1* aabb = &mAreas[i];

		if (x >= aabb->xMin && x <= aabb->xMax && y >= aabb->yMin && y <= aabb->yMax)
			return i;
	}

	return -1;
}

void RugbyScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

	if (index == -1)
		return;

	const AABB1* clickedArea = &mAreas[index];

	int y = clickedArea->yMin + (clickedArea->yMax - clickedArea->yMin) / 2;

	Player* m_team2 = CreateEntity<Player>(25, sf::Color::Red);
	m_team2->SetPosition(event.mouseButton.x, y, 0.5f, 0.5f);
	m_team2->SetLane(index);

	mLanePlayerCount[index]++;
}