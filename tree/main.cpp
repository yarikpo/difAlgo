#include <bits/stdc++.h>

using namespace std;

int a[1000];
int t[4000];

void build(int v, int l, int r){
	if (l == r)
		t[v] = a[l];
	else {
		int m = (l + r) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m + 1, r);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

int sum (int v, int tl, int tr, int l, int r){
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum(v * 2, tl, tm, l, min(r, tm)) +
			sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int val){
	if (tl == tr)
		t[v] = val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos, val);
		else
			update(v * 2 + 1, tm + 1, tr, pos, val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 0, n - 1);


	return 0;
}