#include<iostream>

using namespace std;

long long int to_lucky(int j, int n) {
	long long int r = 0;
	long long int multi = 1;
	for (int i = 0; i < n; i++) {
		r += (4 + 3 * (j & 1)) * multi;
		multi *= 10;
		j = j >> 1;
	}
	return r;
}

int main() {
	long long int l, r;
	cin >> l >> r;

	long long int s = 0;
	l--;
	for (int i = 1; i < 11; i++)
	for (int j = 0; j < (1 << i); j++) {
		long long int d = to_lucky(j, i);
		// cout << d << ' ' << l << ' ' << r << '\n';
		if (d >= l) {
			s += (min(d, r) - l) * d;
			l = min(d, r);
		}

		if (d >= r) { goto e; }
	}
	e:
	cout << s;
}
