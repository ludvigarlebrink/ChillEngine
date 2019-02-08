/**
 * @file     MemoryManager.hpp
 * @author   Marek Cernak
 * @date     2/8/2019
 *
 * @brief memory arena implementation
 */

// Example usage for debug/release configuration
//#if DEBUG || RELEASE
//typedef MemoryArena<LinearAllocator, SingleThreadPolicy, SimpleBoundsChecking, SimpleMemoryTracking, SimpleMemoryTagging> ApplicationArena;
//#else
//typedef MemoryArena<LinearAllocator, SingleThreadPolicy, NoBoundsChecking, NoMemoryTracking, NoMemoryTagging> ApplicationArena;
//#endif

template <class AllocationPolicy, class ThreadPolicy, class BoundsCheckingPolicy, class MemoryTrackingPolicy, class MemoryTaggingPolicy>
class MemoryArena 
{
public:
    template <class AreaPolicy>
    explicit MemoryArena(const AreaPolicy& area)
        : m_allocator(area.GetStart(), area.GetEnd())
    {
    }

    void* Allocate(size_t size, size_t alignment, const SourceInfo& sourceInfo)
    {
        m_threadGuard.Enter();

        const size_t originalSize = size;
        const size_t newSize = size + BoundsCheckingPolicy::SIZE_FRONT + BoundsCheckingPolicy::SIZE_BACK;

        char* plainMemory = static_cast<char*>(m_allocator.Allocate(newSize, alignment, BoundsCheckingPolicy::SIZE_FRONT));

        m_boundsChecker.GuardFront(plainMemory);
        m_memoryTagger.TagAllocation(plainMemory + BoundsCheckingPolicy::SIZE_FRONT, originalSize);
        m_boundsChecker.GuardBack(plainMemory + BoundsCheckingPolicy::SIZE_FRONT + originalSize);

        m_memoryTracker.OnAllocation(plainMemory, newSize, alignment, sourceInfo);

        m_threadGuard.Leave();

        return (plainMemory + BoundsCheckingPolicy::SIZE_FRONT);
    }

    void Free(void* ptr)
    {
        m_threadGuard.Enter();

        char* originalMemory = static_cast<char*>(ptr) - BoundsCheckingPolicy::SIZE_FRONT;
        const size_t allocationSize = m_allocator.GetAllocationSize(originalMemory);

        m_boundsChecker.CheckFront(originalMemory);
        m_boundsChecker.CheckBack(originalMemory + allocationSize - BoundsCheckingPolicy::SIZE_BACK);

        m_memoryTracker.OnDeallocation(originalMemory);

        m_memoryTagger.TagDeallocation(originalMemory, allocationSize);

        m_allocator.Free(originalMemory);

        m_threadGuard.Leave();
    }

private:
    AllocationPolicy m_allocator;
    ThreadPolicy m_threadGuard;
    BoundsCheckingPolicy m_boundsChecker;
    MemoryTrackingPolicy m_memoryTracker;
    MemoryTaggingPolicy m_memoryTagger;
};