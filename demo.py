def fibonacci(n):
    """Generate Fibonacci sequence up to n terms (0-based): returns list of length n"""
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    
    fib_sequence = [0, 1]
    for i in range(2, n):
        fib_sequence.append(fib_sequence[i-1] + fib_sequence[i-2])
    
    return fib_sequence

def fib_n(n):
    """Return Fibonacci number F(n) with F(0)=0, F(1)=1 (matches C function)"""
    if n <= 0:
        return 0
    a = 0
    b = 1
    for _ in range(n):
        a, b = b, a + b
    return a

if __name__ == "__main__":
    terms = 10
    seq = fibonacci(terms)
    print(f"Fibonacci sequence ({terms} terms): {seq}")
    # Direct F(n) requests
    print(f"fib_n(10) -> {fib_n(10)}")        # prints 55 (F(10))
    print(f"last element of fibonacci(11) -> {seq[-1]}")  # also 55
    # Example showing the off-by-one when requesting 10 terms:
    seq10 = fibonacci(10)
    print(f"fibonacci(10) last -> {seq10[-1]} (this is F(9))")

