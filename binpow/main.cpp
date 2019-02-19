#include <bits/stdc++.h>

using namespace std;

int binpow(int a, int n){
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow(a, n - 1) * a;
	else {
		int b = binpow(a, n / 2);
		return b * b;
	}
}

signed main(){
	int a, n;
	cin >> a >> n;
	cout << binpow(a, n);

	return 0;
}