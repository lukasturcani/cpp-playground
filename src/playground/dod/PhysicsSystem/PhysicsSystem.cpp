#include "src/playground/dod/PhysicsSystem/PhysicsSystem.h"


auto PhysicsSystem::update_bodies(
    const PhysicsConfig& config,
    std::vector<PhysicsBody>& bodies
) const -> void
{
    const auto time_step { config.time_step.value };
    for (auto& body : bodies)
    {
        body.position.x += body.velocity.x * time_step;
        body.position.y += body.velocity.y * time_step;
        body.position.z += body.velocity.z * time_step;
    }
}

auto PhysicsSystem::update_bodies_2(
    const PhysicsConfig& config,
    const std::vector<PhysicsBody>& bodies
) const -> std::vector<PhysicsBody>
{
    std::vector<PhysicsBody> result {};
    result.reserve(bodies.size());
    const auto time_step { config.time_step.value };
    for (auto& body : bodies)
    {
        result.emplace_back(
            Vector3 {
                body.position.x
                    + body.velocity.x*time_step,
                body.position.y
                    + body.velocity.y*time_step,
                body.position.z
                    + body.velocity.z*time_step,
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
    const auto time_step { config.time_step.value };
    for (std::size_t i { 0 }; i < positions.size(); ++i)
    {
        auto& position { positions.at(i) };
        const auto& velocity { velocities.at(i) };
        position.x += velocity.x * time_step;
        position.y += velocity.y * time_step;
        position.z += velocity.z * time_step;
    }
}
