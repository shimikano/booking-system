#include <vector>
#include <algorithm> // for sort and unique

#include "flight.cpp"

using namespace std;

class BookingSystem {

  private:

    vector<Flight> flights;

  public:

    // adds a flight to this booking system
    void addFlight(const Flight& flight) {
      return flights.push_back(flight);
    }

    // returns all flights for a given origin airport
    const vector<Flight> getFlightsByOrigin(Airport origin) {
      vector<Flight> result;

      // loop through all flights and add the matching ones
      for (Flight flight: flights) {
        if (flight.getOrigin() == origin) {
          result.push_back(flight);
        }
      }

      return result;
    }

    // returns all available origin airports
    const vector<Airport> getOriginAirports() {
      vector<Airport> result;

      // loop through all flights and add the origin airport
      for (Flight flight: flights) {
        result.push_back(flight.getOrigin());
      }

      // remove duplicates: sort first, then erase the duplicates
      sort(result.begin(), result.end());
      result.erase(unique(result.begin(), result.end()), result.end());

      return result;
    }

};
