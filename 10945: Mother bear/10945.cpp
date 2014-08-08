#include <iostream>
#include <string>

using namespace std;

int main() {
	string frase;
	bool flag;

	while(getline(cin, frase) && frase != "DONE") {
		
		flag = true;

		string novaFrase;

	    for(int i = 0; i < frase.length(); i++) {
			if(isalpha(frase[i])) {
				novaFrase.push_back(tolower(frase[i]));
			}
		}

		for(int i = 0, j = novaFrase.length()-1; flag && (i < j); i++, j--) {
			if(novaFrase[i] != novaFrase[j]) flag = false;
		}

		if(flag)
			cout << "You won't be eaten!\n";
		else
			cout << "Uh oh..\n";
	}
}