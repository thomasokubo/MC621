def main():
	N, A = [int(i) for i in input().split()]
	city = [-1] + [int(i) for i in input().split()] + [-1]
	i, j = A, A
	qtd = 0
	if city[A] == 1:
		qtd+=1
	i-=1
	j+=1
	while city[i] != -1 and city[j] != -1:
		if city[i] + city[j] == 2:
			qtd+=2
		i-=1
		j+=1
	if city[i] == -1:
		while city[j] != -1:
			if city[j] == 1:
				qtd+=1
			j+=1
	elif city[j] == -1:
		while city[i] != -1:
			if city[i] == 1:
				qtd+=1
			i-=1
	print(qtd)


main()
