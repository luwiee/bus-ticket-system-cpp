#include "passenger.h"
#include <iostream>

// Constructor
Passenger::Passenger(int passengerNumber, const std::string& name)
    : passengerNumber(passengerNumber), name(name) {}

// Accessors
int Passenger::getPassengerNumber() const {
    return passengerNumber;
}

std::string Passenger::getName() const {
    return name;
}

// Function to add a ticket to the passenger's tickets vector
void Passenger::addTicket(const Ticket& ticket) {
    tickets.push_back(ticket);
}

// Function to display passenger information including their tickets
void Passenger::displayPassengerInfo() const {
    std::cout << "Passenger Number: " << passengerNumber << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Tickets Booked:" << std::endl;

    if (tickets.empty()) {
        std::cout << "No tickets booked." << std::endl;
    } else {
        for (const Ticket& ticket : tickets) {
            ticket.displayTicketInfo();
            std::cout << "------------------------" << std::endl;
        }
    }
}

// Function to get the vector of tickets belonging to the passenger
std::vector<Ticket> Passenger::getTickets() {
    return tickets;
}
