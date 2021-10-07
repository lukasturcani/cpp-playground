#include "gtest/gtest.h"
#include "src/playground/AlignedAllocator.h"


TEST(AlignedAllocator, AllocationDeallocation)
{
    AlignedAllocator<float> allocator { 16 };
    float* floats { allocator.allocate(32) };
    EXPECT_EQ(
        reinterpret_cast<std::size_t>(&(*floats)) % 16,
        0
    );
    allocator.deallocate(floats);
}


auto main(int argc, char* argv[]) -> int
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
