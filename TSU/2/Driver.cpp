#include <iostream>
#include "Racer.h"
using namespace std;


int main() {
	srand(time(0));
	cout << "0) Racer Class Gamodzaxeba Uparametro Konstruqtorit: \n\n";
	
	Racer vighac;
	cout << vighac << endl << endl<< endl;

	cout << "1) Racer Gamodzaxeba Parametriani Konstruqtorit: \n\n";
	Racer bacho("Bucefali", "Bacho", 150, 70, 12);
	cout << bacho << endl << endl << endl;

	cout << "2) Racer Gamodzaxeba Setteris Shemdeg: \n\n";
	bacho.setHorseName("Ferrari");
	bacho.setRacerName("Beka");
	cout << bacho << endl << endl << endl;

	cout << "3) Racer Getterebis Gamokeneba: \n\n";
	cout << bacho.getHorseName() << endl;
	cout << bacho.getRacerName() << endl << endl << endl;

	cout << "4) Racer 'Age Me' Funqciis Gamokenebamde: \n";
	cout << bacho.getHorseAge() << endl;

	cout << "Racer 'Age Me' Funqciis Gamokenebis Shemdeg: \n";
	bacho.age_me();
	cout << bacho << endl << endl ;
	bacho.age_me();
	bacho.age_me();
	cout << bacho << endl << endl << endl;

	cout << "5) Gavushvat Cxenebi Doghze: \n";
	cout << bacho << endl << endl;
	cout << vighac << endl << endl;
	bacho.race(vighac);

	cout << "\n\n6) Gavushvat Sxva Cxenebi Doghze: \n";
	Racer a ("Lamborgini", "Gio", 120, 90, 6);
	Racer b("Tetra", "Vaja", 140, 100, 9);
	cout << a << endl << endl;
	cout << b << endl << endl;
	a.race(b);
}
