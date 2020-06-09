#include <iostream>

#include "booking_system.cpp"

using namespace std;

class CommandLineInterface {

  private:

    BookingSystem bookingSystem;

    // this method allows the user to interactively choose an element among the given choices;
    // this is a generic template method - it works for any kind of type T
    template<typename T>
    static T choose(vector<T> choices) {
      int selectedIndex = -1;

      cout << endl;

      do {
        // display the choices
        int i = 0; // we use zero-based indices
        for (T choice: choices) {
          cout << "  " << i++ << ": " << choice << endl;
        }

        cout << endl;

        cin >> selectedIndex; // read a number from the user
      } while (selectedIndex < 0 || selectedIndex >= choices.size()); // repeat until we get a valid selectedIndex

      cout << endl;

      return choices.at(selectedIndex); // return the element at the selectedIndex
    }

    void displayIntro() {
      cout << "== Welcome to the booking system ==" << endl << endl;
    }

  public:

    CommandLineInterface(BookingSystem bookingSystem): bookingSystem(bookingSystem) {}

    void start() {
      while (true) { // loop forever
        displayIntro();

        cout << "Please choose your airport of origin: " << endl;

        Airport origin = choose(bookingSystem.getOriginAirports());

        cout << "You chose: " << origin.getId() << endl << endl;

        cout << "Please choose your flight:" << endl;

        Flight flight = choose(bookingSystem.getFlightsByOrigin(origin));

        cout << "You chose: " << flight << endl << endl;

        // the next steps would be to enter the number of people or luggage...

        cout << "Thank you for using the booking system!" << endl << endl;
      }
    }

};
