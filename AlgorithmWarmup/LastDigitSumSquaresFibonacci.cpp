#include <iostream>

int fibonacci_sum_squares_fast(long long n) {
    int pisano_period = 60;

    if (n <= 1)
        return n;

    n = n % pisano_period;

    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;
    int sum = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += (current * current) % 10;
        sum %= 10; 
    }

    return sum;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}