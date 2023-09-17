#include "bus.h"
#include <iostream>

// Constructor
Bus::Bus(const std::string& busNumber, const std::string& destination, int totalSeats, float ticketPrice)
    : busNumber(busNumber), destination(destination), totalSeats(totalSeats), ticketPrice(ticketPrice) {
    // Initialize seat availability (all seats initially available)
    for (int i = 1; i <= totalSeats; ++i) {
        seats.push_back(std::make_pair(i, true));
    }
}

// Accessors
std::string Bus::getBusNumber() const {
    return busNumber;
}

std::string Bus::getDestination() const {
    return destination;
}

int Bus::getTotalSeats() const {
    return totalSeats;
}

float Bus::getTicketPrice() const {
    return ticketPrice;
}

// Functions
void Bus::displayBusInfo() const {
    std::cout << "Bus Number: " << busNumber << std::endl;
    std::cout << "Destination: " << destination << std::endl;
    std::cout << "Total Seats: " << totalSeats << std::endl;
    std::cout << "Ticket Price: " << ticketPrice << std::endl;
}

bool Bus::bookSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > totalSeats) {
        std::cerr << "Error: Invalid seat number." << std::endl;
        return false;
    }

    if (!seats[seatNumber - 1].second) {
        std::cerr << "Error: Seat " << seatNumber << " is already booked." << std::endl;
        return false;
    }

    seats[seatNumber - 1].second = false;
    return true;
}

bool Bus::isSeatAvailable(int seatNumber) const {
    if (seatNumber < 1 || seatNumber > totalSeats) {
        std::cerr << "Error: Invalid seat number." << std::endl;
        return false;
    }

    return seats[seatNumber - 1].second;
}

int Bus::getAvailableSeatCount() const {
    int count = 0;
    for (const auto& seat : seats) {
        if (seat.second) {
            count++;
        }
    }
    return count;
}

int Bus::getBookedSeatCount() const {
    return totalSeats - getAvailableSeatCount();
}

const std::vector<Ticket>& Bus::getBookedTickets() const {
    return tickets;
}

