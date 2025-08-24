#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

void launchConsole(const char* exeName) {
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    // Create a modifiable copy of the exeName string
    string commandLine = exeName;

    if (CreateProcess(
            NULL,                           // No module name
            &commandLine[0],                // Modifiable command line
            NULL,                           // Default security
            NULL,                           // Default security
            FALSE,                          // No inheritance
            CREATE_NEW_CONSOLE,             // New console window
            NULL,                           // Environment variables
            NULL,                           // Current directory
            &si,                            // STARTUPINFO
            &pi                             // PROCESS_INFORMATION
        )) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        DWORD error = GetLastError();
        cout << "Failed to start " << exeName << ". Error code: " << error << endl;
    }
}

int main() {
    cout << "Launching User and Admin Windows..." << endl;

    launchConsole("user.exe");
    launchConsole("admin.exe");

    cout << "Both consoles launched!" << endl;
    system("pause");
    return 0;
}