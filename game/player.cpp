#include "player.h"
#include "animation.h"

Player::Player(int speed)
{
	POINT position = { 500 , 500 };
	is_moving_down = 0;
	is_moving_up = 0;
	is_moving_left = 0;
	is_moving_right = 0;
	this->speed = speed;
	anim_moving_left = new Animation(_T(".\\img\\player_moving_left%d.png"), FRAME_NUM, FRAME_PER_SECOND);
	anim_moving_right = new Animation(_T(".\\img\\player_moving_right%d.png"), FRAME_NUM, FRAME_PER_SECOND);
	anim_standing = new Animation(_T(".\\img\\player_standing%d.png"), 1, FRAME_PER_SECOND);
}
Player::~Player()
{
	delete anim_moving_left;
	delete anim_moving_right;
}

void Player::ProcessEvent(const ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case VK_KEY_W:
			is_moving_up = 1;
			break;
		case VK_UP:
			is_moving_up = 1;
			break;
		case VK_KEY_S:
			is_moving_down = 1;
			break;
		case VK_DOWN:
			is_moving_down = 1;
			break;
		case VK_KEY_A:
			is_moving_left = 1;
		case VK_LEFT:
			is_moving_left = 1;
			break;
		case VK_KEY_D:
			is_moving_right = 1;
			break;
		case VK_RIGHT:
			is_moving_right = 1;
			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case VK_KEY_W:
			is_moving_up = 0;
			break;
		case VK_UP:
			is_moving_up = 0;
			break;
		case VK_KEY_S:
			is_moving_down = 0;
			break;
		case VK_DOWN:
			is_moving_down = 0;
			break;
		case VK_KEY_A:
			is_moving_left = 0;
		case VK_LEFT:
			is_moving_left = 0;
			break;
		case VK_KEY_D:
			is_moving_right = 0;
			break;
		case VK_RIGHT:
			is_moving_right = 0;
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void Player::Move()
{
	Vector2D dir = Vector2D(1.0 * ((double)is_moving_right - is_moving_left),
		1.0 * ((double)is_moving_down - is_moving_up));
	dir.normalize();
	dir *= 1.0 * speed;
	position.x += (LONG)dir.x;
	position.y += (LONG)dir.y;

	if (position.x < 0)position.x = 0;
	if (position.y < 0)position.y = 0;
	if (position.x + FRAME_WIDTH > WINDOW_WIDTH)position.x = WINDOW_WIDTH - FRAME_WIDTH;
	if (position.y + FRAME_WIDTH > WINDOW_HEIGHT)position.y = WINDOW_HEIGHT - FRAME_HEIGHT;
}

void Player::Draw(int delta)
{
	int facing_right = is_moving_right - is_moving_left;
	if (facing_right == 0 && is_moving_down == 0 && is_moving_up == 0)
		anim_standing->Play(position.x, position.y, delta);
	else if (facing_right > 0)
		anim_moving_right->Play(position.x, position.y, delta);
	else
		anim_moving_left->Play(position.x, position.y, delta);
}
