// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// entry point
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
        {
            DWORD currentPID = GetCurrentProcessId();
            char message[256];
            sprintf_s(message, sizeof(message), "DLL running in PID: %d", currentPID);
            MessageBoxA(NULL, message, "Process Context Proof", MB_OK);
            break;
        }
        case DLL_PROCESS_DETACH:
            MessageBoxA(NULL, "goodbye!", "test", MB_OK | MB_ICONINFORMATION);
            break;
    }

    return TRUE;
}