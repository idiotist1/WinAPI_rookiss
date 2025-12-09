#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// 프로그램 시작부터 함수를 호출한 시점까지의 시간을 ms로 반환(정밀도가 떨어짐)
	//::GetTickCount64(); 

	// 시스템 부팅 시 고정되는 고성능 타이머의 주파수를 반환
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	// 고성능 타이머(<1us)의 현재 카운터 값을 반환
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Update()
{
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;

	_frameCount++;
	_frameTime += _deltaTime;

	// 프레임 타임이 1초를 경과했다면
	if (_frameTime >= 1.f)
	{
		//몇번 갱신을 햇는지(보통은 60프레임 유지가 되어야한다)
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}
}
