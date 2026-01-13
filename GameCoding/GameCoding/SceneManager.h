#pragma once

class SceneManager
{
	DECLARE_SINGLE(SceneManager);
public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void Clear();
public:
	void ChangeScene(SceneType sceneType);

	class Scene* GetCurrrentScene() { return _scene; }
private:
	class Scene* _scene;
	SceneType _sceneType = SceneType::None;
};

