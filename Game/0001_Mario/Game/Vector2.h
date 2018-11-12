#pragma once

class Vector2
{
public:
	Vector2() = default;
	Vector2(int X, int Y) : x(X), y(Y) {};
	
	int x = 0;
	int y = 0;
};