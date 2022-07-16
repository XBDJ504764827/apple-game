#include<stdio.h>
#include<easyx.h>
#include<mmsystem.h>
#include<time.h>
#pragma comment(lib,"winmm.lib")


int main()
{
	initgraph(600, 600);
	IMAGE bkimg;
	IMAGE appimg0, appimg1;

	loadimage(&bkimg, "./img/aaiyd-dmw9i.jpg");
	loadimage(&appimg0, "./img/apple0.jpg");
	loadimage(&appimg1, "./img/apple1.jpg");

	mciSendString("open ./img/告白气球.mp3", 0, 0, 0);
	mciSendString("play ./img/告白气球.mp3", 0, 0, 0);

	setbkmode(TRANSPARENT);

	int x, y;
	char ch;
	int score = 0;
	ExMessage msg;
	int speed = 1;
	srand((unsigned int)time(NULL));

	while (1)
	{
		
		ch = 'A' + rand() % 26;
		x = rand() % 500;

		for (y = 0; y < 600; y += speed)
		{
			BeginBatchDraw();
			putimage(0, 0, &bkimg);
			putimage(x, y, &appimg0, SRCPAINT);
			putimage(x, y, &appimg1, SRCAND);

			outtextxy(x + 20, y + 20, ch);

			char str[20];
			sprintf_s(str, "分数:%d", score);
			settextcolor(RGB(0, 0, 0));
			outtextxy(500, 4, str);
			EndBatchDraw();

			peekmessage(&msg, EM_KEY);
			if (msg.message == WM_KEYDOWN)
			{
				if (msg.vkcode == ch)
				{
					score += 5;
					if (score >= 0 && score <= 100)
						speed = 1;
					else if (score>100&&score<=150)
					{
						speed = 2;
					}
					break;
				}
			}

			Sleep(10);
		}
	}

	return 0;
}