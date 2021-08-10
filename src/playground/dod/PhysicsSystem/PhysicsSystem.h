#pragma once

#include <immintrin.h>
#include <vector>

#include "src/playground/dod/PhysicsBody.h"
#include "src/playground/dod/PhysicsConfig.h"


struct Vector3s
{
public:
    std::vector<float> x;
    std::vector<float> y;
    std::vector<float> z;
};


class PhysicsSystem
{
public:

    auto update_bodies(
        const PhysicsConfig& config,
        std::vector<PhysicsBody>& bodies
    ) const -> void;

    auto update_bodies_2(
        const PhysicsConfig& config,
        const std::vector<PhysicsBody>& bodies
    ) const -> std::vector<PhysicsBody>;

    auto update_bodies_3(
        const PhysicsConfig& config,
        std::vector<Vector3>& positions,
        const std::vector<Vector3>& velocities
    ) const -> void;

    auto update_bodies_4(
        const PhysicsConfig& config,
        Vector3s& positions,
        const Vector3s& velocities
    ) const -> void;

};
