#include "pch.h"
#include "GameScene.h"
#include "ObjectManager.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
	monster->SetPos(Pos{ 400, 400 });
	GET_SINGLE(ObjectManager)->Add(monster);

}

void GameScene::Update()
{
	// 복사 비용을 아끼기 위해 참조를 했다.
	// 순회를 함과 동시에 objects의 갯수가 늘어나면 오류가 발생하므로 여기서는 참조하면 안됨
	//const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();

	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Render(hdc);
	}
}
