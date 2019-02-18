#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
vector<int> vec[1001];
int matr[1001][1001];
int p[1001];
bool used[1001];
int INF = 1e9;

void deikstra(int v){
	for (int i = 0; i < 1001; i++){
		p[i] = INF;
		used[i] = false;
	}
	p[v] = 0;
	
	for (int j = 0; j < n; j++){
		int Min = INF + 1;
		int pos = -1;
		// Could be optimize by set or priority queue
		for (int i = 0; i < n; i++){
			if (Min > p[i] && !used[i]){
				Min = p[i];
				pos = i;
			}
		}
		if (pos == -1)
			break;
		used[pos] = true;
		for (int i = 0; i < vec[pos].size(); i++){
			p[i] = min(p[i], p[pos] + matr[pos][vec[pos][i]]);
		}
	}
}

signed main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int d1, d2, d3; // d1 -> d2 == d3
		cin >> d1 >> d2 >> d3;
		vec[d1].push_back(d2);
		vec[d2].push_back(d1);
		matr[d1][d2] = d3;
		matr[d2][d1] = d3;
	}
	int s;
	cin >> s;
	deikstra(s);
	for (int i = 0; i < n; i++){
		cerr << "s[" << i << "]: " << p[i] << '\n'; 
	}


	return 0;
}