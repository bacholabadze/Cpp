#include <iostream>
#include <queue>
using namespace std;

// Syntax:
// union [name] { member-list };
//
//union MyNumericalUnion {
//	int i;
//	double d;
//}
//
//int main(){
//	MyNumericalUnion mu;
//	mu.i = 42; // Holds int
//	mu.d = 3.1234; // Holds double
//}
///////////////////////////////////////////////////

enum class WeatherDataEnum {
	Temperature, Wind  // 0, 1
};

struct TemperatureData {
	int temperature;
	void display() {cout<<"Air Temperature: "<<temperature<<endl;}
};

struct WindData {
	double speed;
	int direction;
	void display() {cout<<"Wind Speed: "<<speed<<", direction: "<<direction<<endl;}
};

struct WeatherData {
	WeatherDataEnum type; // Discriminated Union
	union {
		TemperatureData temperature;
		WindData wind;
	};
};

void displayTempData(TemperatureData t) {t.display();}
void displayWindData(WindData w) {w.display();}

queue<WeatherData> weatherDataCollection;

void initializeWeatherData();

union xy {
	int x;
	double y;
};

int main(){
	xy u;
	u.x = 42;
	cout<<u.x<<endl;
	cout<<u.y<<endl<<endl; //  2.07508e-322 (garbage)

	u.y = 23.4;
	cout<<u.y<<endl<<endl;

	initializeWeatherData();

	while (!weatherDataCollection.empty()){
		WeatherData wd = weatherDataCollection.front();
		switch (wd.type){
			case WeatherDataEnum::Temperature:
				displayTempData(wd.temperature);
				break;
			case WeatherDataEnum::Wind:
				displayWindData(wd.wind);
				break;
			default:
				break;
		}
		weatherDataCollection.pop();
		cout<<"---"<<endl;
	}
	cout<<endl;
}

void initializeWeatherData(){
	WeatherData wd1, wd2, wd3;

	wd1.type = WeatherDataEnum::Temperature;
	wd1.temperature = {28};  // Temperature is 28 degrees celsius
	weatherDataCollection.push(wd1);

	wd2.type = WeatherDataEnum::Wind;
	wd2.wind = {7.3};  // WInd is 7.3 meters/second and [!] 0 (Default) degrees azimuth
	weatherDataCollection.push(wd2);

	wd3.type = WeatherDataEnum::Wind;
	wd3.wind = {5.4, 122};  // WInd is 7.3 meters/second and [!] 0 (Default) degrees azimuth
	weatherDataCollection.push(wd3);

}
