/* ************************************************************************** */
/*                                                                            */
/*                                                             _  __    __    */
/*   main.c                                                   /_\/ / /\ \ \   */
/*                                                           //_\\ \/  \/ /   */
/*   By: artwizard <hello@myrrys.art>                       /  _  \  /\  /    */
/*                                                          \_/ \_/\/  \/     */
/*   Created: 2024/07/31 22:30:39 by artwizard                                */
/*   Updated: 2024/08/01 00:04:15 by artwizard                 myrrys.art     */
/*                                                                            */
/* ************************************************************************** */

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void)
{
	const int	screen_w = 400;
	const int	screen_h = 400;
	int		click_count = 0;
	bool		autoClickerActive = false;
	float		autoClickerTimer = 0.0f;
	float		autoClickerInterval = 1.0f;

	Rectangle buttonRect = {100, 200, 200, 50};
	Rectangle counterRect = {100, 100, 200, 50};
	Rectangle autoidleRect = {100, 300, 200, 50};


	InitWindow(screen_w, screen_h, "simple idle game");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		float	deltaTime = GetFrameTime();

		if (GuiButton(buttonRect, "Click me!"))
			click_count++;
		if (click_count > 9 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), autoidleRect))
			autoClickerActive = !autoClickerActive;

		if (autoClickerActive)
		{
			autoClickerTimer += deltaTime;
			if (autoClickerTimer >= autoClickerInterval)
			{
				click_count++;
				autoClickerTimer -= autoClickerInterval;
			}
		}
		BeginDrawing();
		ClearBackground(DARKGRAY);
		GuiButton(buttonRect, "Click me!");
		DrawRectangleRec(counterRect, BLACK);
		DrawText(TextFormat("%d", click_count), counterRect.x + 10, counterRect.y + 10, 30, LIGHTGRAY);
		Color autoidleColor = (click_count > 9) ? (autoClickerActive ? GREEN : LIGHTGRAY ) : GRAY;
		DrawRectangleRec(autoidleRect, autoidleColor);
		DrawText("Auto+1", autoidleRect.x + 5, autoidleRect.y + 15, 20, BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
