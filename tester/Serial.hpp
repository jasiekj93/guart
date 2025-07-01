#pragma once

/**
 * @file Serial.hpp
 * @author Adrian Szczepanski
 * @date 10-06-2025
 */

#include <cstdint>

#include <string_view>
#include <array>

#include <libguart/Output.hpp>

class Serial : public guart::Output
{
public:
    Serial(std::string_view path);
    ~Serial();

    Output& operator<<(const std::string_view) override;
    Output& operator<<(char) override;

    void flush() override;

    // std::span<const uint8_t> read();

private:
    static constexpr size_t BUFFER_SIZE = 0x20000;

    int handle;
    std::array<uint8_t, BUFFER_SIZE> buffer;
};