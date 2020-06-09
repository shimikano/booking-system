#include <iostream>

#include "airport.cpp"
#include "airline.cpp"

using namespace std;

class Flight {

  private:

    Airport origin;
    Airport destination;
    Airline airline;
    long departureDateTime;

  public:

    Flight(Airport origin, Airport destination, Airline airline, long departureDateTime):
      origin(origin),
      destination(destination),
      airline(airline),
      departureDateTime(departureDateTime) {}

    Airport getOrigin() const {
      return origin;
    }

    Airport getDestination() const {
      return destination;
    }

    Airline getAirline() const {
      return airline;
    }

    long getDepartureDateTime() const {
      return departureDateTime;
    }

    // we overload the << operator to easily print to cout
    friend ostream& operator<<(ostream& os, const Flight& flight) {
      os << flight.origin.getId() << " --> " << flight.destination.getId() << " with " << flight.airline << " at " << flight.departureDateTime;

      return os;
    }

};
