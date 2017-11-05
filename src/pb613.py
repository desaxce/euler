import sys

from math import *
from scipy import integrate
from scipy.integrate import dblquad 

a = 40
b = 30
epsilon = 1e-15
def theta(x, y):
	return (pi - atan(b/a) + atan(x/(a-y)) - atan(a/b) + atan(y/(b-x)))

def bounds_y():
	return [0, a]

def bounds_x(y):
	return [0, b-(b/a*1.0)*y]

def main(argv):
	print (integrate.nquad(theta, [bounds_x, bounds_y])[0]/600/2/pi)
	#print (dblquad(lambda x, y: pi - atan(b/a) + atan(x/(a-y)) - atan(a/b) + atan(y/(b-x)), 0, b-epsilon, lambda x: 0, lambda x: a- (a/b)*x))


if __name__ == "__main__":
	main(sys.argv[1:])
