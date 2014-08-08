#include <iostream>

using namespace std;

int main() {

	int n, b, h, w, p, a, menor, valor;
	bool flag;

	while(cin >> n >> b >> h >> w) {
		flag = false;
		menor = 0;
		while(h--) {
			cin >> p;
			for(int i = 0; i < w; i++) {
				cin >> a;
				if(a >= n) flag = true;
			}
			if(flag) {
				valor = n * p;
				if(menor != 0) {
					if(valor < menor) menor = valor;
				} else {
					menor = valor;
				}
			}
		}
		if(menor > 0 && menor < b) cout << menor << endl;
		else cout << "stay home" << endl;		

	}
}
