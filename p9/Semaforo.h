#ifndef __SEMAFORO__
#define __SEMAFORO__
#include <mutex>
#include <condition_variable>
class Semaforo {
private:
    std::mutex mutex_;
    std::condition_variable condition_;
    unsigned long count_; 
public:
    Semaforo(unsigned long = 0); 
    void post();
    void wait();
    void init(unsigned long);
};
#endif