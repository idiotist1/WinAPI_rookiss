#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ObjectManager.h"

Missile::Missile() : Object(ObjectType::Projectile)
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
	// TODO : Data
	_stat.hp = 1;
	_stat.maxHp = 1;
	_stat.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	//
	if (_target == nullptr)
	{
		_pos.x += _stat.speed * deltaTime * cos(_angle);
		_pos.y -= _stat.speed * deltaTime * sin(_angle);

		_sumTime += deltaTime;
		if (_sumTime >= 0.2f)
		{
			// 모든 오브젝트
			const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
			for (Object* object : objects)
			{
				if (object->GetObjectType() == ObjectType::Monster)
				{
					_target = object;
					break;
				}
			}
		}
	}
	else
	{
		// 목표로의 방향
		Vector dir = _target->GetPos() - GetPos();
		dir.Normalize();

		Vector moveDir = dir * _stat.speed * deltaTime;
		_pos += moveDir;
	}

	// 충돌
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		if (object == this)
			continue;

		if (object->GetObjectType() != ObjectType::Monster)
			continue;

		Pos p1 = GetPos();
		Pos p2 = object->GetPos();

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 25)
		{
			GET_SINGLE(ObjectManager)->Remove(object); // 괜찮을..까?
			GET_SINGLE(ObjectManager)->Remove(this); // 괜찮을..까?
			return;
		}
	}

	// TODO
	if (_pos.y < -100)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
		return;
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
