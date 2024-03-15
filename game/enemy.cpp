#include "enemy.h"
#include "animation.h"
#include "player.h"

Enemy::Enemy()
{
	speed = 10;
	anim_moving_left = new Animation(_T(".\\img\\enemy_moving_left%d.png"), FRAME_NUM, FRAME_PER_SECOND);
	anim_moving_right = new Animation(_T(".\\img\\enemy_moving_right%d.png"), FRAME_NUM, FRAME_PER_SECOND);
	is_moving_left = 0;

	int edge = (rand() % 4);
	switch(edge)
	{
	case 0:
		position.x = rand() % WINDOW_WIDTH;
		position.y = -FRAME_HEIGHT;
		break;
	case 1:
		position.x = rand() % WINDOW_WIDTH;
		position.y = WINDOW_HEIGHT;
		break;
	case 2:
		position.x = -FRAME_WIDTH;
		position.y = rand() % WINDOW_HEIGHT;
		break;
	case 3:
		position.x =  WINDOW_WIDTH;
		position.y = rand() % WINDOW_HEIGHT;
		break;
	default:
		break;
	}
}

Enemy::~Enemy()
{
	delete anim_moving_left;
	delete anim_moving_right;
}

bool Enemy::CheckPlayerCollsion(const Player& player)
{
	return false;
}

void Enemy::Move(const Player& player)
{
	Vector2D dir = Vector2D(player.position.x - position.x, player.position.y - position.y);
	dir.normalize();
	dir *= speed;
	position.x += (LONG)dir.x;
	position.y += (LONG)dir.y;

	if (dir.x > 0.0)
		is_moving_left = 0;
	else
		is_moving_left = 1;
}

void Enemy::Draw(int delta)
{
	if (is_moving_left)
		anim_moving_left->Play(position.x, position.y, delta);
	else
		anim_moving_right->Play(position.x, position.y, delta);
}