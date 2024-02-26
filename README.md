# C++ Theater Booking System

This C++ project implements a simple Theater Booking System, allowing users to interactively book and cancel seats in a theater. The system provides features such as seat visualization, ticket booking, cancellation, and more.

## Features

- **Seating Arrangement:** Displays the current seating arrangement of the theater.
- **Ticket Booking:** Allows users to book seats, specifying row and seat numbers.
- **Ticket Cancellation:** Enables users to cancel booked tickets.
- **Pricing:** Provides dynamic pricing based on the row number of the selected seat.
- **Data Persistence:** Booking details are saved to a file (`booking_details.txt`) for data persistence between program runs.

## Usage

1. Compile the code using a C++ compiler:

   ```bash
   g++ theater_booking_system.cpp -o theater_booking_system
   ```

2. Run the executable:

   ```bash
   ./theater_booking_system
   ```

3. Follow on-screen instructions to navigate and use the Theater Booking System.

## Files

- `theater_booking_system.cpp`: Main C++ source code file.
- `booking_details.txt`: File storing booking details (seat availability).

## Functionality

- **Display Seating:**
  - Visualizes the current seating arrangement of the theater.

- **Book Ticket:**
  - Allows users to book seats by specifying row and seat numbers.
  - Provides dynamic pricing based on the selected seat's row.

- **Cancel Ticket:**
  - Enables users to cancel their booked tickets.

- **Clear Theater:**
  - Clears all seat bookings, resetting the theater.

- **Quit:**
  - Saves booking details and exits the program.

## Notes

- The system is designed for educational purposes and can be extended for additional features.
- Ensure proper input during seat selection to avoid errors.
