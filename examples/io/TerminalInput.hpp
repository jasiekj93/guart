#pragma once

/**
 * @file TerminalInput.hpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <iostream>
#include <string>

class TerminalInput
{
public:
    TerminalInput();
    ~TerminalInput();

    // Initialize terminal for direct input
    bool initialize();
    
    // Restore terminal to original state
    void restore();
    
    // Get a single character without waiting for Enter
    int getChar();
    
    // Check if input is available without blocking
    bool isInputAvailable();
    
    // Get special key codes (arrows, function keys, etc.)
    std::string getSpecialKey();

private:
    struct termios originalTermios;
    struct termios rawTermios;
    bool isInitialized = false;
    
    // Setup raw mode
    void setupRawMode();
};
