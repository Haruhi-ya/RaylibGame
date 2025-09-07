#include "Head.h"
Rectangle StartButtonPosition;
Rectangle ExitButtonPosition;
Vector2 point1;
Vector2 point1t;
Vector2 point2;
Vector2 point2t;
Texture rectangle_depth;
Texture zombi;
//Font GameFont;     //测试字体屡次失败 这是为什么！！！

//菜单按钮初始化
void InitMenu(float Lenth, float Width)
{
	rectangle_depth = LoadTexture("./resource/rectangle_depth.png");
	zombi = LoadTexture("./resource/zombi.png");
	StartButtonPosition = (Rectangle){ Lenth / 2 - 200, Width / 1.2 - 250, rectangle_depth.width, rectangle_depth.height };
	ExitButtonPosition = (Rectangle){ Lenth / 2 - 200,Width / 1.15,rectangle_depth.width, rectangle_depth.height };
	point1 = (Vector2){ StartButtonPosition.x,StartButtonPosition.y };
	point2 = (Vector2){ ExitButtonPosition.x,ExitButtonPosition.y };
	point1t = (Vector2){ point1.x+28,point1.y+15 };
	point2t = (Vector2){ point2.x+52,point2.y+15 };
	//GameFont = LoadFont("./resource/Narrow.ttf");//字体
	// 检查字体是否加载成功
	//if (GameFont.texture.id == 0) 
	//{
	//	GameFont = GetFontDefault();
	//}
}
void DrawMenu(Rectangle StartButtonPosition, Rectangle ExitButtonPosition)
{	//DEBUG://DrawRectangleRec(StartButtonPosition, RED);
	//DEBUG://RectangleRec(ExitButtonPosition, RED);
	
	DrawTextureV(rectangle_depth, point1, WHITE);
	DrawTextureV(rectangle_depth, point2, WHITE);
	DrawTexture(zombi,Lenth/2.65,Width/16 , WHITE);
	DrawTextEx(/*GameFont*/GetFontDefault(), "START", point1t, 100, 5, MAROON);
	DrawTextEx(GetFontDefault(), "EXIT", point2t, 100, 25, MAROON);
}