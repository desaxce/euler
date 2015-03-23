#include <pe.h>

int N = 2011;
map<string, int> memoiser;

int rotational_cost(string s, char c) {
	map<string, int>::iterator it = memoiser.find(s);
	if (it!=memoiser.end()) {
		return it->second;
	}
	else if (s.size()==2) {
		size_t pos = s.find(c);
		if (pos==1)
			return 1;
		return 0;
	}
	else {
		size_t pos = s.find(c);
		string ss = s;
		if (pos==0) { // si _c_ est au debut
			return rotational_cost(s.substr(1), ++c);
		}
		else if (pos==s.size()-1) { // si _c_ est a la fin
			reverse(s.begin(), s.end());
			return 1+rotational_cost(s.substr(1), ++c);
		}
		else { // si _c_ est au milieu
			//cout << s << endl;
			reverse(s.begin()+pos, s.end());
			//cout << s << endl;
			reverse(s.begin(), s.end());
			//cout << s << endl;
			memoiser[ss] = 2+rotational_cost(s.substr(1), ++c);
			return memoiser[ss];
		}
	}
}

int main() {
	string abcdefghijk("ABCDEFGHIJK");
	map<string, int> arrangements;
	int maximum = 0;
	do {
		arrangements[abcdefghijk] = rotational_cost(abcdefghijk, 'A');
		if (arrangements[abcdefghijk]>maximum) {
			maximum = arrangements[abcdefghijk];
		}
	} while (next_permutation(abcdefghijk.begin(), abcdefghijk.end()));
	cout << "Done" << endl;

	int count = 0;
	cout << "Maximum = " << maximum << endl;
	for (map<string, int>::const_iterator it = arrangements.begin(); it!=arrangements.end(); ++it) {
		if (it->second==maximum) {
			count++;
			if (count==N) {
				cout << it->first << " : " << it->second << endl;
				return 0;
			}
		}
	}
	return 0;
}
