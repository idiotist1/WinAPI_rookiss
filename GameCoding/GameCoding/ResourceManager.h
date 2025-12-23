#pragma once

class ResourceManager
{
public:
	DECLARE_SINGLE(ResourceManager);

	~ResourceManager();
public:
	void Init();
	void Clear();

	const class LineMesh* GetLineMesh(wstring key);
private:
	unordered_map<wstring, class LineMesh*> _lineMeshes;
};

