import itertools

N = 100

def mod(k, n):
	modulo = k%n
	if modulo < 0:
		return modulo+n
	return modulo

S = [290797]
T = []
j = 1
while j < 2*N+1:
	S.append(mod(S[j-1]**2, 50515093))
	T.append(mod(S[j], 2000)-1000)
	j += 1

#print(T[0], T[1])
#print(T[2], T[3])
#print(T[4], T[5])

droites = []
droitesVerticales = []

for i in range(0, N):
	A = [T[2*i], T[2*i+1]]
	for j in range(i+1, N):
		B = [T[2*j], T[2*j+1]]
		if A[0] == B[0] and A[1] == B[1]:
			continue
		if A[0] != B[0]:
			c = (B[1]-A[1])/(B[0]-A[0])
			droites.append([c, A])
		else:
			droitesVerticales.append(A[0])

# Toutes les droites avec multiplicité
print("Nombre de droites avec multiplicité:", len(droites))

# Première méthode utilisée via itertools
# On se restreint aux droites distinctes
# Ne marche plus pour un grand N à cause d'erreurs de précision sur d
# droitesDistinctes = list(droites for droites,_ in itertools.groupby(droites))

# Deuxième méthod en gardant un point A(x,y) appartenant à la droite
# et non pas spécifiquement l'abscisse à l'origine (erreurs d'arrondis)

# Toutes les droites verticales avec multiplicité
print("Nombre de droites verticales avec multiplicité:", len(droitesVerticales))

# Restriction aux droites distinctes
droitesVerticalesDistinctes = list(set(droitesVerticales))
nombreDroitesVerticalesDistinctes = len(droitesVerticalesDistinctes)
print("Nombre de droites verticales distinctes:", nombreDroitesVerticalesDistinctes)

# On range les droites par coefficient directeur (avec multiplicité)
d = {}
for droite in droites:
	if droite[0] in d.keys():
		d[droite[0]].append(droite[1])
	else:
		d[droite[0]] = [droite[1]]

e = {}
nombreDroitesDistinctes = 0
# On ne garde que le nombre de droites distinctes
for c in d.keys():
	points = d[c]
	e[c] = len(points)
	for i in range(0, len(points)):
		for j in range(i+1, len(points)):
			if points[i][0] == points[j][0]: # C'est le même point
				e[c] -= 1
				break
			else:
				nouveauCoefficient = (points[j][1]-points[i][1])/(points[j][0]-points[i][0])
				if c == nouveauCoefficient: # i.e. les deux points sont sur la même droite
					e[c] -= 1
					break
	nombreDroitesDistinctes += e[c]

print("Nombre de droites distinctes: ", nombreDroitesDistinctes)

nombreTotalDeDroitesDistinctes = nombreDroitesDistinctes + nombreDroitesVerticalesDistinctes

S = 0
for c in e.keys():
	S += e[c]*(nombreTotalDeDroitesDistinctes-e[c])

S += nombreDroitesVerticalesDistinctes * nombreDroitesDistinctes

print("Nombre total de droites distinctes: ", nombreTotalDeDroitesDistinctes)
print("Nombre d'intersections:", S)
