#include <iostream>

using namespace std;

int main() {

	int k, n, m, x, y;

	while(cin >> k) {
		cin >> n >> m;
		while(k--) {
			cin >> x >> y;
			if(n == x || m == y) cout << "divisa\n";
			else if(n < x && m < y) cout << "NE\n";
			else if(n > x && m < y) cout << "NO\n";
			else if(n > x && m > y) cout << "SO\n";
			else cout << "SE\n";
		}
	}
}
