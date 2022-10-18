#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void sol();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	sol();
}

void sol() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n + 1);
	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vector<bool> visited(n + 1, true);
	queue<int> qe;
	vector<int> res;
	
	for(int i = 1; i < n + 1; i++) {
		if (visited[i]) {
			visited[i] = false;
			res.push_back(i);
			if (a[i].empty()) continue;

			qe.push(i);
			while (!qe.empty()) {
				int u = qe.front(); qe.pop();
				for(int v : a[u]) {
					if (visited[v]) {
						visited[v] = false;
						qe.push(v);
						res.push_back(v);
					}
				}
			}
		}
	}
	for(auto x : res) cout << x << endl;
}
