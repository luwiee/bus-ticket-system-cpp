#ifndef BUS_H
#define BUS_H

#include <string>
#include <vector>
#include "ticket.h"

class Bus {
private:
    std::string busNumber;
    std::string destination;
    std::vector<std::pair<int, bool>> seats; // Represents seat availability (seat number, availability)
    std::vector<Ticket> tickets; // Represents tickets bought for this bus
    int totalSeats;
    float ticketPrice;

public:
    // Constructor
    Bus(const std::string& busNumber, const std::string& destination, int totalSeats, float ticketPrice);

    // Accessors
    std::string getBusNumber() const;
    std::string getDestination() const;
    int getTotalSeats() const;
    float getTicketPrice() const;

    // Functions
    void displayBusInfo() const;
    bool bookSeat(int seatNumber); // Returns true if booking is successful
    bool isSeatAvailable(int seatNumber) const;

    // Additional Functions
    int getAvailableSeatCount() const;
    int getBookedSeatCount() const;
    const std::vector<Ticket>& getBookedTickets() const;
    
};

#endif // BUS_H
