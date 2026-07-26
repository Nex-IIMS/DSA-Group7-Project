// ============================================================
// main.cpp - CLI Menu Framework & Application Entry Point
// ITS60504 Data Structures and Algorithms
// Group Assignment: Sorting and Searching Algorithms
// ============================================================
// This file provides the menu-driven command line interface
// that serves as the central hub for all algorithm operations.
// Each menu option invokes a corresponding dedicated function.
//
// Features:
//   - Auto-generates 100+ dummy records on startup
//   - Menu options: Display, Sort, Search, Exit
//   - Timing for every algorithm execution
//   - Supports scalability testing with variable input sizes
// ============================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

#include "record.h"
#include "data_generator.h"
#include "selection_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "binary_search.h"
#include "interpolation_search.h"
#include "timer.h"

using namespace std;

// ============================================================
// DISPLAY FUNCTIONS
// ============================================================

// Prints a horizontal separator line
void printSeparator(int width = 50) {
    cout << string(width, '=') << endl;
}

// Prints a thinner separator line
void printThinSeparator(int width = 50) {
    cout << string(width, '-') << endl;
}

// Display all records in a formatted table
void displayRecords(const vector<Record>& records) {
    cout << endl;
    printSeparator();
    cout << "         ALL RECORDS (" << records.size() << " total)" << endl;
    printSeparator();
    cout << "| " << setw(6) << "ID"
         << " | " << setw(10) << "Value" << " |" << endl;
    printThinSeparator(24);

    for (const auto& record : records) {
        record.display();
    }

    printSeparator();
    cout << endl;
}

// Display the main menu
void displayMainMenu() {
    cout << endl;
    printSeparator();
    cout << "   SORTING & SEARCHING ALGORITHM SYSTEM" << endl;
    printSeparator();
    cout << "   A. Display All Records" << endl;
    cout << "   B. Sort Records" << endl;
    cout << "   C. Search for Number" << endl;
    cout << "   D. Regenerate Dataset" << endl;
    cout << "   E. Exit Application" << endl;
    printSeparator();
}

// Display the sorting sub-menu
void displaySortMenu() {
    cout << endl;
    printThinSeparator(40);
    cout << "   SELECT SORTING ALGORITHM" << endl;
    printThinSeparator(40);
    cout << "   1. Selection Sort" << endl;
    cout << "   2. Quick Sort" << endl;
    cout << "   3. Merge Sort" << endl;
    cout << "   4. Back to Main Menu" << endl;
    printThinSeparator(40);
}

// Display the searching sub-menu
void displaySearchMenu() {
    cout << endl;
    printThinSeparator(40);
    cout << "   SELECT SEARCHING ALGORITHM" << endl;
    printThinSeparator(40);
    cout << "   1. Binary Search" << endl;
    cout << "   2. Interpolation Search" << endl;
    cout << "   3. Back to Main Menu" << endl;
    printThinSeparator(40);
}

// ============================================================
// HELPER FUNCTIONS
// ============================================================

// Clears the input buffer to prevent issues with cin
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Checks if the dataset is sorted (needed before searching)
bool isSorted(const vector<Record>& records) {
    for (size_t i = 1; i < records.size(); i++) {
        if (records[i].value < records[i - 1].value) {
            return false;
        }
    }
    return true;
}

// ============================================================
// SORTING HANDLER
// ============================================================
// Creates a working copy of the dataset, runs the selected
// sorting algorithm, measures execution time, and displays
// the sorted result.
// ============================================================

void handleSorting(vector<Record>& records) {
    bool inSortMenu = true;

    while (inSortMenu) {
        displaySortMenu();
        cout << "   Enter your choice: ";
        char sortChoice;
        cin >> sortChoice;
        clearInputBuffer();

        if (sortChoice == '4') {
            inSortMenu = false;
            continue;
        }

        // Create a working copy so the original data is preserved
        // for comparing different sorting algorithms on the same dataset
        vector<Record> workingCopy = records;
        string algorithmName;
        Timer timer;

        switch (sortChoice) {
            case '1': {
                algorithmName = "Selection Sort";
                cout << "\n   Running " << algorithmName << "..." << endl;
                timer.start();
                selectionSort(workingCopy);
                timer.stop();
                break;
            }
            case '2': {
                algorithmName = "Quick Sort";
                cout << "\n   Running " << algorithmName << "..." << endl;
                timer.start();
                quickSort(workingCopy, 0, workingCopy.size() - 1);
                timer.stop();
                break;
            }
            case '3': {
                algorithmName = "Merge Sort";
                cout << "\n   Running " << algorithmName << "..." << endl;
                timer.start();
                mergeSort(workingCopy, 0, workingCopy.size() - 1);
                timer.stop();
                break;
            }
            default:
                cout << "   Invalid choice. Please try again." << endl;
                continue;
        }

        // Display timing result
        cout << "\n   " << algorithmName << " completed!" << endl;
        cout << "   Execution Time: " << fixed << setprecision(4)
             << timer.getElapsedMilliseconds() << " ms" << endl;
        cout << "   Records sorted: " << workingCopy.size() << endl;

        // Ask if user wants to view sorted results
        cout << "\n   View sorted records? (Y/N): ";
        char viewChoice;
        cin >> viewChoice;
        clearInputBuffer();

        if (toupper(viewChoice) == 'Y') {
            displayRecords(workingCopy);
        }

        // Ask if user wants to apply the sort to the main dataset
        cout << "   Apply this sort to the main dataset? (Y/N): ";
        char applyChoice;
        cin >> applyChoice;
        clearInputBuffer();

        if (toupper(applyChoice) == 'Y') {
            records = workingCopy;
            cout << "   Dataset updated with sorted order." << endl;
        }
    }
}

