
#include "Mods.h"
#include "Dialog.h"
#include "FieldOfView.h"
#include "perfmon.h"
#include "Variables.h"
bool camr;
bool caml;

int ticks = 0;
int alpha = 0;
std::uint32_t getColorA()
{
	return color(alpha, 255 - alpha, alpha);
}
void watermark()
{
	const wchar_t* wm = L"dedsprx";
	FJ::DrawTextWithShadow(wm, 600 - FJ::Font_width(wm), 600, getColorA());

}
void crosshair()
{
	MultiplayerLocalPlayer* pl = mc->theMinecraft->cMultiplayerLocalPlayer;

	//else if (pl->isInWater())
	{
		//FJ::DrawTextWithShadow(L"[In Water]", 330, 180, color(MinecraftColors::BLUE));
	}
	int y = 180;

	if (!pl->isCollidedVertically)
	{
		if (pl->fallDistance > 0)
		{
			FJ::DrawTextFormatted("[Falling from %i blocks]", ((int)pl->fallDistance), 330-(FJ::Font_width(L"FFFFFFFFFFFFFF")/2), 0, color(MinecraftColors::RED), true);
		}
	}
	if (!pl->isCollided)
	{
		FJ::DrawTextWithShadow(L"[In Air]", 330, y, color(MinecraftColors::WHITE));

		y += 10;
	}
	if (pl->inPortal)
	{
		FJ::dimgui();
		FJ::DrawTextWithShadow(L"[In Portal]", 330, y, color(MinecraftColors::WHITE));
		y += 10;
	}
	else
	{
		FJ::undimgui();
	}
	if (pl->sliding)
	{
		FJ::DrawTextWithShadow(L"[Sliding]", 330, y, color(MinecraftColors::CYAN));
		y += 10;
	}
}
void alphatick()
{
	alpha++;
	if (alpha >= 244)
	{
		alpha = 0;
	}

}
void co()
{
	sys_get_random_number(0, 20);
}
bool test = false;
void wrld()
{
	MultiplayerLocalPlayer* pl = mc->theMinecraft->cMultiplayerLocalPlayer;
	int y = pl->posY;

	if (y > 240)
	{
		pl->extinguish();
	}
	if (y< 5)
	{
		mc->theMinecraft->cMultiplayerLocalPlayer->posY = mc->theMinecraft->cMultiplayerLocalPlayer->posY - 5;
	}
}
void ModuleFrame()
{


	bool r2 = pressed(Buttons::R2);
	bool r3 = pressed(Buttons::R3);
	bool l2 = pressed(Buttons::L2);
	bool l3 = pressed(Buttons::L3);
	bool start = pressed(Buttons::START);
	bool select = pressed(Buttons::SELECT);


	if (select & r2)
	{
		Dialog::DisplayMessage("Game Plugin Unloaded.\nGoodbye! ", 10);
	}
	bool ingame = InWorld();
	if (ingame)
	{


		bool zoom = r2 & l2;
		int offset = 0x014C670C;
		int zoff = 0x3F800000;
		int zoon = 0x40500000;
		// zoom
		if (zoom)
		{
			FOV::ResetToDefault();
			(*(int*)offset) = zoon;
		}
		else if (zoom == false)
		{
			(*(int*)offset) = zoff;
			FOV::Max();
		}

		// LEANING

		bool leftCam = l3 & pressed(Buttons::LEFT);
		bool rightCam = l3 & pressed(Buttons::RIGHT);

		if (caml == true)
		{
			if (camr == true)
			{
				CAMERA_RIGHT(false);
			}
			CAMERA_LEFT(caml);
		}
		else CAMERA_LEFT(false);

		if (camr == true)
		{
			CAMERA_RIGHT(camr);
		}
		else CAMERA_RIGHT(false);
		camr = (rightCam)& (!leftCam);
		caml = (leftCam)& (!rightCam);

		if (rightCam) CAMERA_RIGHT(true);

		// PRONING
		bool R3 = Buttons::IsMCButtonPressed(Buttons::R3);
		if (R3)
		{
			MOVEMENT_SWIM(true);
			Enh_CamdownR3(true);
			sys_sleep(400);
		}
		if (R3 == false){
			MOVEMENT_SWIM(false);
			Enh_CamdownR3(false);
		}


	}


}
