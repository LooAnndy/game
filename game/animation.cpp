#pragma once
#include "Animation.h"

//
//ʵ����Amimation���ʱ����Ҫ����������
// path ����Դ�Ļ���·��a
// num ����ͼƬ������
// intervalͼƬ����֮���ʱ����
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

//����ʱ�����ڣ�x , y)λ���ϻ��Ƶ�ǰ֡
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
1>����BlendOp����ϲ��������Ŀǰ���ҽ���һ�ַ�ʽAC_SRC_OVER������ʾԴλͼͨ������alpha��Ϣ�ŵ�Ŀ��λͼ��

	2>����BlendFlags����ϱ�ǣ�ֻ����0

	3>����SourceConstantAlpha�������ϱ�ʾλͼ��͸����(0~255)�����Ϊ0��������ȫ͸���������255���Ͳ�͸��

	4>����AlphaFormat������趨ΪAC_SRC_ALPHA����ô���λͼ������32λ�ģ�������λͼ����32λ��(һ��24λ�Ӷ࣬RGB)���Ͳ�Ҫ������ֱ�Ӹ�0������
ԭ�����ӣ�https://blog.csdn.net/crocodile__/article/details/10156817
*/

/*�ڴ�����ʵ�ְ�͸����ͼ����
* ��ҪͼƬԤ����ñ�����͸����
* x , y Ŀ����ͼλ��
img:IMAGE��һ������ָ��
*/

//����msimg32.lib�⣬���������ڿ���
#pragma comment(lib , "MSIMG32.LIB")
void putimage_alpha(IMAGE* target, int x, int y, IMAGE* source)
{
	int w = source->getwidth();
	int h = source->getheight();
	HDC dstDC = GetImageHDC(target);
	HDC srcDC = GetImageHDC(source);

	// �ṹ��ĵ�������Ա��ʾ�����͸���ȣ�0 ��ʾȫ͸����255 ��ʾ��͸����
	BLENDFUNCTION bf = { AC_SRC_OVER , 0 , 255 , AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}