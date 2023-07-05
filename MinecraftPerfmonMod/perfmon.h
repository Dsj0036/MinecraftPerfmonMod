#include <Include.h>
#include "Functions.h"

namespace Perfmon
{
	namespace Options
	{
		bool ShowUsername = true;
		bool ShowFPS = true;
		bool ShowCoords = true;
		bool ShowTime = false;
		bool ShowChunk = true;
		bool FixedWidth = true;
		bool ShowWalkedDist = true;
		bool ShowElapsed = true;
		bool ShowViewRot = true;
		bool ShowResolution = true;
		bool HasShadowStyle = true;
		bool HasBackground = true;
		int RowWitdh = 50;
	}
	int ticks = 0;
	void DrawElapsed(int x, int y, int* col)
	{
		const char* format = "Ticks: %i";
		if (Options::HasBackground & Options::HasShadowStyle == false)
		{
			FJ::DrawRectangle(x, y, strlen(format) + 10, 10, col);
		}
		FJ::DrawTextFormatted(format, ticks, x, y,color( col), Options::HasShadowStyle);
	}
	void DrawLabelBox(const wchar_t* text, int x, int y, int* col)
	{


		if (Options::HasBackground & Options::HasShadowStyle == false)
		{
			int width = FJ::Font_width(text);
			FJ::DrawRectangle(x, y, width + 10, 10, col);
		}
		if (Options::HasShadowStyle)
		{
			FJ::DrawTextWithShadow(text, x, y, color(col));
		}
		else {

			FJ::DrawText(text, x, y, color(col));
		}
	}
	void DrawFormatLabelBox(const char* format, int arg, int x, int y, int * col){
		if (Options::HasBackground & Options::HasShadowStyle == false)
		{
			FJ::DrawRectangle(x, y, strlen(format) + 10, 10, col);
		}
		FJ::DrawTextFormatted(format, arg, x, y, color(col), Options::HasShadowStyle);
	}
	void DrawFormatLabelBox(const char* format, int arg, int arg2, int x, int y, int * col){
		if (Options::HasBackground & Options::HasShadowStyle == false)
		{
			FJ::DrawRectangle(x, y, strlen(format) + 10, 10, col);
		}
		FJ::DrawTextFormatted2(format, arg, arg2, x, y, color(col), Options::HasShadowStyle);
	}
	bool Show = true;
	int OptionsHeight = 0;
	int Color[3] { 63, 204, 101 };

	namespace Location
	{
		int x = 0;
		int y = 0;
	}

	bool Toggle()
	{
		return Perfmon::Show = !Perfmon::Show;
	}
	int getTime[1000];
	int timeMath[1000];
	bool gotTime[1000];

