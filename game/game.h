//author：LooAnndy
//功能：
//	存放全局的标准库，宏定义，全局变量，以及一些必要的数学物理模型
#ifndef _GAME_H_
#define _GAME_H_


#include <math.h>
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <vector>

#define FRAME_PER_SECOND 45

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 640

//虚拟键盘的扩展
#define VK_KEY_W 0x57
#define VK_KEY_A 0x41 
#define VK_KEY_S 0x53 
#define VK_KEY_D 0x44

struct Vector2D
{
	double x, y;
	Vector2D()
	{
		this->x = 0.0;
		this->y = 0.0;
	}

	Vector2D(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2D normalize()
	{
		if (fabs(this->x) < 1e-6 && fabs(this->y) < 1e-6)
			return *this;
		double len = sqrt(x * x + y * y);
		this->x = this->x / len;
		this->y = this->y / len;
		return *this;
	}

	bool operator==(const Vector2D& b)const
	{
		return this->x == b.x && this->y == b.y;
	}

	Vector2D operator+(const Vector2D& b)const
	{
		return Vector2D(x + b.x, y + b.y);
	}

	Vector2D operator-(const Vector2D& b)const
	{
		return Vector2D(x - b.x, y - b.y);
	}

	Vector2D operator*(double mul)const
	{
		return Vector2D(x * mul, y * mul);
	}

	Vector2D operator/(double div)const
	{
		return Vector2D(x / div, y / div);
	}

	Vector2D operator+= (const Vector2D& b)
	{
		this->x = this->x + b.x;
		this->y = this->y + b.y;
		return *this;
	}

	Vector2D operator-= (const Vector2D& b)
	{
		this->x = this->x - b.x;
		this->y = this->y = b.y;
		return *this;
	}

	Vector2D operator*= (double mul)
	{
		this->x = this->x * mul;
		this->y = this->y * mul;
		return *this;
	}

	Vector2D operator/= (double div)
	{
		this->x = this->x / div;
		this->y = this->y / div;
		return *this;
	}
};

#define SPEED 20

#endif