#include "injector.hpp"

DWORD injector::findProcessID(const std::string& targetProcessName)
{
    DWORD processIDs[1024];
    DWORD bytesReturned;
    wchar_t currentProcessName[MAX_PATH];

    if (!EnumProcesses(processIDs, sizeof(processIDs), &bytesReturned)) { 
        return 0; 
    }

    int numProcesses = bytesReturned / sizeof(DWORD);
    std::wstring targetProcessNameW = stringToWString(targetProcessName);

    for (int i = 0; i < numProcesses; ++i)    {
        HandleWrapper processHandle(OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processIDs[i]));

        if (processHandle == NULL) { 
            continue; 
        }

        if (!GetModuleBaseNameW(processHandle, NULL, currentProcessName, sizeof(currentProcessName) / sizeof(wchar_t))) { 
            continue; 
        }

        if (_wcsicmp(currentProcessName, targetProcessNameW.c_str()) == 0) { 
            return processIDs[i];
        }
    }

    return 0;
}

std::wstring injector::stringToWString(const std::string& str) {
    if (str.empty()) {
        return L"";
    }

    int sizeNeeded = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
    std::wstring wstr(sizeNeeded, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], sizeNeeded);

    wstr.pop_back();
    return wstr;
}

bool injector::injectDLL(DWORD processID, std::string pathToDLL)
{
    //TODO: Implement this

    return false;
}
