#pragma once
#include "Include.h"
#include "IncludeLibs.h"
int mcOfs = 0x014CF2E4,
gameRenderHook = 0x00AA3360, ctrlLockOfs = 0x0155847c, shaderOfs = 0x00A7E2E8, PlayUISFX = 0x886798, MultiPlayerGetEntity = 0xB0E8F4, GetLocalPlayerID = 0xAE03B4, MPDestroyBlock = 0xB34A6C, wcLenOfs = 0x00CB32D8, theMcOfs = 0x014cf2e4, Ofsprintf = 0xCB9910, Ofssnprintf = 0xCB9A10, GuiFillGardient = 0xA7D278, GuiRender = 0xA891F0, FontWidth = 0x00A7DB38, CinputRequestKeyboard = 0xC62B80, addr1 = 0x00BDCA84, addr2 = 0x00BDCA9C, addr3 = 0x009C1928, addr4 = 0x009C1A3C, addr5 = 0x009C170C, addr6 = 0x009C2388, ofs1 = 0x30000000, ofs2 = 0x35000000, ofs3 = 0x01500000, ofs4 = 0x01100000;

bool MainMenu = true;
bool MenuIsOpened = true;
bool InitializeSPRX = true;
int selectionIndex = 0;


namespace UIColor
{
	int ButtonForeSelected[3] = { 247, 184, 22 };
	int ButtonFore[3] = { 200, 200, 200 };
	int Black[3] = { 0, 0, 0 };
	int MenuBackground[3] = { 181, 181, 181 };
	int ButtonFillSelectedOverlay[3] = { 86, 219, 99 };
	int ButtonFillSelectedBottom[3] = { 63, 166, 73 };
	int ButtonOverlay[3] = { 148, 148, 148 };
	int ButtonBottom[3] = { 120, 120, 120 };
	int White[3] = { 255, 255, 255 };
	int PerfmonColor[3] = { 70, 242, 73 };

};

TheMinecraft * mc;
namespace MinecraftColors
{
	int WHITE[3] = { 255, 255, 255 };
	int BLACK[4] = { 25, 25, 25, 50 };
	int BLACK1[4] = { 15, 15, 15, 50 };
	int BLACK2[4] = { 10, 10, 10, 50 };
	int PINK[3] = { 255, 137, 214 };
	int RED[4] = { 255, 16, 63, 20 };
	int ORANGE[3] = { 255, 143, 16 };
	int CYAN[3] = { 16, 233, 255 };
	int GREEN[3] = { 33, 192, 74 };
	int LIME[3] = { 0, 255, 15 };
	int BLUE[3] = { 0, 147, 255 };
	int PURPLE[3] = { 128, 0, 128 };
	int YELLOW[3] = { 255, 255, 0 };
	int TEST[4] = { 36, 36, 36, 0.8 };
	int RAINBOW[3] = { 255, 0, 0 };
	int RainbowRED = 135;
	int RainbowGREEN = 65;
	int RainbowBLUE = 54;
	int RainbowRED1 = 255;
	int RainbowGREEN1 = 10;
	int RainbowBLUE1 = 130;
};