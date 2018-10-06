from sys import stdin

def main():
	b = 0
	t = [0,0]
	for line in stdin:
		t[b] = 0
		for i in line.split():
			t[b] *= 2
			t[b] += int(i)
		b = 1-b
		if (b == 0):
			#print(bin(t[0]), bin(t[1]))
			k = t[0] ^ t[1]
			#print(bin(k))
			if k == 31:
				print("Y")
			else:
				print("N")

main()
