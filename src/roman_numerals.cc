#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

int main() {
    string numeral;
    while (cin>>numeral) {
        int number_i = 0;
        int number_v = 0;
        int number_x = 0;
        int number_l = 0;
        int number_c = 0;
        int number_d = 0;
        int number_m = 0;
        char *s = numeral.c_str();
        for (int i = numeral.size()-1; i > -1; --i) {
            if (s[i] == 'I') {
                number_i++;
            }
            else if (s[i] == 'V') {
                number_v++;
            }
            else if (s[i] == 'X') {
                number_x++;
            }
            else if (s[i] == 'L') {
                number_l++;
            }
            else if (s[i] == 'C') {
                number_c++;
            }
            else if (s[i] == 'D') {
                number_d++;
            }
            else if (s[i] =='M') {
                number_m++;
            }
        }
        result += this_how_much_i_win(number_i, number_v, number_x, 
                    number_l, number_c, number_d, number_m);
    }
    return 0;
}
