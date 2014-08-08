#include <iostream>

using namespace std;

int main() {
	int t, a, b, c, n = 1;

	cin >> t;
	while(n <= t) {

		cin >> a >> b >> c;

		cout << "Case " << n++ << ": ";

		if( (a > b && a < c) || (a > c && a < b) ) cout << a << endl;
		else if( (b > a && b < c) || (b > c && b < a) ) cout << b << endl;
		else cout << c << endl;
	}
}
