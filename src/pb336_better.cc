#include <pe.h>
#define pb push_back
#define cl clear

int main() {
	const int n = 11;
	const int N = 2011;
	string start = "KJ";
	map<string, int> res; // because a map sorts the key alphabetically automatically!
	vector<string> current;
	res[start] = 1;
	
	for (int i = 2; i < n; ++i) {
		const char letter = (char) ('A'+n-1-i);
		current.cl();
		for (auto& kv : res) {
			current.pb(kv.first); // Use push_back here, not assignment via current[j], else program crashes with SEG FAULT
		}
		res.cl();
		for (int j = 0; j < current.size(); ++j) {
			string tmp = current[j];
			tmp.insert(tmp.begin(), letter);
			reverse(tmp.begin(), tmp.end());
			for (int k = 1; k < i; ++k) {
				string tmp1 = tmp;
				reverse(tmp1.begin()+k, tmp1.end());
				res[tmp1] = 1;
			}
		}
	}
	int count = 0;
	for (auto& kv : res) {
		if (++count==N) {
			cout << kv.first << endl;
			return 0;
		}
	}
	return 0;
}
