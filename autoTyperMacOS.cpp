#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#endif

void typeTextFile(const std::string &text)
{
#ifdef __APPLE__
    for (char c : text)
    {
        UniChar character = static_cast<UniChar>(c);
        CGEventRef keyEventDown = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)0, true);
        CGEventRef keyEventUp = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)0, false);
        CGEventKeyboardSetUnicodeString(keyEventDown, 1, &character);
        CGEventKeyboardSetUnicodeString(keyEventUp, 1, &character);
        CGEventPost(kCGHIDEventTap, keyEventDown);
        CGEventPost(kCGHIDEventTap, keyEventUp);
        CFRelease(keyEventDown);
        CFRelease(keyEventUp);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    CGEventRef returnKeyEventDown = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)0x24, true);
    CGEventRef returnKeyEventUp = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)0x24, false);
    CGEventPost(kCGHIDEventTap, returnKeyEventDown);
    CGEventPost(kCGHIDEventTap, returnKeyEventUp);
    CFRelease(returnKeyEventDown);
    CFRelease(returnKeyEventUp);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
#else
    std::cerr << "Bhai mac ke liye hai..." << std::endl;
#endif
}

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::ifstream inputFile("input.txt");
    if (!inputFile)
    {
        std::cerr << "input.txt naam ki file banao aur usme daalo content to be typed" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        typeTextFile(line);
        CGEventRef returnKeyEventDown = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)0x24, true);
        CGEventRef returnKeyEventUp = CGEventCreateKeyboardEvent(NULL, (CGKeyCode)0x24, false);
        CGEventPost(kCGHIDEventTap, returnKeyEventDown);
        CGEventPost(kCGHIDEventTap, returnKeyEventUp);
        CFRelease(returnKeyEventDown);
        CFRelease(returnKeyEventUp);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    inputFile.close();
}