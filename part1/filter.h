#pragma once

#include <atomic>
using namespace std;

class mutex {
 public:
  mutex() {

  }

  void init (int num_threads) {
    this->num_threads = num_threads;
    level = new atomic_int[num_threads]();
    for (auto i = 0; i < num_threads; i++) {
      level[i] = 0;
    }
    victim = new atomic_int[num_threads]();
  }
  
  void lock(int thread_id) {
    int k = 0;
    for (auto i = 0; i < this->num_threads; i++) {
        level[thread_id] = i;
        victim[i] = thread_id;
        while((k != thread_id) && (level[k] >= i && victim[i] == thread_id)) {};
    }
  }
  
  void unlock(int thread_id) {
    level[thread_id] = 0;
  }

 private:
  atomic_int* level;
  atomic_int* victim;
  int num_threads;
};
