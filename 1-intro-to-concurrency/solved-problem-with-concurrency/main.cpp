#include <atomic>
#include <thread>
#include <iostream>

// using std::atomic lib, solves race conditions

std::atomic<int> counter{};

void count() {
    for (int i = 0; i < 1'000'000; i++) {
        counter += 1;
    }
}

int main() {
    std::thread t1{count};
    std::thread t2{count};

    t1.join();
    t2.join();

    std::cout << counter;

	return 0;
}