/*
 * Código feito com a seguinte referencia de consulta: https://fabhodev.wordpress.com/2013/10/13/10191-longest-nap-uva-solution/comment-page-1/
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int h, m;
} Horario;

typedef struct {
	int h1,h2,m1,m2;
} Horas;

bool cmp(Horas a, Horas b) {
    if(a.h1 < b.h1) return true;
    if(a.h1 > b.h1) return false;
    if(a.m1<b.m1) return true;
    if(a.m1>b.m1) return false;
    if(a.h2 < b.h2) return true;
    if(a.h2 > b.h2) return false;
    if(a.m2<b.m2) return true;
    if(a.m2>b.m2) return false;
}

int main() {

	int s, dia = 0;

	while(cin >> s) {
		string str;
		Horario horario1, horario2, horarioAnt, maiorHorario;
		int maiorTempo = 0, minutos1, minutos2, dif;

		vector<Horas> v;

		horarioAnt.h = 10;
		horarioAnt.m = 0;

		// entrada de dados
		while(s--) {
			scanf("%d:%d %d:%d", &horario1.h, &horario1.m, &horario2.h, &horario2.m);
			getline(cin, str);

			Horas horas;
	        horas.h1 = horario1.h;
	        horas.m1=horario1.m;

	        horas.h2 = horario2.h;
	        horas.m2=horario2.m;

	        v.push_back(horas);
		}

	    sort(v.begin(), v.end(), cmp); // ordena as horas da agenda
	    for(int i = 0; i < v.size(); i++) {
			minutos1 = v[i].h1*60 + v[i].m1;
			minutos2 = horarioAnt.h*60 + horarioAnt.m;
			dif = minutos1 - minutos2;
			if(dif > maiorTempo) {
				maiorTempo  = dif;
				maiorHorario = horarioAnt;
			}
			horarioAnt.h = v[i].h2;
			horarioAnt.m = v[i].m2;
	    }
		minutos1 = 18*60;
		minutos2 = horarioAnt.h*60 + horarioAnt.m;
		dif = minutos1 - minutos2;
		if(dif > maiorTempo) {
			maiorTempo  = dif;
			maiorHorario = horarioAnt;
		}

		if(maiorTempo < 60) {
			cout << "Day #" << ++dia << ": the longest nap starts at " << maiorHorario.h << ":";
			maiorHorario.m < 10 ? cout << "0" << maiorHorario.m : cout << maiorHorario.m;
			cout << " and will last for " << maiorTempo << " minutes.\n";
		} else {
			cout << "Day #" << ++dia << ": the longest nap starts at " << maiorHorario.h << ":";
			maiorHorario.m < 10 ? cout << "0" << maiorHorario.m : cout << maiorHorario.m;
			cout << " and will last for " << maiorTempo/60 << " hours and " << maiorTempo%60 << " minutes.\n" ;
		}
	}

}