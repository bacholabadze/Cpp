/* BaseFish.h ----------------------------------------------------
   Header file for a class BaseFish.
   Contains General Attributes of the fish like:
   1. Weight
   2. Hearts
   3. Age
   4. Sex
   5. Alive

   Available Methods:
   1. isAlive()
   2. ageFish()
   3. display()
   4. getWeight()
   ----------------------------------------------------------------------*/

#ifndef BASEFISH
#define BASEFISH

#include <iostream>
#include <string>
class BaseFish {
public:
    BaseFish(double weight = 0.1, short hearts = 10, short age=1, std::string sex = "Female", bool alive = 1);
    /*-----------------------------------------------------------------------
      BaseFish constructor.
      Preconditions:  None.
      Postconditions: Every Fish has weight, hearts (Life expectancy), age, sex, status (Dead or alive).
     -----------------------------------------------------------------------*/
    
    int isAlive();
    /*-----------------------------------------------------------------------
    Returns 1 if fish is alive, 0 if dead.
    -----------------------------------------------------------------------*/

    int ageFish();
    /*-----------------------------------------------------------------------
    Increases Fish age by 1. if age>hearts fish dies.
    Returns increased fish's age.
    -----------------------------------------------------------------------*/

    double getWeight();
    /*-----------------------------------------------------------------------
    Returns the fish's weight value.
    -----------------------------------------------------------------------*/

    virtual void display(std::ostream& out) const;
    /*-----------------------------------------------------------------------
      Output function member.
      Precondition:  ostream out is open.
      Postcondition: A text representation of this BaseFish object has
          been output to out.
    ------------------------------------------------------------------------*/
    bool alive;     // Alive - 1, Dead - 0
private:
    double weight;   // Fish weight
    short hearts;   // Life Expectancy, if a fish age goes beyond hearts number, fishh will die.
    short age;      // Fish Age
    std::string sex;     // Fish sex (male or female)
};

//--- Definition of BaseFish's Constructor
inline BaseFish::BaseFish(double myweight, short myhearts, short myage, std::string mysex, bool myalive)
    :weight(myweight), hearts(myhearts), age(myage), sex(mysex), alive(myalive) {}

inline int BaseFish::isAlive() {
    return this->alive;
}

inline double BaseFish::getWeight() {
    return this->weight;
}

inline int BaseFish::ageFish() {
    if (this->alive) {
        this->age += 1;
        std::cout << "[+] The Fish aged, now "<<this->age<<" years old.\n";
        if (this->age > this->hearts-1)
            this->alive = 0;
        return this->age;
    }
    else {
        std::cout << "[!] The Fish is dead. Can't grow old.\n";
        return this->age;
    }
}

inline void BaseFish::display(std::ostream& out) const
{
    out << weight << " kg\n" << hearts << " Hearts <3\n" << age << " Years old\n" << sex << "\n" << "Is Alive? " << alive << std::endl;
}

//--- Definition of output operator <<
inline std::ostream& operator<<(std::ostream& out, const BaseFish& fish)
{
    fish.display(out);
    return out;
};

#endif
