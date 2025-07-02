/**
 * @file TerminalInput.cpp
 * @author Adrian Szczepanski
 * @date 01-07-2025
 */

#include "TerminalInput.hpp"
#include <sys/select.h>
#include <fcntl.h>
#include <cstring>

TerminalInput::TerminalInput()
{
}

TerminalInput::~TerminalInput()
{
    if (isInitialized)
    {
        restore();
    }
}

bool TerminalInput::initialize()
{
    // Get current terminal attributes
    if (tcgetattr(STDIN_FILENO, &originalTermios) == -1)
    {
        return false;
    }
    
    // Setup terminfo
    int result = setupterm(nullptr, STDOUT_FILENO, nullptr);
    // if (result == )
    // {
    //     return false;
    // }
    
    setupRawMode();
    isInitialized = true;
    return true;
}

void TerminalInput::restore()
{
    if (isInitialized)
    {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTermios);
        isInitialized = false;
    }
}

void TerminalInput::setupRawMode()
{
    rawTermios = originalTermios;
    
    // Disable canonical mode, echo, and signals
    rawTermios.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ICRNL | ISIG | IEXTEN);
    rawTermios.c_iflag &= ~(IXON | IXOFF | IXANY | INPCK | ISTRIP);
    rawTermios.c_oflag &= ~(OPOST);
    rawTermios.c_cflag |= (CS8);
    
    // Set timeout for read
    rawTermios.c_cc[VMIN] = 0;   // Minimum characters to read
    rawTermios.c_cc[VTIME] = 1;  // Timeout in tenths of seconds
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &rawTermios);
}

int TerminalInput::getChar()
{
    char ch;
    ssize_t result = read(STDIN_FILENO, &ch, 1);
    if (result == 1)
    {
        return static_cast<unsigned char>(ch);
    }
    return -1; // No input or error
}

bool TerminalInput::isInputAvailable()
{
    fd_set readfds;
    struct timeval timeout;
    
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    
    return select(STDIN_FILENO + 1, &readfds, nullptr, nullptr, &timeout) > 0;
}

std::string TerminalInput::getSpecialKey()
{
    std::string sequence;
    int ch = getChar();
    
    if (ch == 27) // ESC sequence
    {
        sequence += static_cast<char>(ch);
        
        // Read the rest of the escape sequence
        while (isInputAvailable())
        {
            ch = getChar();
            if (ch != -1)
            {
                sequence += static_cast<char>(ch);
                
                // Most escape sequences end with a letter
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '~')
                {
                    break;
                }
            }
        }
    }
    else if (ch != -1)
    {
        sequence += static_cast<char>(ch);
    }
    
    return sequence;
}
