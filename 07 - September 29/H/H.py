def cycle(G, K):
	path = [1]
	pos = [-1 for i in range(len(G) + 1)]
	while True:
		v = path[-1]
		pos[v] = len(path) - 1
		#print(path, v, G[v])
		for u in G[v]:
			if pos[u] == -1:
				path.append(u)
				break
			elif len(path) - pos[u] > K:
				return path[pos[u]::]

def main():
	N, M, K = [int(i) for i in input().split()]
	G = {i: set() for i in range(1, N+1)}
	for m in range(M):
		i, j = [int(i) for i in input().split()]
		G[i].add(j)
		G[j].add(i)
	path = cycle(G,K)
	print(len(path))
	temp = ' '.join(str(v) for v in path)
	#resp = temp[::len(temp)-1]
	print(temp)


main()
