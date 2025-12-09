#pragma once

#include "Defines.h"
#include "Enums.h"
#include "Types.h"

#include <windows.h>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

#include <format>

#define _CRTDEBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
//__FILE__ : 실행되고 있는 파일 이름
//__LINE__ : 몇번째 줄인지
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif