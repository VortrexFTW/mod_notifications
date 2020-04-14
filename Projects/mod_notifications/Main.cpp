
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDKHelper.h>

#define NTDDI_VISTA

#include "wintoastlib.h"

MODULE_MAIN("notifications");

void ModuleRegister()
{
	SDK::RegisterFunction("toast", [](Galactic3D::Interfaces::INativeState* pState, int32_t argc, void* pUser) {
		SDK_TRY;

		SDK::State State(pState);

		 szTextW;


		const char* szText = State.CheckString(0);

		if(!WinToast::instance()->initialize()) {
			SDK::BooleanValue ReturnFalse(false);
			State.Return(ReturnFalse);
			return false;
		}

		WinToast::instance()->setAppName("GTA Connected");
		WinToastTemplate templ(WinToastTemplate::Text02);
		templ.setTextField(L"GTA Connected", WinToastTemplate::FirstLine);
		templ.setTextField((std::wstring)szText, WinToastTemplate::SecondLine);

		if (WinToast::instance()->showToast(templ, new CustomHandler()) < 0) {
			std::wcerr << L"Could not launch your toast notification!";
			return Results::ToastFailed;
		}

		SDK::BooleanValue ReturnTrue(true);
		State.Return(ReturnTrue);
		return true;

		SDK_ENDTRY;
	});
}

void ModuleUnregister()
{
}