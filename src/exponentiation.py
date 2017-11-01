import sys

minexp = [[set({1})], [set({1, 2})]]

def create_new():
	n = len(minexp)+1 # nouvel élément

	current_size = n # On commence avec n multiplication
	all_solutions = [set([i for i in range(1, n)])]

	for i in range(1, n // 2 + 1): # Seule la moitié nous intéresse
		for set1 in minexp[i-1]:
			for set2 in minexp[n-i-1]:
				temp = set1 | set2
				if len(temp) < current_size:
					all_solutions = [temp]
					current_size = len(temp)
				elif len(temp) == current_size:
					all_solutions.append(temp)

	for solution in all_solutions:
		solution.add(n)
	return all_solutions

def sol(n):
	i = 2 # Taille initiale du tableau minexp
	while i < n:
		minexp.append(create_new())
		i+=1

def main(argv):
	n = int(argv[0])
	sol(n) # On remplit le tableau minexp

	resultat = 0
	for i in range(1, n+1):
		resultat += len(minexp[i-1][0])-1

	print (resultat)

if __name__ == "__main__":
	main(sys.argv[1:])
