#include <iostream>
#include <vector>

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

class MovieTicketBookingSystem {
private:
    std::vector<std::vector<bool>> seats;

public:
    MovieTicketBookingSystem() : seats(NUM_ROWS, std::vector<bool>(NUM_COLS, true)) {}

    void displayAvailableSeats() {
        std::cout << "Available Seats:" << std::endl;
        for (int i = 0; i < NUM_ROWS; ++i) {
            for (int j = 0; j < NUM_COLS; ++j) {
                if (seats[i][j]) {
                    std::cout << "O ";
                } else {
                    std::cout << "X ";
                }
            }
            std::cout << std::endl;
        }
    }

    bool bookTicket(int row, int col) {
        if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS && seats[row - 1][col - 1]) {
            seats[row - 1][col - 1] = false;
            return true;
        }
        return false;
    }

    double calculateTotalCost(int numTickets) {
        return numTickets * TICKET_PRICE;
    }
};

int main() {
    MovieTicketBookingSystem bookingSystem;

    std::cout << "Welcome to Movie Ticket Booking System!" << std::endl;

    while (true) {
        std::cout << "1. View available seats\n2. Book a ticket\n3. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                bookingSystem.displayAvailableSeats();
                break;
            case 2: {
                int row, col, numTickets;
                std::cout << "Enter row and column number: ";
                std::cin >> row >> col;
                std::cout << "Enter number of tickets: ";
                std::cin >> numTickets;
                if (bookingSystem.bookTicket(row, col)) {
                    std::cout << "Tickets booked successfully!" << std::endl;
                    std::cout << "Total cost: $" << bookingSystem.calculateTotalCost(numTickets) << std::endl;
                } else {
                    std::cout << "Invalid seat or seat already booked. Please try again." << std::endl;
                }
                break;
            }
            case 3:
                std::cout << "Thank you for using the Movie Ticket Booking System. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
