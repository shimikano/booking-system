#include <string>
#include <iostream>

using namespace std;

class Airport {

  private:

    string id; // the 3 letter airport code
    string name; // human readable airport name

  public:

    Airport(string id, string name) : id(id), name(name) {}

    string getId() const {
      return id;
    }

    string getName() const {
      return name;
    }

    // we need to define the < operator to be able to have Airports sorted
    bool operator<(const Airport& other) const {
      return id < other.id; // just delegate to the id
    }

    // we need to define the == operator to be able to have Airport equality
    bool operator==(const Airport& other) const {
      return id == other.id; // just delegate to the id
    }

    // we overload the << operator to easily print to cout
    friend ostream& operator<< (ostream& os, const Airport& airport) {
      os << "[" << airport.id << "] " << airport.name;

      return os;
    }

};
