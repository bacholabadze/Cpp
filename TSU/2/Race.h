#include <iostream>
using namespace std;

const string unk = "unknown";

class Racer {
private:
	/*
	●	A string  - ცხენის სახელი
	●	A string - ჟოკეის სახელი
	●	A double - ცხენის წონა
	●	A double - ჟოკეის წონა
	●	An int - ცხენის ასაკი
	●	A char - ცხენის სქესი
	●	A bool for defeat (თუ ცხენი წააკებს დოღს)
	●	A bool for injured (თუ ცხენი დაშავდება დოღის დროს )
	●	A bool for allowed (თუ ცხენს ექნება უფლება მიიღოს მონაწილეობა შეჯიბრში)
	*/
	string horseName, racerName;
	double horseWeight, racerWeight;
	int horseAge;
	char horseSex;
	bool defeat, injured, allowed;

public:
	/* ●	Default Constructor */
	Racer();

	/* ●	Explicit value constructor - რომელსაც გადასცემთ ცხენის და ჟოკეის სახელებს, მათ წონას, ცხენის ასაკსა და სქესს. */
	Racer(string nameHorse, string nameRacer, double weightHorse, double weightRacer, int ageHorse);


	/* ●	ბეჭდვის ფუნქცია რომელიც გამოიტანს racer-ის ატრიბუტებს. */
	void display(ostream& out) const;

	/* ცხენის ატრიბუტების წასაკითხად */
	void read(istream& in);


	/* ●	ფუნქცია რომელიც არაფერს აბრუნებს მაგრამ ზრდის ობიექტის ასაკს(ცხენის). */
	void age_me();
	void calculateAllowChances();
	void calculateInjuryChances();

	/* ●	Race ფუნქცია რომელიც სხვა racer ობიექტს იღებს პარამეტრად, ფუნქცია განკუთვნილია ორ ცხენს შორის გამარჯვებულის გამოსავლენად.*/
	void race(Racer& player2);

	/* ●	Racer კლასს აუცილებლად უნდა ჰქონდეს შესაბამისი მუტატორები და აქსესორები.*/
	void setHorseName(string newName);
	string getHorseName();
	void setRacerName(string newName);
	string getRacerName();
	unsigned getHorseAge();
};

//----- უპარამეტრო კონსტრუქტორი რომელიც შექმნის racer-ს, defeat და injured თავდაპირველად იქნება false, ხოლო allowed true
Racer::Racer() : horseName(unk), racerName(unk), horseWeight(100), racerWeight(50), horseAge(5), horseSex('Q'), defeat(false), injured(false), allowed(true) {
	puts("[!] Default Constructor");
}


//----- პარამეტრიანი კონსტრუქტორი. defeat და injured თავდაპირველად იქნება false, ხოლო allowed true
Racer::Racer(string nameHorse, string nameRacer, double weightHorse, double weightRacer, int ageHorse) {
	puts("[!] Constructor with Parameters");
	defeat = false;
	injured = false;
	allowed = true;

	horseName = nameHorse;
	racerName = nameRacer;
	horseWeight = weightHorse;
	racerWeight = weightRacer;
	horseAge = ageHorse;
	horseSex = 'Q';

	// თუ ცხენის ასაკი >= 13 დავითვალოთ მისი დოღზე დაშვების შანსი
	if (horseAge >= 13) Racer::calculateAllowChances();
}

//----- << and >> ოპერატორების გადატვირთვა
ostream& operator<<(ostream& out, const Racer& r) {
	r.display(out);
	return out;
}
istream& operator<< (istream& in, Racer& r);

//----- display იმპლემენტაცია
void Racer::display(ostream& out) const {
	out << "Cxenis Saxeli: " << horseName
		<< "\nJokeis Saxeli: " << racerName
		<< "\nCxenis Wona: " << horseWeight
		<< "\nCxenis Asaki: " << horseAge
		<< "\nCxenis Sqesi: " << horseSex
		<< "\nWagebuli: " << defeat
		<< "\nDashavebuli: " << injured
		<< "\nDashvebuli: " << allowed;
}

