#include <string>
#include <iostream>

using namespace std;

class Airline {

  private:

    string name;

  public:

    Airline(string name): name(name) {}

    string getName() const {
      return name;
    }

    // we overload the << operator to easily print to cout
    friend ostream& operator<<(ostream& os, const Airline& airline) {
      os << airline.name;

      return os;
    }

};
