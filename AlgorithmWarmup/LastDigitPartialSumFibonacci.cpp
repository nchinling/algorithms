#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    int pisanoPeriod = 60; // Pisano period for modulo 10
    from = from % pisanoPeriod;
    to = to % pisanoPeriod;

    if (to < from) // Adjust for wrapping around the Pisano period
        to += pisanoPeriod;

    int previous = 0;
    int current = 1;
    int sum = 0;

    for (int i = 0; i <= to; ++i) {
        if (i >= from) {
            sum = (sum + previous) % 10;
        }
        int temp_previous = previous;
        previous = current;
        current = (temp_previous + current) % 10;
    }

    return sum;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}