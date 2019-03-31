/**
 * \brief
 */
#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include <thread>
#include <vector>

namespace delator {

/**
 * \brief
 */
class ThreadPool {
   public:
    /**
     * \brief Constructor.
     * \param pool_size
     */
    ThreadPool(const std::size_t pool_size);
     
    /**
     *
     */
    ~ThreadPool();

    // void EnqueueTask(Task task);

   private:
    std::vector<std::thread> pool_; //!<
    //std::vector<Task> task_list_;
};

}  // namespace delator

#endif  // THREAD_POOL_H_
