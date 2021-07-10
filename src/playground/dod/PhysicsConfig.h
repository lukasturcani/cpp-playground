#pragma once

#include "src/playground/Seconds.h"

struct PhysicsConfig
{
    PhysicsConfig() = delete;

    PhysicsConfig(Seconds time_step)
        : time_step { time_step }
    {}

    Seconds time_step;
};
