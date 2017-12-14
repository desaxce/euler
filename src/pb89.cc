#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

int taille_minimum(int number) {
	int result = 0;

	result += number/1000;
	number = number%1000;

	result += 2*(number/900);
	number = number%900;

	result += number/500;
	number = number%500;

	result += 2*(number/400);
	number = number%400;

	result += number/100;
	number = number%100;
	
	result += 2*(number/90);
	number = number%90;

	result += number/50;
	number = number%50;

	result += 2*(number/40);
	number = number%40;

	result += number/10;
	number = number%10;

	result += 2*(number/9);
	number = number%9;

	result += number/5;
	number = number%5;

	result += 2*(number/4);
	number = number%4;

	result += number;

	return result;
}

int this_how_much_i_win(string numeral) {
	const char *s = numeral.c_str();
	int taille = (int) numeral.size();
	int number = 0;
	for (int i = 0; i < taille; ++i) {
		if (s[i] == 'M') {
			number += 1000;
		}
		else if (i < taille-1 and s[i] == 'C' and s[i+1] == 'M') {
			number += 900;
			i++;
		}
		else if (s[i] == 'D') {
			number += 500;
		}
		else if (i < taille-1 and s[i] == 'C' and s[i+1] == 'D') {
			number += 400;
			i++;
		}
		else if (s[i] == 'C') {
			number += 100;
		}
		else if (i < taille-1 and s[i] == 'X' and s[i+1] == 'C') {
			number += 90;
			i++;
		}
		else if (s[i] == 'L') {
			number += 50;
		}
		else if (i < taille-1 and s[i] == 'X' and s[i+1] == 'L') {
			number += 40;
			i++;
		}
		else if (s[i] == 'X') {
			number += 10;
		}
		else if (i < taille-1 and s[i] == 'I' and s[i+1] == 'X') {
			number += 9;
			i++;
		}
		else if (s[i] == 'V') {
			number += 5;
		}
		else if (i < taille-1 and s[i] == 'I' and s[i+1] == 'V') {
			number += 4;
			i++;
		}
		else if (s[i] == 'I') {
			number++;
		}
	}
	return taille - taille_minimum(number);
}

int main() {
    string numeral;
	int result = 0;
    while (cin>>numeral) {
		result += this_how_much_i_win(numeral);
    }
	cout << result << endl;
    return 0;
}
