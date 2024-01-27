def fibonacci_sum(n):
    if n <= 1:
        return n

    previous, current, _sum = 0, 1, 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        _sum += current

    return _sum % 10

def fibonacci_last_digit(n):
    current, next = 0, 1
    for _ in range(n):
        current, next = next, (current + next) % 10

    return current


if __name__ == '__main__':
    n = int(input())
    print((fibonacci_last_digit((n + 2) % 60) + 9) % 10)