//----- read იმპლემენტაცია
void Racer::read(istream& in) {
	string newHorseName, newRacerName;
	in >> newHorseName >> newRacerName;
}

//---- ფუნქცია age_me ზრდის ობიექტის ასაკს (ცხენის). 
void Racer::age_me() {
	Racer::horseAge += 1;
	cout << "[!] Cxeni Berdeba + 1 Wlit {" << Racer::horseAge << "}\n";
	Racer::calculateAllowChances();
}

void Racer::race(Racer& player2) {
	cout << "Pirveli aris " << Racer::racerName << endl;
	cout << "Meore aris " << player2.racerName << endl;

	if ((!Racer::allowed) || (!player2.allowed)) {
		cout << "Doghi Ver Shedgeba, Erterti Cxeni Ar Aris Dashvebuli.";
	}
	else {
		Racer::calculateInjuryChances();
		player2.calculateInjuryChances();
		if (Racer::injured && (!player2.injured)) {
			cout << Racer::horseName << " Cxeni Dashavda, Avtomaturad Moigo " << player2.horseName << endl;
			Racer::defeat = true;
		}
		else if ((!Racer::injured) && player2.injured) {
			cout << player2.horseName << " Cxeni Dashavda, Avtomaturad Moigo " << Racer::horseName << endl;
			player2.defeat = true;
		}
		else if (Racer::injured && player2.injured) {
			cout << "Orive Cxeni Dashavda!! Doghi Ver Shedga.";
		}
		else {
			int fight_ratio = ((Racer::horseWeight + player2.horseWeight) / (Racer::racerWeight + player2.racerWeight)) * 50;
			int tmp = rand() % 100;
			//cout << "??? " << tmp << " ???" << fight_ratio << endl;

			if (fight_ratio > tmp) {
				cout << "[+] Moigo " << Racer::horseName << " !!!\n";
				player2.defeat = true;
			}
			else if (tmp > fight_ratio) {
				cout << "[+] Moigo " << player2.horseName << " !!!\n";
				Racer::defeat = true;
			}
			else {
				cout << "Saswaulebrivad Orivem Ertdroulad Gadakveta Finishis Xazi :)\n";
			}
		}
	}
}

/* თუ მრბოლელი ცხენის ასაკი 6 წელზე ნაკლებია, მაშინ შანსი იმისა რომ ის დოღის დროს დაშავდება არის 25%,
თუ ასაკი 6დან 13წლამდეა მაშინ დაშავების შანსები 3%-მდე მცირდება. */
void Racer::calculateInjuryChances() {
	if (Racer::horseAge < 6 && Racer::allowed) {
		int tmp = rand() % 100;
		if (tmp < 25) Racer::injured = true;
		else Racer::injured = false;
	}
	else if (Racer::horseAge < 13 && Racer::allowed) {
		int tmp = rand() % 100;
		if (tmp < 3) Racer::injured = true;
		else Racer::injured = false;
	}
	if (Racer::injured) Racer::allowed = false;
}

/*	შანსი იმისა რომ 13 წელს გადაცილებულ ცხენებს შეჯიბრებაზე არ დაუშვებენ 80%-ია,
	ასევე უნდა გაითვალისწინოთ რომ დაშავებული ცხენებიც არ დაიშვებიან დოღზე.	*/
void Racer::calculateAllowChances() {
	if (Racer::horseAge >= 13 && Racer::allowed) {
		int tmp = rand() % 100;
		if (tmp < 80) {
			Racer::allowed = false;
			cout << "[!] Cxens Asakis Gamo Aghar Daushveben Doghze!!! \n";
		}
		else Racer::allowed = true;
	}
	if (Racer::injured) Racer::allowed = false;
}

//------------------------------- აქსესორები
unsigned Racer::getHorseAge() {
	return horseAge;
}

string Racer::getHorseName() {
	puts("[!] Getter");
	return horseName;
}

string Racer::getRacerName() {
	puts("[!] Getter");
	return racerName;
}

// ------------------------------ მუტატორები
void Racer::setHorseName(string newName) {
	puts("[!] Setter");
	horseName = newName;
}

void Racer::setRacerName(string newName) {
	puts("[!] Setter");
	racerName = newName;
}

