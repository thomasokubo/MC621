def main():
	MAX = 1000000007
	T, K = [int(i) for i in input().split()]
	fib = [1 for i in range(K)]
	for i in range(K, 100001):
		fib.append((fib[i - 1] + fib[i - K])%MAX)
	s = [0]
	for i in range(1,100001):
		s.append((s[i-1] + fib[i])%MAX)
	for t in range(T):
		a, b = [int(i) for i in input().split()]
		print((s[b] - s[a-1])%MAX)


main()
