#pragma once

#include "src/playground/Vector3.h"

struct PhysicsBody
{

    PhysicsBody() = delete;

    PhysicsBody(const Vector3& position, const Vector3& velocity)
        : position { position }
        , velocity { velocity }
    {}

    PhysicsBody(const PhysicsBody& other)
        : position { other.position }
        , velocity { other.velocity }
    {}

    Vector3 position;
    Vector3 velocity;
};
