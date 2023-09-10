#include <iostream>
#include <vector>
#include "bus.h"
#include "passenger.h"
#include "ticket.h"

int main()
{
    std::vector<Bus> buses;
    std::vector<Passenger> passengers;

    while (true)
    {
        std::cout << "========= Ticket Booking System =========" << std::endl;
        std::cout << "1. Add Bus" << std::endl;
        std::cout << "2. View List of Buses" << std::endl;
        std::cout << "3. Check Available Seats of a Bus" << std::endl;
        std::cout << "4. Check Passenger in a Seat of a Bus" << std::endl;
        std::cout << "5. View List of Passengers" << std::endl;
        std::cout << "6. View Tickets of a Passenger" << std::endl;
        std::cout << "7. Book a Ticket for a Registered Passenger" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "=========================================" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string busNumber, destination;
            int totalSeats;
            float ticketPrice;

            std::cout << "Enter Bus Number: ";
            std::cin >> busNumber;
            std::cout << "Enter Destination: ";
            std::cin >> destination;
            std::cout << "Enter Total Seats: ";
            std::cin >> totalSeats;
            std::cout << "Enter Ticket Price: ";
            std::cin >> ticketPrice;

            Bus newBus(busNumber, destination, totalSeats, ticketPrice);
            buses.push_back(newBus);

            std::cout << "Bus added successfully!" << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "=== List of Buses ===" << std::endl;
            for (const Bus &bus : buses)
            {
                bus.displayBusInfo();
                std::cout << "------------------------" << std::endl;
            }
            break;
        }
        case 3:
        {
            std::string targetBusNumber;
            std::cout << "Enter Bus Number: ";
            std::cin >> targetBusNumber;

            bool found = false;
            for (const Bus &bus : buses)
            {
                if (bus.getBusNumber() == targetBusNumber)
                {
                    found = true;
                    int availableSeats = bus.getAvailableSeatCount();
                    int bookedSeats = bus.getBookedSeatCount();
                    std::cout << "Available Seats: " << availableSeats << std::endl;
                    std::cout << "Booked Seats: " << bookedSeats << std::endl;
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Bus with number " << targetBusNumber << " not found." << std::endl;
            }

            break;
        }
        case 4:
        {
            std::string targetBusNumber;
            int targetSeatNumber;

            std::cout << "Enter Bus Number: ";
            std::cin >> targetBusNumber;
            std::cout << "Enter Seat Number: ";
            std::cin >> targetSeatNumber;

            bool found = false;
            for (const Bus &bus : buses)
            {
                if (bus.getBusNumber() == targetBusNumber)
                {
                    found = true;
                    if (bus.isSeatAvailable(targetSeatNumber))
                    {
                        std::cout << "Seat " << targetSeatNumber << " is available." << std::endl;
                    }
                    else
                    {
                        const std::vector<Ticket> &bookedTickets = bus.getBookedTickets();
                        for (const Ticket &ticket : bookedTickets)
                        {
                            if (ticket.getSeatNumber() == targetSeatNumber)
                            {
                                std::cout << "Passenger " << ticket.getPassengerName() << " is in seat " << targetSeatNumber << "." << std::endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Bus with number " << targetBusNumber << " not found." << std::endl;
            }

            break;
        }
        case 5:
        {
            std::cout << "=== List of Passengers ===" << std::endl;
            for (const Passenger &passenger : passengers)
            {
                passenger.displayPassengerInfo();
                std::cout << "------------------------" << std::endl;
            }
            break;
        }
        case 6:
        {
            int targetPassengerNumber;
            std::cout << "Enter Passenger Number: ";
            std::cin >> targetPassengerNumber;

            bool found = false;
            for (Passenger &passenger : passengers)
            {
                if (passenger.getPassengerNumber() == targetPassengerNumber)
                {
                    found = true;
                    passenger.displayPassengerInfo();
                    std::cout << "Tickets Booked:" << std::endl;
                    const std::vector<Ticket> &passengerTickets = passenger.getTickets();
                    if (passengerTickets.empty())
                    {
                        std::cout << "No tickets booked." << std::endl;
                    }
                    else
                    {
                        for (const Ticket &ticket : passengerTickets)
                        {
                            ticket.displayTicketInfo();
                        }
                    }
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Passenger with number " << targetPassengerNumber << " not found." << std::endl;
            }

            break;
        }
        case 7:
        {
            int targetPassengerNumber;
            std::string targetBusNumber;
            int targetSeatNumber;

            std::cout << "Enter Passenger Number: ";
            std::cin >> targetPassengerNumber;
            std::cout << "Enter Bus Number: ";
            std::cin >> targetBusNumber;
            std::cout << "Enter Seat Number: ";
            std::cin >> targetSeatNumber;

            bool foundPassenger = false;
            for (Passenger &passenger : passengers)
            {
                if (passenger.getPassengerNumber() == targetPassengerNumber)
                {
                    foundPassenger = true;

                    bool foundBus = false;
                    for (Bus &bus : buses)
                    {
                        if (bus.getBusNumber() == targetBusNumber)
                        {
                            foundBus = true;

                            if (bus.isSeatAvailable(targetSeatNumber))
                            {
                                float ticketPrice = bus.getTicketPrice();

                                // Generate the ticket number for the entire bus system
                                int ticketNumber = Ticket::getNextTicketNumber();

                                // Create a new Ticket object and add it to the passenger's tickets
                                Ticket newTicket(ticketNumber, targetPassengerNumber, passenger.getName(), targetBusNumber, targetSeatNumber, ticketPrice);
                                passenger.addTicket(newTicket);

                                // Book the seat on the bus
                                bus.bookSeat(targetSeatNumber);

                                // Increment the ticket number for the entire bus system
                                Ticket::incrementNextTicketNumber();

                                std::cout << "Ticket booked successfully!" << std::endl;
                            }
                            else
                            {
                                std::cout << "Seat " << targetSeatNumber << " is already booked." << std::endl;
                            }
                            break;
                        }
                    }

                    if (!foundBus)
                    {
                        std::cout << "Bus with number " << targetBusNumber << " not found." << std::endl;
                    }

                    break;
                }
            }

            if (!foundPassenger)
            {
                std::cout << "Passenger with number " << targetPassengerNumber << " not found." << std::endl;
            }

            break;
        }
        case 8:
        {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            return 0;
        }
        default:
        {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            break;
        }
        }
    }

    return 0;
}
