#include <windows.h>
#include <thread>
#include <chrono>

// Short delay between actions
void wait(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    // Step 1: Fake warning
    MessageBox(
        NULL,
        "WARNING: Suspicious activity detected!",
        "Windows Defender",
        MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL
    );
    wait(1000);

    // Step 2: Fake scan
    for (int i = 1; i <= 5; ++i) {
        char buffer[100];
        sprintf(buffer, "Scanning system... [%d/5]", i);
        MessageBox(
            NULL,
            buffer,
            "Virus Scanner",
            MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL
        );
        wait(500);
    }

    // Step 3: Fake threat detected
    MessageBox(
        NULL,
        "Trojan.Win32.Generic detected!\nAttempting to quarantine...",
        "Alert!",
        MB_OKCANCEL | MB_ICONERROR | MB_SYSTEMMODAL
    );
    wait(1000);

    // Step 4: Final reveal
    MessageBox(
        NULL,
        "Just kidding! ??\nThis was a harmless prank.",
        "FAKE VIRUS",
        MB_OK | MB_ICONASTERISK | MB_SYSTEMMODAL
    );

    return 0;
}
