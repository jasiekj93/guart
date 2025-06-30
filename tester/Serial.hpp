#pragma once

/**
 * @file Serial.hpp
 * @author Adrian Szczepanski
 * @date 10-06-2025
 */

#include <cstdint>

#include <string_view>
#include <array>

class Serial 
{
public:
    Serial(std::string_view path);
    ~Serial();

    void write(std::string_view);
    void write(char);

    // std::span<const uint8_t> read();

private:
    static constexpr size_t BUFFER_SIZE = 0x20000;

    int handle;
    std::array<uint8_t, BUFFER_SIZE> buffer;
};