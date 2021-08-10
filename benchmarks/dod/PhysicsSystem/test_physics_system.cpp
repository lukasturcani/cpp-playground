#include <vector>
#include <benchmark/benchmark.h>
#include <cstdint>

#include "src/playground/Vector3.h"
#include "src/playground/dod/PhysicsBody.h"
#include "src/playground/dod/PhysicsConfig.h"
#include "src/playground/dod/PhysicsSystem/PhysicsSystem.h"


auto get_physics_bodies(
    std::uint64_t num_bodies
) -> std::vector<PhysicsBody>
{
    std::vector<PhysicsBody> bodies {};
    for (std::uint64_t i { 0 }; i < num_bodies; ++i)
    {
        float number { static_cast<float>(i) };
        bodies.push_back(
            PhysicsBody {
                Vector3 { number, number, number },
                Vector3 { number, number, number },
            }
        );
    }
    return bodies;
}


auto get_vectors(
    std::uint64_t num_vectors
) -> std::vector<Vector3>
{
    std::vector<Vector3> vectors;
    for (std::uint64_t i { 0 }; i < num_vectors; ++i)
    {
        float number { static_cast<float>(i) };
        vectors.push_back(
            Vector3 { number, number, number }
        );
    }
    return vectors;
}


auto get_vector3s(
    std::uint64_t num_vectors
) -> Vector3s
{
    Vector3s vectors;
    for (std::uint64_t i { 0 }; i < num_vectors; ++i)
    {
        float number { static_cast<float>(i) };
        vectors.x.push_back(number);
        vectors.y.push_back(number);
        vectors.z.push_back(number);
    }
    return vectors;
}


static
auto benchmark_physics_system(benchmark::State& state) -> void
{


    std::vector<PhysicsBody> bodies {
        get_physics_bodies(state.range(0))
    };
    const PhysicsSystem physics_system {};
    const PhysicsConfig physics_config {
        Seconds { 1.f },
    };
    for (auto _ : state)
    {
        physics_system.update_bodies(physics_config, bodies);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(benchmark_physics_system)->Range(8, 8<<12)->Complexity();


static
auto benchmark_physics_system_2(benchmark::State& state) -> void
{


    std::vector<PhysicsBody> bodies {
        get_physics_bodies(state.range(0))
    };
    const PhysicsSystem physics_system {};
    const PhysicsConfig physics_config {
        Seconds { 1.f },
    };
    for (auto _ : state)
    {
        physics_system.update_bodies_2(physics_config, bodies);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(benchmark_physics_system_2)->Range(8, 8<<12)->Complexity();


static
auto benchmark_physics_system_3(benchmark::State& state) -> void
{


    std::vector<Vector3> positions { get_vectors(state.range(0)) };
    const std::vector<Vector3> velocities {
        get_vectors(state.range(0)),
    };
    const PhysicsSystem physics_system {};
    const PhysicsConfig physics_config {
        Seconds { 1.f },
    };
    for (auto _ : state)
    {
        physics_system.update_bodies_3(
            physics_config,
            positions,
            velocities
        );
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(benchmark_physics_system_3)->Range(8, 8<<12)->Complexity();


static
auto benchmark_physics_system_4(benchmark::State& state) -> void
{


    Vector3s positions { get_vector3s(state.range(0)) };
    const Vector3s velocities {
        get_vector3s(state.range(0)),
    };
    const PhysicsSystem physics_system {};
    const PhysicsConfig physics_config {
        Seconds { 1.f },
    };
    for (auto _ : state)
    {
        physics_system.update_bodies_4(
            physics_config,
            positions,
            velocities
        );
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(benchmark_physics_system_4)->Range(8, 8<<12)->Complexity();


BENCHMARK_MAIN();
