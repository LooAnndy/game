//
// auther:LooAnndy
// function:
// 用于播放的类Animation，处理图片透明度的函数putimage_alpha
//

#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "game.h"

//
//实例化Amimation类的时候需要三个参数：
// path 播放源的基本路径a
// num 播放图片的数量
// interval图片播放之间的时间间隔
//

class Animation
{
public:
	Animation(LPCTSTR path, size_t num, int interval);
	~Animation();

	//处理定时器后，在（x , y)位置上绘制当前帧
	void Play(int x, int y, int delta);

private:
	int timer;//	动画计时器，计时超过interval之后开启下一帧
	int idx_frame;//动画的帧索引
	int interval_ms;
	std::vector<IMAGE*> frame_list;
};

void putimage_alpha(IMAGE* target, int x, int y, IMAGE* source);

#endif // !ANIMATION_H_
