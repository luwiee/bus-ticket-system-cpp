#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
private:
    int ticketNumber;
    int passengerNumber; // Unique identifier for the passenger
    std::string passengerName;
    std::string busNumber;
    int seatNumber;
    float totalPrice;

    // Static variable to keep track of the next ticket number
    static int nextTicketNumber;

public:
    // Constructor
    Ticket(int ticketNumber, int passengerNumber, const std::string& passengerName, const std::string& busNumber, int seatNumber, float totalPrice);

    // Accessors
    int getTicketNumber() const;
    int getPassengerNumber() const;
    std::string getPassengerName() const;
    std::string getBusNumber() const;
    int getSeatNumber() const;
    float getTotalPrice() const;

    // Function
    void displayTicketInfo() const;

};

#endif // TICKET_H
