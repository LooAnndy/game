#ifndef ENEMY_H_
#define ENEMY_H_

#include "game.h"
class Animation;
class Player;

class Enemy
{
public:
	Enemy();
	~Enemy();

	bool CheckPlayerCollsion(const Player &player);
	//bool CheckBulletCollsion(const Bullet &bullet);
	void Move(const Player &player);
	void Draw(int delta);

private:
	static const int FRAME_WIDTH = 200;
	static const int FRAME_HEIGHT = 200;
	static const size_t FRAME_NUM = 3;

private:
	int speed;
	bool is_moving_left;
	POINT position;

private:
	Animation* anim_moving_left;
	Animation* anim_moving_right;
};

#endif // !ENEMY_H_

