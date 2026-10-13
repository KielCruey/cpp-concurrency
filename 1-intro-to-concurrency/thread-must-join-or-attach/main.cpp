#include <thread>

int counter{};

void count() {
    for (int i = 0; i < 1'000'000; i++) {
        counter += 1;
    }
}

int main() {
    std::thread(count);
	return 0;
}