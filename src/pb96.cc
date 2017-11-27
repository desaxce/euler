#include <iostream>
#include <string>
#include <deque>

using namespace std;

int grid[9][9];
int ngrid[9][9];
int count = 0;
int nx;
int ny;

void display() {
	cout << "nx = " << nx << " and ny = " << ny << endl;
	for (int i = 0; i < 9; ++i)  {
		for (int j = 0; j < 9; ++j) {
			cout << ngrid[i][j]<< " ";
		}
		cout << endl;
	}
}

int not_good(int i) {
	for (int j = 0; j < 9; ++j) {
		if (ngrid[nx][j]==i) {
			return 1;
		}
		if (ngrid[j][ny]==i) {
			return 1;
		}
	}
	for (int j = (nx/3)*3; j < (nx/3)*3 +3; ++j) {
		for (int k = (ny/3)*3; k < (ny/3)*3+3; ++k) {
			if (ngrid[j][k]==i) {
				return 1;
			}
		}
	}
	return 0;
}
int solve_cell() {
	//count++;
	//if (count < 20) {
	//	display();
	//	cout << endl;
	//}
	if (grid[nx][ny]==0) {
		int i = ngrid[nx][ny]+1;
		while (i<=9 and not_good(i)) {
			++i;
		}
		//if (nx == 6 and ny == 0) {
		//	cout << "i = " << i << endl;
		//}
		if (i<=9) {
			ngrid[nx][ny] = i;
			return 1;
		}
		else {
			ngrid[nx][ny] = 0;
			do {
				if (nx==0) {
					ny--;
					nx=8;
				}
				else {
					nx--;
				}
			} while (grid[nx][ny]!=0);
			return 0;
		}
	}
	return 1;
}

int solve() {
	while (nx < 9) {
		int r;
		do {
			r = solve_cell();
		} while (r!=1);

		nx++;
		if (nx==9) {
			nx = 0;
			ny++;
			if (ny==9) {
				//display();
				return 0;
			}
		}
	}
}

int main() {
	int result = 0;
	string line;
	for (int i = 0; i < 50; ++i) {
		getline(cin, line);
		for (int j = 0; j < 9; ++j) {
			getline(cin, line);
			for (int k = 0; k < line.length(); ++k) {
				grid[j][k] = line[k]-'0';
				ngrid[j][k] = line[k]-'0';
			}
		}
		nx = 0;
		ny = 0;
		solve();
		result += ngrid[0][0]*100+ngrid[0][1]*10+ngrid[0][2];
	}
	cout << result << endl;
	return 0;
}
