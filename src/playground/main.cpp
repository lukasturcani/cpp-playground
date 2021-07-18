#include <iostream>
#include <cstdlib>
#include <cstdint>

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

    std::uint64_t total { 0 };
    for (const auto& body : bodies)
    {
        total += body.position.x;
        total += body.position.y;
        total += body.position.z;
        total += body.velocity.x;
        total += body.velocity.y;
        total += body.velocity.z;
    }
    std::cout << total << std::endl;

    return EXIT_SUCCESS;
}
