#include <cstdlib>


template<typename T>
class AlignedAllocator
{
public:

    AlignedAllocator() = delete;
    AlignedAllocator(
        std::size_t alignment
    )
        : _alignment { alignment }
    {}

    T* allocate(std::size_t num_objects)
    {
        return reinterpret_cast<T*>(
            std::aligned_alloc(_alignment, num_objects)
        );
    }

    void deallocate(void* memory)
    {
        std::free(memory);
        memory = nullptr;
    }
private:
    std::size_t _alignment;
};
