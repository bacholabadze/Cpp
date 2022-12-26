#include <iostream>
#include <string>

#include "BaseFish.h"
#include "ClownFish.h"
#include "SiameseFightingFish.h"
#include "BettaPallifina.h"

using namespace std;

int main() {
	//BaseFish myFish;
	//cout << myFish.isAlive() << endl;
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//myFish.ageFish();
	//cout << myFish.isAlive() << endl;
	//cout << myFish << endl;
	// --------------------------------------------------

	cout << "-----------NEMO------------------" << endl;
	ClownFish nemo;
	nemo.ageFish();
	nemo.ageFish();
	cout << nemo<<endl;
	nemo.eat(0.02);
	cout << nemo << endl;
	cout << "----------------------------------" << endl;


	cout << "\n\n-----------NEMO'S Father----------" << endl;
	ClownFish nemoFather(0.7, 15, 8,"Male",true);
	nemoFather.ageFish();
	cout << nemoFather << endl;
	cout << "---------------------------------" << endl;


	cout << "\n-----------DYING NEMO------------" << endl;
	nemo.eat(0.02);
	nemo.eat(0.01);
	nemo.eat(0.01);
	nemo.eat(0.05);
	nemo.ageFish();
	cout << endl << nemo << endl;
	cout << "----------------------------------" << endl;

	cout << "\n\n-----------AGING NEMO'S Father----------" << endl;
	cout << nemoFather << endl;
	nemoFather.eat(2);
	nemoFather.eat(3);
	nemoFather.ageFish();
	nemoFather.ageFish();
	nemoFather.eat(0.01);
	nemoFather.ageFish();
	nemoFather.ageFish();
	nemoFather.ageFish();
	nemoFather.ageFish();
	nemoFather.ageFish();
	nemoFather.ageFish();
	cout << "---------------------------------" << endl;

	cout << "\n\n-----------Ninja-------------" << endl;
	SiamesaFightingFish ninja;
	cout << ninja << endl;
	ninja.ageFish();
	ninja.ageFish();
	ninja.eat(0.03);
	ninja.ageFish();
	ninja.eat(1);
	cout << "---------------------------------" << endl;

	cout << "\n\n-----------Sakura-------------" << endl;
	BettaPallifina sakura;
	cout << sakura << endl;
	sakura.ageFish();
	sakura.ageFish();
	sakura.eat(0.03);
	sakura.ageFish();
	sakura.eat(0.01);
	sakura.eat(0.01);
	sakura.eat(0.01);
	sakura.eat(0.01);
	sakura.eat(0.01);
	sakura.ageFish();
	cout << "---------------------------------" << endl;

}
