pete = (z+z^2+z^3+z^4)^9;
colin = (z+z^2+z^3+z^4+z^5+z^6)^6;
w = sum(i = 1, 36, polcoeff(pete, i)*sum(j = 1, i-1, polcoeff(colin, j)));
t = sum(i = 1, 36, polcoeff(pete, i)*sum(j=1, 36, polcoeff(colin, j)));
proba = w/t*1.0;