// ============================================================
// SEARCHING HANDLER
// ============================================================
// Accepts a target integer from the user and runs the selected
// searching algorithm, measuring execution time.
// ============================================================

void handleSearching(const vector<Record>& records) {
    // Check if data is sorted (required for both search algorithms)
    if (!isSorted(records)) {
        cout << "\n   WARNING: Dataset is NOT sorted!" << endl;
        cout << "   Binary Search and Interpolation Search require" << endl;
        cout << "   sorted data. Please sort the data first (Menu B)." << endl;
        cout << "   Proceeding may produce incorrect results." << endl;

        cout << "\n   Continue anyway? (Y/N): ";
        char proceed;
        cin >> proceed;
        clearInputBuffer();

        if (toupper(proceed) != 'Y') {
            return;
        }
    }

    bool inSearchMenu = true;

    while (inSearchMenu) {
        displaySearchMenu();
        cout << "   Enter your choice: ";
        char searchChoice;
        cin >> searchChoice;
        clearInputBuffer();

        if (searchChoice == '3') {
            inSearchMenu = false;
            continue;
        }

        // Get the target value from user
        int target;
        cout << "\n   Enter the number to search for: ";
        cin >> target;
        clearInputBuffer();

        string algorithmName;
        int resultIndex = -1;
        Timer timer;

        switch (searchChoice) {
            case '1': {
                algorithmName = "Binary Search";
                cout << "   Running " << algorithmName << "..." << endl;
                timer.start();
                resultIndex = binarySearch(records, target);
                timer.stop();
                break;
            }
            case '2': {
                algorithmName = "Interpolation Search";
                cout << "   Running " << algorithmName << "..." << endl;
                timer.start();
                resultIndex = interpolationSearch(records, target);
                timer.stop();
                break;
            }
            default:
                cout << "   Invalid choice. Please try again." << endl;
                continue;
        }

        // Display search result
        cout << endl;
        printThinSeparator(40);
        cout << "   " << algorithmName << " Result:" << endl;
        printThinSeparator(40);

        if (resultIndex != -1) {
            cout << "   FOUND! Value " << target
                 << " at index " << resultIndex << endl;
            cout << "   Record ID: " << records[resultIndex].id << endl;
        } else {
            cout << "   NOT FOUND. Value " << target
                 << " does not exist in the dataset." << endl;
        }

        cout << "   Execution Time: " << fixed << setprecision(4)
             << timer.getElapsedMilliseconds() << " ms" << endl;
        printThinSeparator(40);
    }
}

// ============================================================
// DATASET REGENERATION
// ============================================================
// Allows user to regenerate the dataset with a different size.
// Useful for Part 2 scalability testing at various input sizes.
// ============================================================

void handleRegenerate(vector<Record>& records) {
    cout << "\n   Current dataset size: " << records.size() << endl;
    cout << "   Enter new dataset size (min 100): ";

    int newSize;
    cin >> newSize;
    clearInputBuffer();

    if (newSize < 100) {
        cout << "   Size must be at least 100. Setting to 100." << endl;
        newSize = 100;
    }

    records = generateRecords(newSize);
    cout << "   New dataset generated with " << records.size()
         << " records." << endl;
}

// ============================================================
// MAIN FUNCTION - Application Entry Point
// ============================================================

int main() {
    // Default: generate 100 records as required by the assignment
    const int DEFAULT_RECORD_COUNT = 100;
    vector<Record> records = generateRecords(DEFAULT_RECORD_COUNT);

    cout << endl;
    printSeparator();
    cout << "   ITS60504 - Data Structures and Algorithms" << endl;
    cout << "   Sorting & Searching Algorithm System" << endl;
    printSeparator();
    cout << "   " << DEFAULT_RECORD_COUNT
         << " records generated successfully." << endl;

    bool running = true;

    while (running) {
        displayMainMenu();
        cout << "   Enter your choice: ";
        char choice;
        cin >> choice;
        clearInputBuffer();
        choice = toupper(choice);

        switch (choice) {
            case 'A':
                displayRecords(records);
                break;
            case 'B':
                handleSorting(records);
                break;
            case 'C':
                handleSearching(records);
                break;
            case 'D':
                handleRegenerate(records);
                break;
            case 'E':
                running = false;
                cout << endl;
                printSeparator();
                cout << "   Thank you for using the system. Goodbye!" << endl;
                printSeparator();
                cout << endl;
                break;
            default:
                cout << "   Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
