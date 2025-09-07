#include "Head.h"
int main()

{
	//基本初始化
	InitAudioDevice();
	InitWindow(Lenth, Width, "Be A Sworder!");
	//主菜单初始化
	InitMenu(Lenth,Width);
	//随机值初始化
	SetRandomSeed((unsigned int)time(NULL));
	//音效初始化
	Sound button1 = LoadSound("./resource/button.ogg");
	Sound button2 = LoadSound("./resource/button2.ogg");
	//帧率
	SetTargetFPS(120);
	//主循环
	while (!WindowShouldClose())
	{
		//输入处理
		Vector2 mouse_position = GetMousePosition();
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouse_position, StartButtonPosition))
		{
			PlaySound(button1);
			GameIs = 1;
		}
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mouse_position, ExitButtonPosition))
		{
			PlaySound(button2);
			GameIs = 2;
		}
		//状态更新
		if (GameIs == 1)
		{
			Game();
		}
		if (GameIs == 2)
		{
			WaitTime(0.5);
			break;
		}
		//渲染
		BeginDrawing();
		ClearBackground(WHITE);
		DrawMenu(StartButtonPosition,ExitButtonPosition);
		EndDrawing();
	}
	//UnloadFont(GameFont);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}