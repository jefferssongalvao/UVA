#include <iostream>
#include <string>

using namespace std;

int main() {

	string bin;

	for(int cont = 1; cin >> bin; cont++) {

		int casos;
		cin >> casos;
		int * n = new int[bin.size()];

		cout << "Case " << cont << ":\n";
		while(casos--) {
			int m, n;
			cin >> m >> n;
			if(m > n) {
				int aux = m;
				m = n;
				n = aux;
			}

			bool flag = true;
			int valor = bin[m];
			for(int i = m+1; i <= n; i++) {
				if(valor != (int) bin[i]) {
					cout << "No\n";
					flag = false;
					break;
				}
			}
			if(flag) cout << "Yes\n";
		}
	}
	return 0;
}