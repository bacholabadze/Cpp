/* BettaPallifina.h ----------------------------------------------------
   Header file for a class BettaPallifina derived from BaseFish that
   adds the attributes unique to BettaPallifina.
   Operations are:  A constructor and an output operation.
   ----------------------------------------------------------------------*/


#ifndef BETTAPALLIFINA
#define BETTAPALLIFINA

#include "BaseFish.h"
#include <iostream>

class BettaPallifina :public BaseFish {
public:
	BettaPallifina(double weight = 0.2, short hearts = 10, short age = 1, std::string sex = "Female", bool alive = 1);
	/*-----------------------------------------------------------------------
	 BettaPallifina constructor.
	 Preconditions:  None.
	 Postconditions: Data members weight, hearts, age, sex, alive are initialized by the BaseFish
	 constructor; mistreatment is 3. foodNeeded is weight*0.1
	-----------------------------------------------------------------------*/

	void eat(double foodQuantity);
	/*-----------------------------------------------------------------------
	Method gets food quantity and feeds fish.
	if food is not enough, it will decrease fish mistreatmentEndurance
	if mistreatmentEndurance hits zero, fish dies :(
	-----------------------------------------------------------------------*/

	short mistreatmentEndurance();
	/*-----------------------------------------------------------------------
	Returns how many mistreatment the fish can take
	-----------------------------------------------------------------------*/

	virtual void display(std::ostream& out) const;
	/*-----------------------------------------------------------------------
	  Output function member.
	  Precondition:  ostream out is open.
	  Postcondition: A text representation of this BettaPallifina
	  object has been output to out.
	 -----------------------------------------------------------------------*/

private:
	short mistreatment = 4;
	double foodNeeded = BaseFish::getWeight() * 0.1;
};

//--- Definition of BettaPallifina's Constructor
inline BettaPallifina::BettaPallifina
(double myweight, short myhearts, short myage, std::string mysex, bool myalive)
	:BaseFish(myweight, myhearts, myage, mysex, myalive) {}

//--- Definition of BettaPallifina's mistreatmentEndurance()
inline short BettaPallifina::mistreatmentEndurance() {
	return this->mistreatment;
}

//--- Definition of BettaPallifina's display()
inline void BettaPallifina::display(std::ostream& out) const
{
	BaseFish::display(out);            //inherited members
	out << "Endurance:" << mistreatment << "\nFood Needed: " << foodNeeded << std::endl;    //local members
}

//--- Definition of BettaPallifina's eat()
inline void BettaPallifina::eat(double foodQuantity) {
	if (this->isAlive() && mistreatment) {
		if (foodQuantity < this->foodNeeded) {
			mistreatment -= 1;
			std::cout << "\n[!] You've just misfed the fish, Be careful next time!\n\n";
		}
		else {
			std::cout << "[+] Om nom nom, Delicious!" << std::endl;
		}
		if (mistreatment <= 0) {
			BaseFish::alive = false;
			std::cout << "[!] The fish died :(" << std::endl;
		}
	}
	else {
		std::cout << "[!] The fish is dead. Can't eat" << std::endl;
	}
}

#endif
