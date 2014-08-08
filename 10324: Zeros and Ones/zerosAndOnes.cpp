/* 
 * Referência: http://online-judge.uva.es/board/viewtopic.php?f=20&t=1729&sid=6c2c3822904d057e418ccbcf74ac9aad&start=60
 * 
 * Toda solução que eu pensava acabava ultrapassando o tempo limite de 3s e no link acima encontrei uma dica de um usuário que recomendou
 * uma ideia de solução que eu segui. No caso, o programa lê o vetor e depois cria um outro vetor, de mesmo tamanho, e que cria uma
 * sequencia que "demarca" onde tem repetição. Por exemplo, com a entrada "0000011111", o array gerado é "1111122222", sendo assim
 * com apenas uma comparacao podemos determinar se toda a sequencia contem bits repetidos. Essa implementacao faz com que o programa
 * so percorra o vetor uma vez, ao contrario das minhas ideias que a cada teste o programa percorria o vetor contendo o numero.
 *
*/

#include <iostream>
#include <string>

int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a > b ? a : b; }

using namespace std;

int main() {

	int n, i, j, loopCounter;
	string numero;
	
	for(int count = 1; cin >> numero; count++) {
		int *v = new int[numero.size()];
		v[0] = 1;
		for(loopCounter = 1; loopCounter < numero.size(); loopCounter++) {
			if(numero[loopCounter] == numero[loopCounter-1])
				v[loopCounter] = v[loopCounter-1];
			else
				v[loopCounter] = v[loopCounter-1] + 1;
		}
		cin >> n;
		cout << "Case " << count << ':' << endl;
		while(n--) {
			cin >> i >> j;
			if(v[min(i, j)] == v[max(i, j)])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		delete [] v;
	}

	return 0;
}
