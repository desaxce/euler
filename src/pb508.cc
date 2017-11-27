#include <pe.h>

ll D(ll L);
ll E(ll L);
ll C(ll L);
ll F(ll L);

ll modulo = 1e9L+7L;

ll mo(ll x) {
	ll tmp = x%modulo;
	return (tmp < 0) ? tmp + modulo: tmp;
}

ll modular_pow(ll base, ll exponent, ll modulus) {
	ll result = 1;
	while (exponent > 0) {
		if (exponent%2==1) {
			result = (result*base)%modulus;
		}
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

ll f(ll a, ll b) {
	if (a==0 and b==0) {
		return 0;
	}
	if (a%2==0) {
		if (b%2==0) {
			return f(-b/2, a/2);
		}
		else {
			return 2+f(-(b-1)/2, a/2);
		}
	}
	else {
		if (b%2==0) {
			return 1+f(-b/2, (a-1)/2);
		}
		else {
			return 1+f(-(b-1)/2, (a+1)/2);
		}
	}
}



ll B1(ll L) {
	ll result = 0;
	for (ll a = -L; a <= L; ++a) {
		for (ll b = -L; b <= L; ++b) {
			result+=f(a, b);
		}
	}
	return result;
}

ll v(ll a, ll L) {
	return mo(f((L+1)/2, a)+f((L+1)/2, a+1));
}

ll C(ll L) {
	if (L==0) {
		return 0;
	}
	else if (L==1) {
		return 6;
	}
	else if (L==-1) {
		return 9;
	}
	ll L_borne = abs(L);
	ll result = 0;
	if (L%2==0) {
		result = mo(result+L_borne+1-f(L_borne+1, L));
		result = mo(result+2*D(-L/2));
	}
	else {
		result += mo(3*L_borne+f(-L_borne, L));
		if (L>0) {
			result += mo(E(-(L-1)/2));
		}
		else {
			result += mo(E((L_borne+1)/2)-v(-(L_borne+1)/2, L_borne)-v((L_borne+1)/2, L_borne));
		}
	}
	//cout << "C("<<L<<") = "<<result << endl;;
	return mo(result);
}

ll u(ll a, ll L) {
	return mo(f(a, -(L+1)/2)+f(a, -(L-1)/2));
}

ll D(ll L) {
	if (L==0) {
		return 0;
	}
	else if (L==1) {
		return 8;
	}
	else if (L==-1) {
		return 7;
	}
	ll L_borne = abs(L);
	ll result = 0;
	if (L%2==0) {
		result += 2*(L_borne+1)-f(L, L_borne+1);
		result = mo(result+2*C(L/2));
	}
	else {
		result = mo(result+2*L_borne+f(L, -L_borne));
		if (L>0) {
			result = mo(result+F((L-1)/2));
		}
		else {
			result = mo(result+F(-(L_borne+1)/2)-u(-(L_borne+1)/2, L_borne)-u((L_borne+1)/2, L_borne));
		}
	}
	//cout << "D("<<L<<") = "<<result << endl;;
	return mo(result);
}

ll E(ll L) {
	ll L_borne = abs(L);
	ll result = 0;
	result = mo(result+2*D(L)+f(L, (L_borne+1))-f(L, -L_borne));
	//cout << "E("<<L<<") = "<<result << endl;;
	return mo(result);
}

ll F(ll L) {
	ll L_borne = abs(L);
	ll result = 0;
	result = mo(result+C(L)+C(L+1));
	if (L>=0) {
		result = mo(result-f(L_borne+1, L+1)-f(-L_borne-1, L+1));
	}
	else {
		result = mo(result+f(-L_borne, -L_borne+1)+f(L_borne, -L_borne+1));
	}
	//cout << "F("<<L<<") = "<<result << endl;
	return mo(result);
}

ll intermediaire(ll b, ll L) {
	return mo(f(b, (L+1)/2)+f(b, -(L+1)/2)+f((L+1)/2, b)+f((L+1)/2, b+1));
}

ll B2(ll L) {
	if (L==0) {
		return 0;
	}
	ll result = 0;
	if (L%2==0) {
		result = mo(result+4*B2(L/2));
		result = mo(result+4*mo(L+1)*mo(L+1));
		result = mo(result-5*(L+1));
		result = mo(result - (C(L/2)+C(-L/2)+E(-L/2)));
		/*for (ll b = -L/2; b <= L/2; ++b) {
			result -= f(b, L/2)+f(b, -L/2)+f(-L/2, b)+f(-L/2, b+1);
		}*/
		result = mo(result+f(L+1, L+1));
	}
	else {
		result = mo(result+4*mo(L)*mo(L));
		result = mo(result+5*L+4*B2((L-1)/2));
		result = mo(result+C((L+1)/2)+C(-(L+1)/2)+E((L+1)/2));
		result = mo(result-intermediaire(-(L+1)/2, L)-intermediaire((L+1)/2, L));
		/*for (ll b = -(L-1)/2; b <= (L-1)/2; ++b) {
			result += f(b, (L+1)/2)+f(b, -(L+1)/2)+f((L+1)/2, b)+f((L+1)/2, b+1);
		}*/
		result = mo(result+f(-L, -L));
	}
	return mo(result);
}


int main() {
	ll L;
	L = 1e15L;
	cout << B2(L) << endl;
	return 0;
}
