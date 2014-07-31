#include <iostream>
#include <algorithm>
#define long long LL

using namespace std;

int main() {

	int i, j;
	
	while(cin >> i >> j) {
		int i_print = i;
		int j_print = j;

		if( i > j) swap (i, j);

		int max = 0;
		int cont;
		while(i <= j) {
			unsigned int n = i;
			cont = 1;
			while(n != 1) {
				if(n % 2 == 1) n = 3 * n + 1;
				else n /= 2;
				cont++;
			}
			if(cont > max) max = cont;
			i++;
		}
		cout << i_print << " " << j_print << " " << max << "\n";
	}

	return 0;

}