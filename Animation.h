#pragma once

#include <vector>
#include <math.h>
#include <iostream>

template <typename T>
class Animation 
{
public:
	Animation(std::vector<T> objects, float time) 
		:objects(objects)
		,time(time)
	{
		totalTime = 0.0f;
	}
	~Animation(){}

	T get(float delta) {
		totalTime += delta;
		int i = totalTime / time;
		int len = objects.size();
		i %= len;
		i = i < len ? i : len - 1;
		return objects[i];
	}

private:
	std::vector<T> objects;
	float time, totalTime;
};

