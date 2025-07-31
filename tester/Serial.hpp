#pragma once

/**
 * @file Serial.hpp
 * @author Adrian Szczepanski
 * @date 10-06-2025
 */

#include <cstdint>
#include <array>

#include <etl/string.h>

#include <libguart/Output.hpp>

class Serial : public guart::Output
{
public:
    Serial(std::string_view path);
    ~Serial();

    Output& operator<<(const etl::string_view) override;
    Output& operator<<(char) override;

    void flush() override;

    // std::span<const uint8_t> read();

private:
    static constexpr size_t BUFFER_SIZE = 0x20000;

    int handle;
    std::array<uint8_t, BUFFER_SIZE> buffer;
};