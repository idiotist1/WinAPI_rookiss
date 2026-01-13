#include "pch.h"
#include "ResourceManager.h"

ResourceManager::~ResourceManager()
{
	Clear();
}

void ResourceManager::Init(HWND hwnd, fs::path resourcePath)
{
	_hwnd = hwnd;
	_resourcePath = resourcePath;

	//fs::current_path(); // 현재 경로
	//_resourcePath.relative_path();
	//fs::absolute(_resourcePath);
}

void ResourceManager::Clear()
{

}

