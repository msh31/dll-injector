#include <iostream>
#include <string>

#include "injector.hpp"

int main()
{
	injector injector;
	std::string processName, dllPath;

	const std::string red = "\033[31m";
	const std::string green = "\033[32m";
	const std::string reset = "\033[0m";

	std::cout << "=== Process Injection Toolkit ===\n";

	std::cout << "\nEnter process name: ";
	std::getline(std::cin, processName);
	std::cout << "\nEnter full DLL path: ";
	std::getline(std::cin, dllPath);

	DWORD processID = injector.findProcessID(processName);

	if (processID == NULL || processID == 0) {
		std::cout << "\n\n failed to get processID, exiting..";
		return -1;
	}

	if (injector.injectDLL(processID, dllPath)){
		std::cout << green << "[+] Injection of " << dllPath << " into " << processName << " was succesful!" << reset << "\n";
	}
	else {
		std::cout << red << "[-] Failed to inject " << dllPath << " into " << processName << "!" << reset << "\n";
	}

	return 0;
}