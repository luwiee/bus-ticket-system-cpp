#include "ticket.h"
#include <iostream>

// Constructor
Ticket::Ticket(int ticketNumber, int passengerNumber, const std::string& passengerName, const std::string& busNumber, int seatNumber, float totalPrice)
    : ticketNumber(ticketNumber), passengerNumber(passengerNumber), passengerName(passengerName), busNumber(busNumber), seatNumber(seatNumber), totalPrice(totalPrice) {}

// Accessors
int Ticket::getTicketNumber() const {
    return ticketNumber;
}

int Ticket::getPassengerNumber() const {
    return passengerNumber;
}

std::string Ticket::getPassengerName() const {
    return passengerName;
}

std::string Ticket::getBusNumber() const {
    return busNumber;
}

int Ticket::getSeatNumber() const {
    return seatNumber;
}

float Ticket::getTotalPrice() const {
    return totalPrice;
}

// Function
void Ticket::displayTicketInfo() const {
    std::cout << "Ticket Number: " << ticketNumber << std::endl;
    std::cout << "Passenger Number: " << passengerNumber << std::endl;
    std::cout << "Passenger Name: " << passengerName << std::endl;
    std::cout << "Bus Number: " << busNumber << std::endl;
    std::cout << "Seat Number: " << seatNumber << std::endl;
    std::cout << "Total Price: " << totalPrice << std::endl;
}