	bool frameTime(int ms, int index, bool resetTime)
	{
		if (resetTime)
			gotTime[index] = false;
		if (!gotTime[index])
		{
			gotTime[index] = true;
			getTime[index] = mc->gameTime;
		}
		timeMath[index] = mc->gameTime - getTime[index];

		if (timeMath[index] >= ms)
		{
			gotTime[index] = false;
			return true;
		}
		else
			return false;
	}
	char fps[0x100];
	wchar_t wfps[0x100];
	void DrawFPS(int x, int y, int* foreColor)
	{
		if (frameTime(60, 0, false)){
			_sys_memset(fps, 0, 0x100);
			_sys_memset(wfps, 0, 0x200);
			_sys_snprintf(fps, 0x100, "FPS: %i", (mc->FPS / 2));
			StringToWideCharacter(wfps, fps, _sys_strlen(fps));

		}
		int width = FJ::Font_width(wfps);
		DrawLabelBox(wfps, x, y, foreColor);

	}
	void DrawChunk(int x, int y, int* foreColor)
	{
		char option[0x100];
		wchar_t woption[0x100];
		_sys_memset(option, 0, 0x100);
		_sys_memset(woption, 0, 0x200);
		_sys_snprintf(option, 0x100, "Chunk: (%i, %i, %i)", (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordX + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordY + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordZ + 1);
		StringToWideCharacter(woption, option, strlen(option));
		int width = FJ::Font_width(woption);
		DrawLabelBox(woption, x, y, foreColor);
	}
	void DrawCoords(int x, int y, int * col)
	{
		char option[0x100];
		wchar_t woption[0x100];
		_sys_memset(option, 0, 0x100);
		_sys_memset(woption, 0, 0x200);
		_sys_snprintf(option, 0x100, "Coords: (%i, %i, %i)", (int)mc->theMinecraft->cMultiplayerLocalPlayer->posX - 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->posY + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->posZ);
		StringToWideCharacter(woption, option, strlen(option));

		int width = FJ::Font_width(woption);
		DrawLabelBox(woption, x, y, col);
	}
	void DrawGtime(int x, int y, int * col)
	{
		int pos[2] = { x, y };
		uint32_t milliseconds = mc->gameTime;
		int seconds = (milliseconds / 60);
		int minutes = seconds / 60;
		int hours = minutes / 60;

		char option4[0x100];
		wchar_t woption4[0x100];
		_sys_memset(option4, 0, 0x100);
		_sys_memset(woption4, 0, 0x200);
		_sys_snprintf(option4, 0x100, "%i: %i: %i", int(hours % 24), int(minutes % 60), int(seconds % 60));

		StringToWideCharacter(woption4, option4, _sys_strlen(option4));
		DrawLabelBox(woption4, x, y, col);
	}
	void DrawUserName(int x, int y, int* col)
	{
		DrawLabelBox(mc->theMinecraft->cMultiplayerLocalPlayer->name, x, y, col);
	}
	void DrawViewAngles(int x, int y, int* col)
	{
		int rotj = mc->theMinecraft->cMultiplayerLocalPlayer->rotationYaw;
		int rotpi = mc->theMinecraft->cMultiplayerLocalPlayer->rotationPitch;
		DrawFormatLabelBox("RY: %i | RP: %i", rotj, rotpi, x, y, col);
	}
	void DrawResolution(int x, int y, int * col)
	{
		int re[2] {mc->theMinecraft->displayWidth, mc->theMinecraft->displayHeight };
		DrawFormatLabelBox("%ix%i", re[0], re[1], x, y, col);
	}
	void DrawWalked(int x, int y, int * col)
	{
		int walk = (mc->theMinecraft->cMultiplayerLocalPlayer->distanceWalkedModified) / 0.6;
		DrawFormatLabelBox("Walked: %i ", walk, x, y, col);
	}
	void emptymethod()
	{
		mc->theMinecraft->cMultiplayerLocalPlayer->setRenderDistanceWeight(5.0);
	}
	void Hook()
	{

		if (!Show)return;
		ticks++;
		int x = Location::x;
		int y = Location::y;
		if (Options::ShowResolution)
		{
			DrawResolution(x, y, Color);
			y += 10;
		}
		if (Options::ShowUsername)
		{
			DrawUserName(x, y, Color);
			y += 10;
		}
		if (Options::ShowTime)
		{
			DrawGtime(x, y, Color);
			y += 10;
		}
		if (Options::ShowFPS)
		{
			DrawFPS(x, y, Color);
			y += 10;
		}
		if (Options::ShowCoords)
		{
			DrawCoords(x, y, Color);
			y += 10;
		}
		if (Options::ShowChunk)
		{
			DrawChunk(x, y, Color);
			y += 10;
		}
		if (Options::ShowViewRot)
		{
			DrawViewAngles(x, y, Color);
			y += 10;
		}
		if (Options::ShowWalkedDist)
		{
			DrawWalked(x, y, Color);
			y += 10;
		}
		if (Options::ShowElapsed)
		{
			DrawElapsed(x,y, Color);
			y += 10;
		}
		OptionsHeight = y;
	}
}

