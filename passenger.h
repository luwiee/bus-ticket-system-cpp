#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <vector>
#include "ticket.h"

class Passenger {
private:
    int passengerNumber;
    std::string name;
    std::vector<Ticket> tickets;

public:
    // Constructor
    Passenger(int passengerNumber, const std::string& name);

    // Accessors
    int getPassengerNumber() const;
    std::string getName() const;

    // Functions
    void addTicket(const Ticket& ticket);
    void displayPassengerInfo() const;
    std::vector<Ticket> getTickets();
};

#endif // PASSENGER_H
