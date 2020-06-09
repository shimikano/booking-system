#include <iostream>

#include "command_line_interface.cpp"

using namespace std;

int main() {
  // create the BookingSystem instance
  BookingSystem bookingSystem = BookingSystem();

  // create some Airport instances
  Airport zrh = Airport("ZRH", "Zurich Kloten");
  Airport nrt = Airport("NRT", "Tokyo Narita");
  Airport mex = Airport("MEX", "Mexico City");
  Airport bjx = Airport("BJX", "Guananjuato");
  Airport cun = Airport("CUN", "Cancun");

  // create some Airline instances
  Airline swiss = Airline("Swiss International Airlines");
  Airline aeromexico = Airline("Aeromexico");
  Airline jal = Airline("Japan Air Lines");

  // create some Flight instances and add them to the BookingSystem
  bookingSystem.addFlight(Flight(zrh, nrt, swiss, 123));
  bookingSystem.addFlight(Flight(zrh, nrt, swiss, 1234)); // another departure date/time
  bookingSystem.addFlight(Flight(zrh, nrt, jal, 123));
  bookingSystem.addFlight(Flight(zrh, mex, swiss, 1234));
  bookingSystem.addFlight(Flight(nrt, bjx, jal, 12345));
  bookingSystem.addFlight(Flight(nrt, zrh, jal, 123456));
  bookingSystem.addFlight(Flight(mex, zrh, swiss, 1234567));
  bookingSystem.addFlight(Flight(mex, bjx, aeromexico, 123));
  bookingSystem.addFlight(Flight(mex, cun, aeromexico, 1234));
  bookingSystem.addFlight(Flight(cun, mex, aeromexico, 12345));
  bookingSystem.addFlight(Flight(cun, zrh, swiss, 123456));

  // create and start the interactive command line application
  CommandLineInterface commandLineInterface = CommandLineInterface(bookingSystem);
  commandLineInterface.start();
}
