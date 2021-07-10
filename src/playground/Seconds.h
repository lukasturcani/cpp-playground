#pragma once

struct Seconds
{
    Seconds() = delete;

    explicit
    Seconds(const float value)
        : value { value }
    {}

    Seconds(const Seconds& other)
        : value { other.value }
    {}

    float value;
};
