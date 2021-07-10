#pragma once

#include <vector>

#include "src/playground/dod/PhysicsBody.h"
#include "src/playground/dod/PhysicsConfig.h"


class PhysicsSystem
{
public:

    auto update_bodies(
        const PhysicsConfig& config,
        std::vector<PhysicsBody>& bodies
    ) -> void;

};
