#include <immintrin.h>

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


auto PhysicsSystem::update_bodies_4(
    const PhysicsConfig& config,
    Vector3s& positions,
    const Vector3s& velocities
) const -> void
{
    const auto time_step { config.time_step.value };
    __m256 simd_time_step {
        _mm256_setr_ps(
            config.time_step.value,
            config.time_step.value,
            config.time_step.value,
            config.time_step.value,
            config.time_step.value,
            config.time_step.value,
            config.time_step.value,
            config.time_step.value
        )
    };
    for (std::size_t i { 0 }; i+8 < positions.x.size(); i += 8)
    {
        __m256 simd_velocities { _mm256_load_ps(&velocities.x.at(i)) };
        __m256 simd_displacements {
            _mm256_mul_ps(simd_velocities, simd_time_step)
        };
        __m256 simd_positions { _mm256_load_ps(&positions.x.at(i)) };
        __m256 simd_new_positions {
            _mm256_add_ps(simd_positions, simd_displacements)
        };
        _mm256_store_ps(&positions.x.at(i), simd_new_positions);
    }
    for (std::size_t i { 0 }; i < positions.y.size(); i += 8)
    {
        auto& y_position { positions.y.at(i) };
        const auto& y_velocity { velocities.y.at(i) };
        y_position += y_velocity*time_step;
    }
    for (std::size_t i { 0 }; i < positions.z.size(); i += 8)
    {
        auto& z_position { positions.z.at(i) };
        const auto& z_velocity { velocities.z.at(i) };
        z_position += z_velocity*time_step;
    }
}
