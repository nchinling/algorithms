#include <iostream>
#include <vector>
#include <algorithm>

long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

long first = 0, second = 0;
		for (int i = 0; i < n; i++)
		{
			if (numbers[i] > first)
			{
				second = first;
				first = numbers[i];
			}
			else if (numbers[i] > second)
			{
				second = numbers[i];
			}
		}
		return first*second;
}



int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}