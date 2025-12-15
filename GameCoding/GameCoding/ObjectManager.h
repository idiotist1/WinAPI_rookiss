#pragma once

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void Add(class Object* object);
	void Remove(class Object* object);
	void Clear();

	const vector<class Object*>& GetObjects() { return _objects; }

	template<typename T>
	T* CreateObject()
	{
		// is_convertible_v : 템플릿 매개변수간에 포인터 변환이 가능한지 체크
		// static_assert : 컴파일 타임에 조건을 검사해서 컴파일 에러 발생
		static_assert(std::is_convertible_v<T*, class Object*>);

		T* object = new T();
		object->Init();
		return object;
	}

private:
	vector<class Object*> _objects;
};

