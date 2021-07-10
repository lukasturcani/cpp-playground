#pragma once


struct Vector3
{
    Vector3() = delete;

    Vector3(
        const float x,
        const float y,
        const float z
    )
        : x { x }
        , y { y }
        , z { z }
    {}

    Vector3(const Vector3& other)
        : x { other.x }
        , y { other.y }
        , z { other.z }
    {}

    float x;
    float y;
    float z;
};
