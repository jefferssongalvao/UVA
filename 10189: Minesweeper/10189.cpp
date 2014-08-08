#include <iostream>

using namespace std;

int main() {

	int n, m, cont = 1;

	cin >> n >> m;
	while(n != 0) {
		// Entradas
			char ** mat = new char *[n];
			for(int i = 0; i < n; i++) {
				mat[i] = new char[m];
				for(int j = 0; j < m; j++)
					cin >> mat[i][j];
			}
		// Saídas
			cout << "Field #" << cont++ << ":" << endl;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(mat[i][j] == '.') {
						int minas = 0;
						if(i > 0 && j > 0 && mat[i-1][j-1] == '*') minas++;
						if(i > 0 && mat[i-1][j] == '*') minas++;
						if(i > 0 && j < m-1 && mat[i-1][j+1] == '*') minas++;
						if(j > 0 && mat[i][j-1] == '*') minas++;
						if(mat[i][j+1] == '*') minas++;
						if(i < n-1 && j > 0 && mat[i+1][j-1] == '*') minas++;
						if(i < n-1 && mat[i+1][j] == '*') minas++;
						if(i < n-1 && j < m-1 && mat[i+1][j+1] == '*') minas++;
						cout << minas;
					} else {
						cout << mat[i][j];
					}
				}
				cout << endl;
			}
			cin >> n >> m;
	        if (n != 0) cout << endl;
	        for(int i=0; i < m; i++)
            	delete [] matriz[i];
			delete [] mat;
	}
}