// ============================================================
// record.h - Data Structure Definition
// ITS60504 Data Structures and Algorithms
// ============================================================
// Defines the Record struct used throughout the application.
// Each record stores an ID and a random integer value.
// Sorting and searching operations are performed on the 'value' field.
// ============================================================

#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <iomanip>

struct Record {
    int id;       // Sequential identifier for the record
    int value;    // Random integer value (used for sorting/searching)

    // Display a single record in formatted output
    void display() const {
        std::cout << "| " << std::setw(6) << id
                  << " | " << std::setw(10) << value << " |" << std::endl;
    }
};

#endif // RECORD_H
