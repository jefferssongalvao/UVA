#include <iostream>
#include <cstdio>

using namespace std;

int calcIdade(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
	
	int idade = ano1 - ano2;

	if(mes2 > mes1) return --idade;
	else if(mes2 == mes1 && dia2 > dia1) return --idade;
	else return idade;

}

int main() {

	int t, cont = 0;
	cin >> t;

	while(t--) {


		int dia1, mes1, ano1, dia2, mes2, ano2;
		scanf("%d/%d/%d", &dia1, &mes1, &ano1);
		scanf("%d/%d/%d", &dia2, &mes2, &ano2);

		bool flag;
		if(ano2 > ano1) flag = false;
		else if(ano2 == ano1 && mes2 > mes1) flag = false;
		else if(ano2 == ano1 && mes2 == mes1 && dia2 > dia1) flag = false;
		else flag = true;

		if(!flag) 
			std::cout << "Case #" << ++cont << ": Invalid birth date" << std::endl;
		else {
			int idade = calcIdade(dia1, mes1, ano1, dia2, mes2, ano2);
			if(idade > 130)
				cout << "Case #" << ++cont << ": Check birth date" << endl;
			else
				cout << "Case #" << ++cont << ": " << idade << endl;
		}

	}

}