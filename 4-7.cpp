#include <cassert>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

queue<int> job_queue({ 12, 12, 18, 6, 3, 8, 9, 11, 21, 8, 8, 20, 7, 19, 6, 22, 8, 5, 6, 19, 4, 14, 15, 16, 14, 7, 18, 10, 8, 20, 7, 19, 1, 12, 20, 3, 5, 11, 1, 22, 21, 21, 23, 18, 8, 15, 3, 24, 9, 21, 23, 23, 3, 20, 24, 3, 5, 10, 9, 10, 20, 3, 8, 9, 7, 15, 8, 15, 20, 21, 6, 20, 16, 3, 21, 23, 7, 16, 7, 5, 15, 21, 11, 9, 12, 6, 9, 17, 5, 22, 1, 15, 1, 24, 10, 8, 15, 23, 18, 6, 17, 3, 15, 22, 17, 2, 19, 23, 1, 22, 10, 14, 9, 1, 9, 17, 23, 14, 12, 13, 15, 15, 6, 21, 1, 22, 9, 12, 17, 5, 5, 18, 11, 4, 15, 19, 5, 20, 23, 6, 13, 15, 19, 10, 14, 15, 10, 13, 15, 4, 24, 19, 4, 22, 7, 18, 14, 10, 20, 13, 22, 19, 24, 1, 17, 11, 20, 13, 5, 24, 17, 19, 18, 6, 3, 11, 10, 8, 17, 16, 16, 24, 19, 9, 12, 5, 9, 2, 1, 7, 12, 18, 2, 11, 10, 15, 14, 22, 13, 4, 19, 12, 13, 2, 14, 8, 23, 7, 2, 17, 5, 19, 11, 7, 14, 20, 1, 16, 9, 21, 2, 21, 3, 5, 24, 15, 17, 15, 20, 13, 9, 20, 22, 7, 1, 12, 13, 20, 6, 1, 12, 19, 9, 14, 20, 9, 16, 10, 8, 6, 24, 24, 4, 11, 7, 17, 10, 16, 22, 16, 12, 12, 7, 10, 17, 19, 5, 23, 11, 1, 22, 23, 16, 2, 5, 5, 7, 15, 13, 21, 14, 11, 19, 17, 2, 21, 19, 10, 18, 19, 21, 11, 7, 20, 9, 9, 1, 8, 7, 22, 2, 11, 11, 8, 10, 2, 24, 16, 6, 15, 18, 15, 20, 11, 2, 3, 3, 2, 3, 23, 23, 22, 23, 19, 14, 14, 8, 2, 21, 4, 14, 5, 10, 24, 14, 15, 10, 6, 8, 14, 17, 24, 20, 22, 23, 9, 3, 4, 10, 21, 18, 7, 3, 6, 16, 13, 1, 6, 24, 1, 20, 7, 5, 22, 13, 5, 8, 12, 18, 7, 24, 6, 2, 12, 12, 23, 10, 16, 3, 21, 21, 1, 10, 12, 12, 11, 20, 10, 8, 23, 14, 12, 10, 3, 21, 14, 11, 10, 4, 1, 9, 11, 1, 4, 18, 17, 3, 18, 22, 15, 9, 15, 24, 11, 21, 24, 20, 20, 13, 24, 10, 19, 9, 4, 15, 22, 20, 20, 17, 19, 10, 10, 21, 11, 10, 8, 20, 8, 21, 7, 19, 8, 20, 10, 7, 4, 13, 9, 23, 23, 15, 13, 12, 21, 3, 6, 13, 1, 18, 22, 20, 7, 24, 3, 20, 12, 22, 4, 15, 4, 5, 10, 9, 15, 10, 19, 14, 20, 9, 10, 5, 3, 2, 3, 7, 15, 24, 3, 2, 19, 18, 24, 8, 12, 14, 1, 7, 11, 3, 7, 20, 6, 17, 6, 7, 13, 12, 16, 15, 1, 21, 18, 24, 13, 18, 10, 19, 11, 12, 11, 17, 6, 17, 6, 8, 3, 12, 20, 4, 6, 6, 7, 12, 17, 5, 17, 13, 21, 16, 14, 10, 4, 11, 18, 9, 20, 12, 1, 10, 15, 20, 22, 24, 20, 12, 18, 17, 3, 24, 22, 24, 7, 17, 8, 23, 4, 2, 15, 21, 12, 18, 15, 4, 3, 15, 23, 14, 3, 9, 19, 11, 7, 17, 22, 22, 10, 21, 4, 14, 1, 8, 6, 12, 18, 13, 11, 10, 3, 21, 10, 24, 15, 17, 6, 22, 23, 17, 20, 19, 8, 10, 14, 9, 24, 24, 22, 8, 21, 16, 2, 19, 24, 8, 5, 3, 19, 23, 20, 16, 20, 21, 5, 14, 10, 4, 16, 21, 23, 17, 1, 17, 20, 4, 19, 24, 2, 12, 6, 17, 3, 6, 5, 3, 17, 19, 10, 1, 6, 4, 11, 3, 21, 3, 19, 22, 6, 23, 4, 18, 11, 15, 14, 5, 6, 13, 23, 18, 2, 7, 14, 14, 19, 18, 17, 10, 1, 13, 22, 9, 8, 2, 23, 16, 23, 1, 6, 1, 12, 1, 4, 10, 5, 1, 9, 24, 24, 13, 21, 7, 3, 20, 17, 4, 10, 12, 17, 1, 17, 10, 13, 1, 13, 17, 20, 3, 16, 4, 21, 17, 12, 5, 19, 1, 18, 17, 22, 22, 18, 1, 7, 22, 17, 18, 4, 6, 6, 19, 15, 14, 22, 2, 3, 22, 2, 1, 12, 2, 13, 8, 10, 24, 1, 11, 23, 8, 1, 15, 16, 18, 15, 8, 1, 8, 6, 15, 19, 19, 2, 23, 10, 7, 7, 14, 11, 2, 1, 2, 20, 7, 21, 16, 20, 10, 21, 15, 16, 5, 9, 3, 10, 19, 16, 15, 14, 7, 11, 3, 17, 16, 3, 5, 15, 7, 24, 18, 1, 11, 19, 10, 16, 20, 16, 24, 16, 17, 16, 7, 9, 14, 18, 16, 1, 9, 10, 5, 9, 22, 19, 17, 20, 16, 9, 22, 21, 14, 20, 10, 10, 4, 9, 11, 10, 24, 18, 22, 15, 9, 22, 3, 11, 20, 17, 2, 21, 19, 9, 13, 4, 23, 19, 8, 1, 10, 18, 8, 2, 21, 10, 21, 16, 7, 20, 19, 16, 23, 8, 22, 16, 11, 16, 10, 22, 18, 2, 20, 7, 1, 2, 2, 4, 6, 16, 17, 21, 9, 18, 17, 14, 10, 19, 8, 23, 2, 20, 1, 8, 7, 14, 22, 2, 12, 19, 14, 14, 10, 4, 7, 6, 9, 18, 5, 2, 4, 16, 17, 21, 17, 9, 10, 23, 11, 20, 22, 10, 20, 18, 20, 3, 7, 9, 9, 18, 13, 2, 15, 7, 20, 11, 3, 4, 7, 11, 20, 1, 12, 24, 12, 19, 12, 12, 13, 5, 1, 14, 6, 9, 24, 11, 20, 1, 3, 11, 2, 21, 6, 17, 12, 9, 10, 12, 24, 8, 16, 9, 9, 9, 16, 7, 15, 2, });

