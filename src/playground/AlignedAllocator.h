#include <cstdlib>


template<typename T, unsigned int Alignment>
class AlignedAllocator
{
public:

    using pointer =  T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    AlignedAllocator() = default;

    auto allocate(std::size_t num_objects) -> T*
    {
        return reinterpret_cast<T*>(
            std::aligned_alloc(Alignment, num_objects)
        );
    }

    auto deallocate(void* memory, std::size_t num_objects) -> void
    {
        std::free(memory);
        memory = nullptr;
    }

    template<class U>
    struct rebind {
        using other = AlignedAllocator<U, Alignment>;
    };
};
