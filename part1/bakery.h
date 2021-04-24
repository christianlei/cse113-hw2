#pragma once

#include <atomic>
#include <label.h>
using namespace std;

class mutex {
 public:
  mutex() {
    // Implement me!
  }
  
  void init (int num_threads) {
    this->num_threads = num_threads;
    this->flag = new atomic_bool[num_threads]();
    this->labels = new label[num_threads]();
    for (auto i = 0; i < num_threads; i++){
      this->flag[i] = 0;
      this->labels[i] = 0;
    }
  }
  
  void lock(int thread_id) {
    int k = 0;
    this->flag[thread_id] = true;
    label max_label = this->labels[0];
    for (auto i = 1; i < this->num_threads; i++){
      if (max_label < this->labels[i]){
        max_label = this->labels[i];
      }
    }
    this->labels[thread_id] = max_label;
    while((k!=thread_id && (this->flag[k] && (this->labels[k] < this->labels[thread_id] || (this->labels[k] == this->labels[thread_id] && k < thread_id ))))){};
  }
  
  void unlock(int thread_id) {
    this->flag[thread_id] = false;
  }

 private:
  atomic_bool* flag;
  label* labels;
  int num_threads;
};
