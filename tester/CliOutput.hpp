#pragma once

#include <libguart/Output.hpp>

class CliOutput : public guart::Output
{
public:
    Output& operator<<(const etl::string_view) override;
    Output& operator<<(char) override;

    void flush() override;
};