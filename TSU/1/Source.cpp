#include <iostream>
using namespace std;

/*
Funqcia pritanvs orobit sistemashi, gadakavs atobitidan

num - mimtitebeli anonimur cvladze int tipis, inaxavs atobit ricxvit mnishvnelobas
bitS - mimtitebeli anonimur cvladze int tipis inaxavs bitebis sistemas (mag 4/8/16/32)
*/
void decToBinary(int* num = new int, int* bitS = new int)
{
	// Size of an integer is assumed to be 32 bits
	for (int i = *bitS - 1; i >= 0; i--) {
		int k = *num >> i;
		if (k & 1)
			cout << "1";
		else
			cout << "0";
	}
}
/* 
Funqcia ighebs atobit ricxvs da bitis sistemis mnishvnelobas da scori tipis shemtxvevashi idzaxebs decToBinary funqcias
Bolos Ki atavisuflebs mexsirebas

num - mimtitebeli anonimur cvladze int tipis, inaxavs atobit ricxvit mnishvnelobas
bitS - mimtitebeli anonimur cvladze int tipis inaxavs bitebis sistemas (mag 4/8/16/32)
*/
int manipulator(){
	int *num = new int;
	cout << "Sheikvane Atobiti ricxvi:";
	cin >> *num;

	if ( *num<10 || *num>99) {
		cout << "Sheikvane Arauarkofiti Atobiti Ricxvi! \n";
		delete num;
		return 0;
	}

	int* bitSystem = new int;
	cout << "Sheikvane Bitis Sistema: ";
	cin >> *bitSystem;

	if (*bitSystem <= 0) {
		cout << "Sheikvane Scori Bitebis Sistema";
		delete bitSystem;
		delete num;
		return 0;
	}

	decToBinary(num, bitSystem);

	delete bitSystem;
	delete num;
	return 1;
}

int main() {
	manipulator();
	return 0;
}
