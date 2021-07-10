#include "src/playground/dod/PhysicsSystem/PhysicsSystem.h"


auto update_bodies(
    const PhysicsConfig& config,
    std::vector<PhysicsBody>& bodies
) -> void
{
    for (auto& body : bodies)
    {
        body.position.x += body.velocity.x * config.time_step.value;
        body.position.y += body.velocity.y * config.time_step.value;
        body.position.z += body.velocity.z * config.time_step.value;
    }
}
