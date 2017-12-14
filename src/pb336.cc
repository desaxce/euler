#include <pe.h>
#define pb push_back

int N = 2011;

int rotational_cost(string s, char c) {
	size_t pos = s.find(c);
	if (s.size()==2) {
		if (pos==1)
			return 1;
		return 0;
	}
	else {
		if (pos==0) { // si _c_ est au debut
			return rotational_cost(s.substr(1), ++c);
		}
		else if (pos==s.size()-1) { // si _c_ est a la fin
			reverse(s.begin(), s.end());
			return 1+rotational_cost(s.substr(1), ++c);
		}
		else { // si _c_ est au milieu
			reverse(s.begin()+pos, s.end());
			reverse(s.begin(), s.end());
			return 2+rotational_cost(s.substr(1), ++c);
		}
	}
}

int main() {
	string abcdefghijk("ABCDEFGHIJK");
	map<string, int> arrangements;
	vector<string> res;

	int maximum = 0;
	do {
		arrangements[abcdefghijk] = rotational_cost(abcdefghijk, 'A');
		if (arrangements[abcdefghijk]>maximum) {
			maximum = arrangements[abcdefghijk];
			res.clear();
		}
		if (arrangements[abcdefghijk]==maximum) {
			res.pb(abcdefghijk);
		}
	} while (next_permutation(abcdefghijk.begin(), abcdefghijk.end()));
	
	cout << res[N-1] << " : " << maximum << endl;
	return 0;
}
