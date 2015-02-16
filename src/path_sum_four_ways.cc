#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>
#include <unordered_map>
#include <queue>

#define MIN(a, b)   ((a) < (b) ? (a): (b))
#define N 80 
#define BILLION 1000000000

using namespace std;

// Modified input file (replaced commas with spaces, cause it's easier to parse this way)

deque<deque<int> > matrix(N);
deque<deque<int> > graph(N*N);

struct compare {
	bool operator()(const int& l, const int& r) {
		return l > r;
	}
};

int dijkstra() {
	queue<int> f;
	f.push(0);
	int result = BILLION;
	int mark[N*N];
	int distance[N*N];

	for (int i = 0; i < N*N; ++i) {
		mark[i] = 0;
		distance[i] = BILLION;
	}
	distance[0] = matrix[0][0];

	while (!f.empty()) {
		int s = f.front();
		f.pop();
		mark[s] = 1;

		for (int i : graph[s]) {
			if (!mark[i]) {
				distance[i] = distance[s]+matrix[i/N][i%N];
				f.push(i);
				mark[i] = 1;
			}
			else if (distance[i] > distance[s]+matrix[i/N][i%N]) {
				distance[i] = distance[s]+ matrix[i/N][i%N];
				f.push(i); // We add this to make sure that all distances are well updated
			}
		}
	}
	return distance[N*N-1];
}

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			deque<int> neighbors;
			if (i==0) {
				if (j==0) {
					neighbors.push_back(1);
					neighbors.push_back(N);
				}
				else if (j==N-1) {
					neighbors.push_back(N-2);
					neighbors.push_back(2*N-1);
				}
				else {
					neighbors.push_back(j+1);
					neighbors.push_back(j-1);
					neighbors.push_back(N+j);
				}
			}
			else if (i==N-1) {
				if (j==0) {
					neighbors.push_back(i*N+1);
					neighbors.push_back(i*N-N);
				}
				else if (j==N-1) {
					neighbors.push_back(N*i+j-1);
					neighbors.push_back(N*i+j-N);
				}
				else {
					neighbors.push_back(i*N+j+1);
					neighbors.push_back(i*N+j-1);
					neighbors.push_back(i*N+j-N);
				}
			}
			else {
				if (j==0) {
					neighbors.push_back(i*N+1);
					neighbors.push_back(i*N-N);
					neighbors.push_back(i*N+N);
				}
				else if (j==N-1) {
					neighbors.push_back(i*N+j-1);
					neighbors.push_back(i*N+j+N);
					neighbors.push_back(i*N+j-N);
				}
				else {
					neighbors.push_back(i*N+j+1);
					neighbors.push_back(i*N+j-1);
					neighbors.push_back(i*N+j+N);
					neighbors.push_back(i*N+j-N);
				}
			}
			graph[N*i+j] = neighbors;
		}
	}

	// call dijkstra on graph
	cout << dijkstra() << endl;
	return 0;
}

