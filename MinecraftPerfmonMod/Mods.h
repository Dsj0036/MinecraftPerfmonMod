
#include<PS3.h>
#include "McButtons.h"
#pragma once
void Enh_NameHead(){

	char HEX[] = { 0xFF, 0xC0, 0xE0, 0x90 };
	sys_dbg_write_process_memory(0x00AD8110, &HEX, sizeof(HEX));
	sys_dbg_write_process_memory_ps3mapi(0x00AD8110, &HEX, sizeof(HEX));
}
void Enh_CamdownR3(bool toggle)
{
	if (toggle)
	{
		char HEX[] = { 0xFC, 0x00, 0xF8, 0x90 };
		sys_dbg_write_process_memory(0x004B1D60, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x004B1D60, &HEX, sizeof(HEX));
	}
	else
	{
		char HEX[] = { 0xFC, 0x20, 0xF8, 0x90 };
		sys_dbg_write_process_memory(0x004B1D60, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x004B1D60, &HEX, sizeof(HEX));
	}
}
void Enh_JumpBetter(){

	char MOD1[] = { 0xBF };
	sys_dbg_write_process_memory(0x014C6728, &MOD1, sizeof(MOD1));
	sys_dbg_write_process_memory_ps3mapi(0x014C6728, &MOD1, sizeof(MOD1));
}
void Enh_Armor()
{
	char SPEED[] = { 0x38, 0x80, 0x00, 0x01 };
	sys_dbg_write_process_memory(0x0090B5F0, &SPEED, sizeof(SPEED));
	sys_dbg_write_process_memory_ps3mapi(0x0090B5F0, &SPEED, sizeof(SPEED));
}
bool zoomkey()
{
	return (Buttons::IsMCButtonPressed(Buttons::L1) && Buttons::IsMCButtonPressed(Buttons::R1));
}
bool selectkey()
{
	return Buttons::IsMCButtonPressed(Buttons::SELECT);
}
void CAMERA_LEFT(bool toggle)
{
	if (toggle)
	{
		char MOD1[] = { 0x40 };
		sys_dbg_write_process_memory(0x00A991AC, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x00A991AC, &MOD1, sizeof(MOD1));

	}
	else
	{
		char MOD1[] = { 0x41 };
		sys_dbg_write_process_memory(0x00A991AC, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x00A991AC, &MOD1, sizeof(MOD1));
	}
}
bool pressed(unsigned int buttons)
{
	return Buttons::IsMCButtonPressed(buttons);
}
void CAMERA_RIGHT(bool toggle)
{
	if (toggle)
	{
		char MOD1[] = { 0x40 };
		sys_dbg_write_process_memory(0x00A99050, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x00A99050, &MOD1, sizeof(MOD1));

	}
	else
	{
		char MOD1[] = { 0x41 };
		sys_dbg_write_process_memory(0x00A99050, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x00A99050, &MOD1, sizeof(MOD1));

	}
}
void HUD_LOADING(bool toggle)
{
	if (toggle)
	{
		char MOD1[] = { 0x01 };
		sys_dbg_write_process_memory(0x014CE214, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x014CE214, &MOD1, sizeof(MOD1));

	}
	else
	{
		char MOD1[] = { 0x00 };
		sys_dbg_write_process_memory(0x014CE214, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x014CE214, &MOD1, sizeof(MOD1));
	}
}
const char*GetPlayerNameC()
{

	return PS3Lib::ReadStringC(0x30F46D04);
}

bool InWorld()
{
	return!(*(char*)0x3000CF6B != 0);
}

void Enh_EnableDebugIDs(bool toggle)
{
	if (toggle)
	{
		char HEX[] = { 0x40 };
		sys_dbg_write_process_memory(0x003097C8, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x003097C8, &HEX, sizeof(HEX));

		char HEX1[] = { 0x40 };
		sys_dbg_write_process_memory(0x003097B8, &HEX1, sizeof(HEX1));
		sys_dbg_write_process_memory_ps3mapi(0x003097B8, &HEX1, sizeof(HEX1));
	}
	else
	{
		char HEX[] = { 0x41 };
		sys_dbg_write_process_memory(0x003097C8, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x003097C8, &HEX, sizeof(HEX));

		char HEX1[] = { 0x41 };
		sys_dbg_write_process_memory(0x003097B8, &HEX1, sizeof(HEX1));
		sys_dbg_write_process_memory_ps3mapi(0x003097B8, &HEX1, sizeof(HEX1));
	}
}void SWIM_FLY(bool toggle)
{
	if (toggle)
	{
		char HEX[] = { 0x3B, 0x40, 0x00, 0x10 };
		sys_dbg_write_process_memory(0x00390410, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x00390410, &HEX, sizeof(HEX));

		char HEX1[] = { 0x3D };
		sys_dbg_write_process_memory(0x003ABD44, &HEX1, sizeof(HEX1));
		sys_dbg_write_process_memory_ps3mapi(0x003ABD44, &HEX1, sizeof(HEX1));
	}
	else
	{
		char HEX[] = { 0x3B, 0x40, 0x00, 0x00 };
		sys_dbg_write_process_memory(0x00390410, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x00390410, &HEX, sizeof(HEX));

		char HEX1[] = { 0x3C };
		sys_dbg_write_process_memory(0x003ABD44, &HEX1, sizeof(HEX1));
		sys_dbg_write_process_memory_ps3mapi(0x003ABD44, &HEX1, sizeof(HEX1));
	}
}void reloadgui()
{
	HUD_LOADING(true);
	HUD_LOADING(false);
}
void INSTANT_MINE(bool toggle)
{
	if (toggle)
	{
		char HEX[] = { 0xBF };
		sys_dbg_write_process_memory(0x00AEB090, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x00AEB090, &HEX, sizeof(HEX));
	}
	else
	{
		char HEX[] = { 0x3F };
		sys_dbg_write_process_memory(0x00AEB090, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x00AEB090, &HEX, sizeof(HEX));
	}
}
void MOVEMENT_SWIM(bool toggle)
{
	if (toggle)
	{
		char HEX[] = { 0xBC };
		sys_dbg_write_process_memory(0x003ABD44, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x003ABD44, &HEX, sizeof(HEX));
	}
	else
	{
		char HEX[] = { 0x3C };
		sys_dbg_write_process_memory(0x003ABD44, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x003ABD44, &HEX, sizeof(HEX));
	}
}

void SWIM_GLITCH(bool toggle)
{
	if (toggle)
	{
		char HEX[] = { 0x40 };
		sys_dbg_write_process_memory(0x00B0229C, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x00B0229C, &HEX, sizeof(HEX));
	}
	else
	{
		char HEX[] = { 0x41 };
		sys_dbg_write_process_memory(0x00B0229C, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x00B0229C, &HEX, sizeof(HEX));
	}
}
