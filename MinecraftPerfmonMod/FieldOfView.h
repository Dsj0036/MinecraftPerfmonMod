#include <IncludeLibs.h>
#pragma once
#include <PS3.h>
namespace FOV
{
	char x1[] = { 0x3F, 0x70 };
	char x2[] = { 0x3F, 0x60 };
	char x3[] = { 0x3F, 0x50 };
	char x4[] = { 0x3F, 0x40 };
	char x5[] = { 0x3F, 0x30 };
	char x6[] = { 0x3F, 0x25 };
	char x7[] = { 0x3F, 0x20 };
	char x8[] = { 0x3F, 0x15 };
	char x9[] = { 0x3F, 0x10 };//X8
	int index = 0;
	void SetFov(int value)
	{
		char HEX[] = { NyTekCFW::IntToHex(value) };
		sys_dbg_write_process_memory(0x00AD5ECD, &HEX, sizeof(HEX));
		sys_dbg_write_process_memory_ps3mapi(0x00AD5ECD, &HEX, sizeof(HEX));
	}

	void Max()
	{
		char MOD1[] = { 0x68 };
		sys_dbg_write_process_memory(0x00987502, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x00987502, &MOD1, sizeof(MOD1));
	}
	void ResetToDefault()
	{
		char MOD1[] = { 0x08 };
		sys_dbg_write_process_memory(0x00987502, &MOD1, sizeof(MOD1));
		sys_dbg_write_process_memory_ps3mapi(0x00987502, &MOD1, sizeof(MOD1));
	}
	void set(char*sz)
	{
		sys_dbg_write_process_memory(0x00987502, &sz, sizeof(sz));
		sys_dbg_write_process_memory_ps3mapi(0x00987502, &sz, sizeof(sz));
	}
	void Set(int index)
	{
		if (index>8 || index<0)
		{
			index = 0;
		}
		switch (index)
		{
		case 0:set(x1); break;
		case 1:set(x2); break;
		case 2:set(x3); break;
		case 3:set(x4); break;
		case 4:set(x5); break;
		case 5:set(x6); break;
		case 6:set(x7); break;
		case 7:set(x8); break;
		case 8:set(x9); break;
		}
	}
	void Plus()	{ Set(index = index + 1); }
	void Minus(){ Set(index = index - 1); };
}