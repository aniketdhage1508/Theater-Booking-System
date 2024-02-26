# C++ Theatre Booking System

This C++ project implements a simple Theatre Booking System, allowing users to interactively book and cancel seats in a theatre. The system provides features such as seat visualization, ticket booking, cancellation, and more.

## Features

- **Seating Arrangement:** Displays the current seating arrangement of the theatre.
- **Ticket Booking:** Allows users to book seats, specifying row and seat numbers.
- **Ticket Cancellation:** Enables users to cancel booked tickets.
- **Pricing:** Provides dynamic pricing based on the row number of the selected seat.
- **Data Persistence:** Booking details are saved to a file (`booking_details.txt`) for data persistence between program runs.

## Usage

1. Compile the code using a C++ compiler:

   ```bash
   g++ theatre_booking_system.cpp -o theatre_booking_system
   ```

2. Run the executable:

   ```bash
   ./theatre_booking_system
   ```

3. Follow on-screen instructions to navigate and use the Theatre Booking System.

## Files

- `theatre_booking_system.cpp`: Main C++ source code file.
- `booking_details.txt`: File storing booking details (seat availability).

## Functionality

- **Display Seating:**
  - Visualizes the current seating arrangement of the theatre.

- **Book Ticket:**
  - Allows users to book seats by specifying row and seat numbers.
  - Provides dynamic pricing based on the selected seat's row.

- **Cancel Ticket:**
  - Enables users to cancel their booked tickets.

- **Clear Theatre:**
  - Clears all seat bookings, resetting the theatre.

- **Quit:**
  - Saves booking details and exits the program.

## Notes

- The system is designed for educational purposes and can be extended for additional features.
- Ensure proper input during seat selection to avoid errors.
