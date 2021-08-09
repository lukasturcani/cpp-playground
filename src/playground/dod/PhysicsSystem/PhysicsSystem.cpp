#include "src/playground/dod/PhysicsSystem/PhysicsSystem.h"


auto PhysicsSystem::update_bodies(
    const PhysicsConfig& config,
    std::vector<PhysicsBody>& bodies
) const -> void
{
    for (auto& body : bodies)
    {
        body.position.x += body.velocity.x * config.time_step.value;
        body.position.y += body.velocity.y * config.time_step.value;
        body.position.z += body.velocity.z * config.time_step.value;
    }
}

auto PhysicsSystem::update_bodies_2(
    const PhysicsConfig& config,
    const std::vector<PhysicsBody>& bodies
) const -> std::vector<PhysicsBody>
{
    std::vector<PhysicsBody> result {};
    result.reserve(bodies.size());
    for (auto& body : bodies)
    {
        result.emplace_back(
            Vector3 {
                body.position.x
                    + body.velocity.x*config.time_step.value,
                body.position.y
                    + body.velocity.y*config.time_step.value,
                body.position.z
                    + body.velocity.z*config.time_step.value,
            },
            Vector3 {
                body.velocity.x,
                body.velocity.y,
                body.velocity.z,
            }
        );
    }
    return result;
}


auto PhysicsSystem::update_bodies_3(
    const PhysicsConfig& config,
    std::vector<Vector3>& positions,
    const std::vector<Vector3>& velocities
) const -> void
{
    for (std::size_t i { 0 }; i < positions.size(); ++i)
    {
        auto& position { positions.at(i) };
        const auto& velocity { velocities.at(i) };
        position.x += velocity.x * config.time_step.value;
        position.y += velocity.y * config.time_step.value;
        position.z += velocity.z * config.time_step.value;
    }
}