int do_job(int job_input, bool is_threaded_code = true) {
    static mutex output_lock;
    if (is_threaded_code) {
        this_thread::sleep_for(chrono::milliseconds(job_input));
        scoped_lock lock(output_lock);
        cout << "Thread " << this_thread::get_id() << " finished job with input: " << job_input << endl;
    }

    return (job_input * 1091) % 337; // create some dummy output
}

int example_run_jobs_sequentially() {
    int job_sum = 0;

    for (queue<int> job_queue_copy(job_queue);
            !job_queue_copy.empty();
            job_queue_copy.pop())

        job_sum += do_job(job_queue_copy.front(), false);

    return job_sum;
}

mutex job_queue_mutex;
mutex sum_mutex;

void worker(int& parallel_job_sum) {
    while (true) {
        int job = -1;

        {
            scoped_lock lock(job_queue_mutex);
            if (job_queue.empty()) {
                break;
            }
            job = job_queue.front();
            job_queue.pop();
        }

        int result = do_job(job);

        {
            scoped_lock lock(sum_mutex);
            parallel_job_sum += result;
        }
    }
}

int main() {
    /** 
     * Your task: create some threads to run the jobs in the jobQueue
     *
     * Psuedocode:
     * While there are still jobs in the jobQueue
     * Threads will grab a "job" (use .front() to see the job value, then use pop to remove it from the queue)
     * After grabbing a job, the thread will pass it to doJob and note the output
     * your code should print the sum of outputs from all the jobs
     *
     * You will need to create some variables and functions
     * You will need mutexes and scoped_locks to prevent threads from interfering with each other. (Don't use atomics)
     *
     * Syntax for creating a thread:
     * thread my_thread(my_function, arg1, arg2, ...)
     * This will create a thread with the name "my_thread". 
     * This thread will run the function "my_function" with arguments "arg1", "arg2", ....
     * You can create multiple threads that all run the same function
     * You may need to use pointers so that threads can modify variables
     * If you want to use aliases instead of pointers, you need to wrap that argument with std::ref when creating the thread.
     *
     * Remember to call .join()!
     * .join() waits for the thread to finish running
     */

    int example_sequential_sum = example_run_jobs_sequentially();
    cout << "Using the sequential code, the sum of outputs from all the jobs was: " << example_sequential_sum << endl;

    /** 
     * Start with 2 threads created manually. 
     * Once that's working, update your code to create a dynamic number of threads based on NUM_THREADS 
     * (use a vector to store the threads and .emplace_back() to create the threads)
    */
    const int NUM_THREADS = 32;
    int parallel_job_sum = 0;

    // YOUR CODE HERE (you may need to create a function though)
    vector<thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(worker, ref(parallel_job_sum));
    }

    for (auto& t : threads) {
        t.join();
    }

    assert(example_sequential_sum == parallel_job_sum);
    cout << "Finished successfully." << endl;
    cout << "Using the parallel code, the sum of outputs from all the jobs was: " << parallel_job_sum << endl;
}