#pragma once

#include "Foundation.h"


template <typename T>
class GOOD_DLL Singleton
{
public:
	template <typename... Arguments>
	static T* getInstancePtr(Arguments... args)
	{
		if (_instance == nullptr)
			_instance = new T(args...);

		return _instance;
	}

protected:
	Singleton(){}
	Singleton(const Singleton&){}
	Singleton& operator=(const Singleton&){ return *this; }

	static T* _instance;
};

template <typename T>
T* Singleton<T>::_instance = nullptr;