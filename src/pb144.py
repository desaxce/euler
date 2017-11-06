import sys

from math import sqrt

def main(argv):
	u = 19.7/1.4
	v = 1
	w = -10.1

	x = 1.4
	y = -9.6

	nombre_de_reflexion = 0

	xmin = x

	while abs(x) > 0.01 or y < 0:
		nombre_de_reflexion += 1

		a = -y/4/x
		b = 1
		c = -3*y/4

		aubv = a*u+b*v
		a2b2 = a**2+b**2
		u, v, w = u-2*a*aubv/a2b2, v-2*b*aubv/a2b2, w-2*c*aubv/a2b2
	
		u2 = u**2
		w2 = w**2
		v2 = v**2
	
		bb = 2*u*w/v2
		aa = 4+u2/v2
		cc = w2/v2-100
		delta = bb**2-4*aa*cc

		xplus = (-bb+sqrt(delta))/2/aa
		xmoins = (-bb-sqrt(delta))/2/aa
	
		#print (abs(xplus-x))
		#print (abs(xmoins-x))

		if abs(xplus-x) < 1e-9:
			x = xmoins
		else:
			x = xplus

		if abs(x) < abs(xmin):
			xmin = x
			print ("Nouvel xmin = ", xmin)
		y = -(w+u*x)/v
	
	print (nombre_de_reflexion)

if __name__ == "__main__":
	main(sys.argv[1:])
