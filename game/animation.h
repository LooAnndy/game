//
// auther:LooAnndy
// function:
// ���ڲ��ŵ���Animation������ͼƬ͸���ȵĺ���putimage_alpha
//

#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "game.h"

//
//ʵ����Amimation���ʱ����Ҫ����������
// path ����Դ�Ļ���·��a
// num ����ͼƬ������
// intervalͼƬ����֮���ʱ����
//

class Animation
{
public:
	Animation(LPCTSTR path, size_t num, int interval);
	~Animation();

	//����ʱ�����ڣ�x , y)λ���ϻ��Ƶ�ǰ֡
	void Play(int x, int y, int delta);

private:
	int timer;//	������ʱ������ʱ����interval֮������һ֡
	int idx_frame;//������֡����
	int interval_ms;
	std::vector<IMAGE*> frame_list;
};

void putimage_alpha(IMAGE* target, int x, int y, IMAGE* source);

#endif // !ANIMATION_H_
