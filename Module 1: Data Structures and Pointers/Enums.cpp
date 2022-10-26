// Enums

// You can define a scoped enum or unscoped enum.

// Unscoped Enum:
// enum [identifier] [:type]
// {enum-list};

// Scoped Enum:
// enum [class|struct]
// [identifier] [:type]
// {enum-list};

#include <iostream>
#include <string>
using namespace std;

enum class Planet : std::uint8_t { // Eight bit unsigned int
    Mercury=1, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto
};

string getName(Planet planet) {
    switch(planet) {
        case Planet::Mercury: return "Mercury";
        case Planet::Venus: return "Venus";
        case Planet::Earth: return "Earth";
        case Planet::Mars: return "Mars";
        case Planet::Jupiter: return "Jupiter";
        case Planet::Saturn: return "Saturn";
        case Planet::Uranus: return "Uranus";
        case Planet::Neptune: return "Neptune";
        case Planet::Pluto: return "Pluto";
        default: return "Mystery";
    }
}

void flyTo(Planet planet){
    cout<< "Destination: " << getName(planet) << "... ";
    if(planet == Planet::Earth){  // Enumerator must be qualified
        cout<<"Already Here!"<<endl;
    }
    else{
        cout<<"Going to planet # "<< (int)planet << "..."<<endl;
    }
}

int main(){
    flyTo(Planet::Earth);
    flyTo(Planet::Mars);
    flyTo((Planet)20);
    return 0;
}
