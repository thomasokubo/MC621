def main():
	N = int(input())
	string = "aabb"
	for i in range(N//4):
		print(string,end='')
	for i in range(N%4):
		print(string[i],end='')
	print("")


main()
