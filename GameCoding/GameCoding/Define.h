#pragma once

//define을 이어서 처리하고 싶다면 "\"을 붙인다.
#define DECLARE_SINGLE(classname)		\
private:								\
	classname() { }						\
public:									\
	static classname* GetInstance()		\
	{									\
		static classname s_instance;	\
		return &s_instance;				\
	}									\

#define GET_SINGLE(classname) classname::GetInstance()