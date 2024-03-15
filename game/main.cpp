#include "interface.h"

int main() {
	initgraph(1280, 640);

	ExMessage msg;
	IMAGE img_background;
	std::vector<Enemy*> enemy_list;

	bool running = 1;
	int counter = 0;

	loadimage(&img_background, L".\\img\\background.jpg" , 1280 , 640);
	Player player = Player(SPEED);

	BeginBatchDraw();

	while (running)
	{
		DWORD start_time = GetTickCount();
		while (peekmessage(&msg))
		{
			player.ProcessEvent(msg);
		}
		player.Move();

		counter++;
		if (counter % 5 == 0)
		{
			enemy_list.push_back(new Enemy());
			counter = 0;
		}
		for (int i = 0 ; i < enemy_list.size() ; i++)
			enemy_list[i]->Move(player);
		std::cout << enemy_list.size() << std::endl;

		cleardevice();
		putimage(0, 0, &img_background);
		player.Draw(45);
		for (int i = 0; i < enemy_list.size(); i++)
			enemy_list[i]->Draw(45);

		FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		//¶¯Ì¬ÑÓÊ±Ö¡Êý
		if (delta_time < FRAME_PER_SECOND)
			Sleep(FRAME_PER_SECOND - delta_time);

	}

	EndBatchDraw();
	return 0;
}
