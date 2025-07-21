#pragma once

namespace guart::key
{
    static constexpr auto UP = "\x1b[A";          // Up arrow key
    static constexpr auto DOWN = "\x1b[B";        // Down arrow key
    static constexpr auto RIGHT = "\x1b[C";       // Right arrow key
    static constexpr auto LEFT = "\x1b[D";        // Left arrow key
    static constexpr auto HOME = "\x1b[H";        // Home key
    static constexpr auto END = "\x1b[F";         // End key
    static constexpr auto INSERT = "\x1b[2~";     // Insert key
    static constexpr auto DELETE = "\x1b[3~";     // Delete key
    static constexpr auto PAGE_UP = "\x1b[5~";    // Page Up
    static constexpr auto PAGE_DOWN = "\x1b[6~";  // Page Down
    static constexpr auto ESC = "\x1b";           // Escape key
    static constexpr auto CR = "\r";              // Enter key
    static constexpr auto NEW_LINE = "\n";        // New line key
    static constexpr auto CR_NL = "\r\n";         // Carriage return + new line key
    static constexpr auto BACKSPACE = "\x7f";     // Backspace key
    static constexpr auto TAB = "\t";             // Tab key
    static constexpr auto SPACE = " ";            // Space key
    static constexpr auto CTRL_C = "\x03";        // Ctrl+C
    static constexpr auto CTRL_D = "\x04";        // Ctrl+D
    static constexpr auto CTRL_A = "\x01";        // Ctrl+A
    static constexpr auto CTRL_E = "\x05";        // Ctrl+E
    static constexpr auto CTRL_F = "\x06";        // Ctrl+F
    static constexpr auto CTRL_B = "\x02";        // Ctrl+B
    static constexpr auto CTRL_N = "\x0e";        // Ctrl+N
    static constexpr auto CTRL_P = "\x10";        // Ctrl+P
    static constexpr auto CTRL_H = "\x08";        // Ctrl+H (Backspace)
    static constexpr auto CTRL_L = "\x0c";        // Ctrl+L (Clear screen)
    static constexpr auto CTRL_K = "\x0b";        // Ctrl+K (Clear to end of line)
    static constexpr auto CTRL_U = "\x15";        // Ctrl+U (Clear to start of line)
    static constexpr auto CTRL_W = "\x17";        // Ctrl+W (Delete word before cursor)
    static constexpr auto CTRL_T = "\x14";        // Ctrl+T (Transpose characters)
    static constexpr auto CTRL_Y = "\x19";        // Ctrl+Y (Yank - paste last killed text)
    static constexpr auto CTRL_X = "\x18";        // Ctrl+X (Prefix for other commands)
    static constexpr auto CTRL_Z = "\x1a";        // Ctrl+Z (Suspend process)
    static constexpr auto CTRL_Q = "\x11";        // Ctrl+Q (Resume output)
    static constexpr auto CTRL_S = "\x13";        // Ctrl+S (Pause output)
    static constexpr auto CTRL_O = "\x0f";        // Ctrl+O (Open line below)
    static constexpr auto CTRL_R = "\x12";        // Ctrl+R (Reverse search)
    static constexpr auto CTRL_V = "\x16";        // Ctrl+V (Insert next character verbatim)
    static constexpr auto CTRL_G = "\x07";        // Ctrl+G (Bell)
    static constexpr auto CTRL_J = "\x0a";        // Ctrl+J (New line, same as Enter)
    static constexpr auto CTRL_M = "\x0d";        // Ctrl+M (Carriage return, same as Enter)
    static constexpr auto SHIFT_UP = "\x1b[1;2A";    // Shift + Up arrow key
    static constexpr auto SHIFT_DOWN = "\x1b[1;2B";  // Shift + Down arrow key
    static constexpr auto SHIFT_RIGHT = "\x1b[1;2C"; // Shift + Right arrow key
    static constexpr auto SHIFT_LEFT = "\x1b[1;2D";  // Shift + Left arrow key
}