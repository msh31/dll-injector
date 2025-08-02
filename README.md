# 🧬 DLL Injector - Educational Malware Sample

**Part of the [Malware Analysis Course](https://github.com/msh31/malware-analysis) - Challenge 2B**

Educational demonstration of Windows process injection techniques commonly used by malware for code execution within legitimate processes.

## 🎯 Learning Objectives

This project taught me core malware process manipulation techniques:

### **DLL Injection Fundamentals**
- **DLL injection** via `CreateRemoteThread()` and `LoadLibrary()`
- **Process memory manipulation** using `VirtualAllocEx()` and `WriteProcessMemory()`
- **Remote thread execution** for code execution in target processes
- **Cross-architecture handling** for x86/x64 process injection

### **Advanced Injection Techniques**
- **Process hollowing** - replace legitimate process memory with malicious code
- **Thread execution hijacking** - redirect existing threads to execute injected code
- **Manual DLL mapping** - load DLLs without using Windows loader APIs
- **Stealth injection methods** - evade detection and monitoring systems

## 🔧 Techniques Implemented

### **Core Windows APIs**
- `OpenProcess()` - Obtain process handles with required permissions
- `VirtualAllocEx()` - Allocate memory in remote process address space
- `WriteProcessMemory()` - Write injection payloads to target process
- `CreateRemoteThread()` - Execute code within target process context
- `GetProcAddress()` - Resolve API addresses for injection

### **Advanced Process Manipulation**
- `NtUnmapViewOfSection()` - Process hollowing implementation
- `SetThreadContext()` - Thread execution redirection
- `SuspendThread()`/`ResumeThread()` - Thread state manipulation
- `GetThreadContext()` - Thread state preservation and modification

## 🛠️ Compilation & Usage

### **Requirements**
- **Platform:** Windows 10/11
- **Compiler:** Visual Studio 2022 or MinGW-w64
- **Dependencies:** Windows API (kernel32.lib, ntdll.lib)
- **Architecture:** Supports both x86 and x64 injection

### **Build Instructions**

**Visual Studio 2022:**
```bash
Build → Configuration Manager → Release → Build Solution
```

**Command Line (MinGW):**
```bash
g++ -o dll-injector.exe src/*.cpp -lkernel32 -lntdll -static
```

### **Safe Execution**
```bash
./dll-injector.exe

# Test with safe targets
# Target: notepad.exe, calc.exe, or custom test applications
# Payload: MessageBox DLL for verification
```

## 📊 Sample Output

```
=== DLL INJECTION TOOLKIT ===

Available Processes:
PID: 1234 | notepad.exe
PID: 5678 | calc.exe  
PID: 9012 | explorer.exe

Select target PID: 1234
DLL Path: C:\test\messagebox.dll

[+] Process opened successfully (PID: 1234)
[+] Memory allocated in target process: 0x0FF0A0010000
[+] DLL path written to target memory
[+] LoadLibrary address resolved: 0x7FF8A0020000
[+] Remote thread created successfully
[+] DLL injection completed!

Injection validated: MessageBox appeared from target process context
```

## 🛡️ Detection & Mitigation

### **Detection Indicators**
- Unusual `CreateRemoteThread()` API calls between processes
- Memory allocations in unexpected process address spaces  
- Cross-process `WriteProcessMemory()` operations
- Processes with modified thread execution contexts
- Unexpected loaded modules in process memory space

### **Defensive Measures**
- Process memory protection (CFG, CET)
- API hooking and monitoring systems
- Behavioral analysis of process interactions
- Memory scanning for injected code patterns
- Thread execution monitoring and validation

## 📖 References & Further Reading

- **[MITRE ATT&CK: Process Injection](https://attack.mitre.org/techniques/T1055/)** - Comprehensive technique overview
- **[Windows Internals 7th Edition](https://docs.microsoft.com/en-us/sysinternals/resources/windows-internals)** - Process and thread internals
- **[PE Format Documentation](https://docs.microsoft.com/en-us/windows/win32/debug/pe-format)** - Essential for advanced injection
- **[Red Team Notes: Process Injection](https://www.ired.team/offensive-security/code-injection-process-injection)** - Practical implementation examples
- **[Malware Analysis Bootcamp](https://class.malware.re/)** - Advanced injection techniques

## 📊 Analysis Reports (To-Do)

See [ANALYSIS.md](./ANALYSIS.md) for detailed:
- Static analysis of injection tool with PE examination
- Dynamic analysis showing injection process with API monitoring
- Memory forensics of injected processes with volatility analysis

---