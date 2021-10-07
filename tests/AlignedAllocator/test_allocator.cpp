#include <vector>
#include "gtest/gtest.h"
#include "src/playground/AlignedAllocator.h"


TEST(AlignedAllocator, AllocationDeallocation)
{
    AlignedAllocator<float, 16> allocator;
    float* floats { allocator.allocate(32) };
    EXPECT_EQ(
        reinterpret_cast<std::size_t>(&(*floats)) % 16,
        0
    );
    allocator.deallocate(floats, 32);
}


TEST(AlignedAllocator, VectorAllocation)
{

    std::vector<float, AlignedAllocator<float, 16>> floats_one(
        32,
        12.f
    );
    std::vector<float, AlignedAllocator<float, 16>> floats_two(
        32,
        12.f
    );
    EXPECT_EQ(
        reinterpret_cast<std::size_t>(&floats_one.at(0)) % 16,
        0
    );
    EXPECT_EQ(
        reinterpret_cast<std::size_t>(&floats_two.at(0)) % 16,
        0
    );
}


auto main(int argc, char* argv[]) -> int
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
