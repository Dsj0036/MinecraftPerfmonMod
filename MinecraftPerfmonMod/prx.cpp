#include "stdafx.h"

#include <cellstatus.h>
#include <sys/prx.h>
#include "Module.h"
#include "Variables.h"

#pragma region Botones


	unsigned int buttonMonitoring = 0x3000CF79;//AddressButtons1.84!
	unsigned int

		X = 0x100,
		O = 0x200,
		SQUARE = 0x400,
		TRIANGLE = 0x800,
		UP = 0x40000,
		DOWN = 0x80000,
		LEFT = 0x100000,
		RIGHT = 0x200000,
		R1 = 0x4000,
		R2 = 0x0,//NEEDFOUND
		R3 = 0x10000,
		L1 = 0x8000,
		L2 = 0x0,//NEEDFOUND
		L3 = 0x20000,
		START = 0x2000,
		SELECT = 0x1000,

		JOYSTICK_L3_UP = 0x20000000,
		JOYSTICK_L3_DOWN = 0x10000000,
		JOYSTICK_L3_LEFT = 0x00800000,
		JOYSTICK_L3_RIGHT = 0x00400000
		;

	unsigned int getMCButtons()
	{
		return*(unsigned int*)(buttonMonitoring);
	}

	bool IsMCButtonPressed(unsigned int Buttons)
	{
		return(getMCButtons() & Buttons)>0;
	}
#pragma endregion


SYS_MODULE_INFO( MinecraftPerfmonMod, 0, 1, 1);
SYS_MODULE_START( _MinecraftPerfmonMod_prx_entry );
SYS_MODULE_STOP(_MinecraftPerfmonMod_prx_stop);


SYS_LIB_DECLARE_WITH_STUB( LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME );
SYS_LIB_EXPORT( _MinecraftPerfmonMod_export_function, LIBNAME );

// An exported function is needed to generate the project's PRX stub export library
extern "C" int _MinecraftPerfmonMod_export_function(void){ return CELL_OK;}

void gameRender_Stub(uint32_t r3, uint32_t r4)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}
void OnNewFrame(uint32_t r3, uint32_t r4)
{
	gameRender_Stub(r3, r4);
	mc = (TheMinecraft*)(mcOfs);
	wrld();
	watermark();
	if (mc->theMinecraft->cMultiplayerLocalPlayer->isDead == false)
	{
		Perfmon::Hook();
		if (IsMCButtonPressed(L1))
		{
			FJ::DrawTextFormatted("r3: %i", (r3 != NULL ? (r3) : 0 ), 30, 0, color(MinecraftColors::BLACK), true);
		}
		alphatick();
		crosshair();
	}

	//ModuleFrame();
}

extern "C" int _MinecraftPerfmonMod_prx_entry(void)
{
	Dialog::DisplayMessage(" Perfmon Mod v1.0 CFW\nBy Destructorrpy\nSubscribe to YouTube.\nCredits on github.", 10);
	HookFunctionStart(gameRenderHook, *(uint32_t*)(OnNewFrame), *(uint32_t*)(gameRender_Stub));
    return SYS_PRX_RESIDENT;
}
extern "C" int _MinecraftPerfmonMod_prx_stop(void)
{

	return SYS_PRX_RESIDENT;
}