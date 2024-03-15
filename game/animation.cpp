#pragma once
#include "Animation.h"

//
//实例化Amimation类的时候需要三个参数：
// path 播放源的基本路径a
// num 播放图片的数量
// interval图片播放之间的时间间隔
//

Animation::Animation(LPCTSTR path, size_t num, int interval)
{
	idx_frame = 0;
	timer = 0;
	interval_ms = interval;
	TCHAR target_file[50];
	for (size_t i = 0; i < num; i++)
	{
		_stprintf(target_file, path, i);

		IMAGE* frame = new IMAGE();
		loadimage(frame, target_file);
		frame_list.push_back(frame);
	}
}

Animation::~Animation()
{
	for (size_t i = 0; i < frame_list.size(); i++)
		delete frame_list[i];
}

//处理定时器后，在（x , y)位置上绘制当前帧
void Animation::Play(int x, int y, int delta)
{
	timer += delta;
	if (timer >= interval_ms)
	{
		idx_frame = (idx_frame + 1) % frame_list.size();
		timer = timer % interval_ms;
	}

	putimage_alpha(NULL, x, y, frame_list[idx_frame]);
}

/*
1>参数BlendOp，混合操作，这个目前有且仅有一种方式AC_SRC_OVER，它表示源位图通过基于alpha信息放到目标位图上

	2>参数BlendFlags，混合标记，只能是0

	3>参数SourceConstantAlpha，大致上表示位图的透明度(0~255)。如果为0，就是完全透明；如果是255，就不透明

	4>参数AlphaFormat，如果设定为AC_SRC_ALPHA，那么你的位图必须是32位的；如果你的位图不是32位的(一般24位居多，RGB)，就不要用它，直接赋0就行了
原文链接：https://blog.csdn.net/crocodile__/article/details/10156817
*/

/*在窗体上实现半透明贴图函数
* 需要图片预处理好背景的透明度
* x , y 目标贴图位置
img:IMAGE的一个对象指针
*/

//导入msimg32.lib库，函数包含在库中
#pragma comment(lib , "MSIMG32.LIB")
void putimage_alpha(IMAGE* target, int x, int y, IMAGE* source)
{
	int w = source->getwidth();
	int h = source->getheight();
	HDC dstDC = GetImageHDC(target);
	HDC srcDC = GetImageHDC(source);

	// 结构体的第三个成员表示额外的透明度，0 表示全透明，255 表示不透明。
	BLENDFUNCTION bf = { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}