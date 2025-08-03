#pragma once
#include <windows.h>
#include <psapi.h>
#include <string>
#include <locale>
#include <codecvt>

#include "handle_wrapper.hpp"

class injector {
    private:
        std::wstring stringToWString(const std::string& str);

    public:
        DWORD findProcessID(const std::string& targetProcessName);

        bool injectDLL(DWORD processID, std::string pathToDLL);

        //~injector();
};