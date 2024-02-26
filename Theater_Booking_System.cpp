#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Theater
{
    int capacity;                // Total capacity of the theater
    bool seats[10][10];          // Array to track seat availability
    float ticketCharges[10][10]; // Array to store ticket charges

public:
    Theater(int capacity)
    {
        this->capacity = capacity;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                seats[i][j] = false;  // Initialize all seats as unbooked
            }
        }
        
        // Set ticket charges based on row numbers
        for(int row = 0; row < 10 ; row++)
        {
            if(row == 0)
            {
                // First row - all seats have a charge of 300
                for (int j = 0; j < 10; j++)
                {
                    ticketCharges[0][j] = 300;
                }
            }
            else if(row>0 && row<=3)
            {
                // Rows 1 to 3 - all seats have a charge of 250
                for (int i = 1; i <=3; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        ticketCharges[i][j] = 250;
                    }
                }
            }
            else if(row>3 && row<=6)
            {
                // Rows 4 to 6 - all seats have a charge of 200
                for (int i = 4; i <= 6; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        ticketCharges[i][j] = 200;
                    }
                }
            }
            else if(row>6 && row<=9)
            {
                // Rows 7 to 9 - all seats have a charge of 150
                for (int i = 7; i <= 9; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        ticketCharges[i][j] = 150;
                    }
                }
            }
        }
    }
    
    // Function declarations
    void run();               // Main function to run the theater program
    void displaySeating();    // Display the current seating arrangement
    void bookTicket();        // Book a ticket
    void cancelTicket();      // Cancel a booked ticket
    void saveData();          // Save booking details to a file
    void loadData();          // Load booking details from a file
    void price(int, int);     // Calculate and display the price of a ticket
    void clear();             // Clear all bookings
};

int main()
{
    Theater theater(100);  // Initialize theater with a capacity of 100 (10x10)
    theater.run();

    return 0;
}

// Member function definitions

void Theater::displaySeating()
{
    cout << "Current Seating:" << endl;
    cout << "    ";
    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";   // Print column numbers
    }
    cout << endl << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i << "   ";
        for (int j = 0; j < 10; j++)
        {
            char status = seats[i][j] ? 'X' : 'O';
            cout << status << " ";  // Print seat status: 'X' for booked, 'O' for available
        }
        cout << endl;
    }
    cout << endl;
}

void Theater::bookTicket()
{
    int row, seat;
    cout << "Enter the row number: ";
    cin >> row;
    cout << "Enter the seat number: ";
    cin >> seat;

    if (row < 0 || row >= 10 || seat < 0 || seat >= 10)
    {
        cout << "Invalid seat selection. Please try again." << endl;
        return;
    }

    if (seats[row][seat])
    {
        cout << "Sorry, this seat is already booked." << endl;
    }
    else
    {
        seats[row][seat] = true;
        cout << "Ticket booked successfully!" << endl;
        price(row, seat);
    }
}

void Theater::cancelTicket()
{
    int row, seat;
    cout << "Enter the row number: ";
    cin >> row;
    cout << "Enter the seat number: ";
    cin >> seat;

    if (row < 0 || row >= 10 || seat < 0 || seat >= 10)
    {
        cout << "Invalid seat selection. Please try again." << endl;
        return;
    }

    if (!seats[row][seat])
    {
        cout << "This seat is already vacant." << endl;
    }
    else
    {
        seats[row][seat] = false;
        cout << "Ticket canceled successfully!" << endl;
    }
}

void Theater::saveData()
{
    ofstream outputFile("booking_details.txt");  //Defining Output Source with Object name outputFile

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            outputFile << seats[i][j] << " ";  // Save seat status to file (0 for unbooked, 1 for booked)
        }
        outputFile << endl;
    }

    outputFile.close();
}

void Theater::loadData()
{
    ifstream inputFile("booking_details.txt");  //Defining Input Source with Object name inputFile
    string line;
    int row = 0;

    while (getline(inputFile, line))
    {
        stringstream ss(line);   //Creates a stringstream Object ss and initializes it with the contents of the string line
        int seat;
        int col = 0;

        while (ss >> seat)
        {
            seats[row][col] = static_cast<bool>(seat);  // Load seat status from file (0 for unbooked, 1 for booked)
            col++;
        }

        row++;
    }

    inputFile.close();
}

void Theater::run()
{
    loadData();

    while (true)
    {
        cout << "\n\n===================================" << endl;
        cout << "          Ticket Booking            " << endl;
        cout << "===================================" << endl;
        cout << "1. Display Seating" << endl;
        cout << "2. Book Ticket" << endl;
        cout << "3. Cancel Ticket" << endl;
        cout << "4. Clear Theater" << endl;
        cout << "5. Quit" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
                displaySeating();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                clear();
                break;
            case 5:
                saveData();
                cout << "Thank you for using the ticket booking system." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void Theater::price(int row, int seat)
{
    int Price;
    Price = ticketCharges[row][seat];
    cout << "Please Pay " << Price << " to Confirm your Seat.";
}

void Theater::clear()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            seats[i][j] = false;  // Clear all seat bookings
        }
    }
}
