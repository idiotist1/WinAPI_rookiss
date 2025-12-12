#pragma once

enum class ObjectType
{
	None,
	Player,
	Monster,
	Projectile,
	Env,
};

class Object
{
public:
	Object();
	virtual ~Object();

protected:
	ObjectType _type = ObjectType::None;

	Pos _pos = {};
};

