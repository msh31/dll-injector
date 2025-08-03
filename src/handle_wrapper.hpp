#pragma once
#include <Windows.h>

class HandleWrapper {
private:
    HANDLE handle;

public:
    HandleWrapper(HANDLE h) : handle(h) {}

    ~HandleWrapper() {
        if (handle != NULL && handle != INVALID_HANDLE_VALUE) {
            CloseHandle(handle);
        }
    }

    operator HANDLE() const { return handle; }

    HandleWrapper(const HandleWrapper&) = delete;
    HandleWrapper& operator=(const HandleWrapper&) = delete;
};