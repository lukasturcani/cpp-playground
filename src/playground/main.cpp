#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "src/playground/Vector3.h"
#include "src/playground/dod/PhysicsBody.h"
#include "src/playground/dod/PhysicsSystem/PhysicsSystem.h"


auto main() -> int
{
    std::vector<PhysicsBody> bodies {
        PhysicsBody {
            Vector3 { 0.f, 0.f, 0.f },
            Vector3 { 0.f, 0.f, 0.f },
        },
        PhysicsBody {
            Vector3 { 0.f, 0.f, 0.f },
            Vector3 { 0.f, 0.f, 0.f },
        },
    };
    const PhysicsSystem physics_system {};
    const PhysicsConfig physics_config {
        Seconds { 1.f },
    };
    physics_system.update_bodies(physics_config, bodies);

    const std::uint64_t size { 10'000'000 };
    PhysicsBody** bodies2 { new PhysicsBody*[size] };

    for (std::uint64_t i { 0 }; i < size; ++i)
    {
        bodies2[i] = new PhysicsBody {
            Vector3 {
                static_cast<float>(2*i),
                static_cast<float>(2*i),
                static_cast<float>(2*i),
            },
            Vector3 { 0.f, 0.f, 0.f },
        };
    }
    for (std::uint64_t i { 0 }; i < size; ++i)
    {
        (*(bodies2[
           rand() % size
        ])).position = Vector3 {
            static_cast<float>(i),
            static_cast<float>(i),
            static_cast<float>(i),
        };
    }
    return EXIT_SUCCESS;
}
