/* SiamesaFightingFish.h ----------------------------------------------------
   Header file for a class SiamesaFightingFish derived from BaseFish that
   adds the attributes unique to SiamesaFightingFish.
   Operations are:  A constructor and an output operation.
   ----------------------------------------------------------------------*/


#ifndef SIAMESAFIGHTINGFISH
#define SIAMESAFIGHTINGFISH

#include "BaseFish.h"
#include <iostream>

class SiamesaFightingFish :public BaseFish {
public:
	SiamesaFightingFish(double weight = 0.4, short hearts = 12, short age = 1, std::string sex = "Male", bool alive = 1);
	/*-----------------------------------------------------------------------
	 SiamesaFightingFish constructor.
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
	  Postcondition: A text representation of this SiamesaFightingFish
	  object has been output to out.
	 -----------------------------------------------------------------------*/

private:
	short mistreatment = 1;
	double foodNeeded = BaseFish::getWeight() * 0.1;
};

//--- Definition of SiamesaFightingFish's Constructor
inline SiamesaFightingFish::SiamesaFightingFish
(double myweight, short myhearts, short myage, std::string mysex, bool myalive)
	:BaseFish(myweight, myhearts, myage, mysex, myalive) {}

//--- Definition of SiamesaFightingFish's mistreatmentEndurance()
inline short SiamesaFightingFish::mistreatmentEndurance() {
	return this->mistreatment;
}

//--- Definition of SiamesaFightingFish's display()
inline void SiamesaFightingFish::display(std::ostream& out) const
{
	BaseFish::display(out);            //inherited members
	out << "Endurance:" << mistreatment << "\nFood Needed: " << foodNeeded << std::endl;    //local members
}

//--- Definition of SiamesaFightingFish's eat()
inline void SiamesaFightingFish::eat(double foodQuantity) {
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
