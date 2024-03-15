//
// author:LooAnndy
// 控制玩家的类
//

#ifndef PLAYER_H_
#define PLAYER_H_
#include "game.h"
class Animation;

class Player
{
public:
	Player(int speed);
	~Player();

	void ProcessEvent(const ExMessage& msg);
	void Move();
	void Draw(int delta);

public:
	POINT position;

private:
	static const int FRAME_WIDTH = 200;
	static const int FRAME_HEIGHT = 200;
	static const size_t FRAME_NUM = 3;

private:
	int speed;
	bool is_moving_left;
	bool is_moving_right;
	bool is_moving_up;
	bool is_moving_down;

private:
	Animation* anim_moving_left;
	Animation* anim_moving_right;
	Animation* anim_standing;
};

#endif // !PLAYER_H_
