#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

#include "record.cpp"
#include "timer.cpp"
#include "data_generator.cpp"
#include "sorting.cpp"
#include "searching.cpp"

void displayRecords(vector<Record>& records) {
    for (int i = 0; i < records.size(); i++) {
        cout << "ID: " << records[i].id << " Value: " << records[i].value << endl;
    }
}

void sortMenu(vector<Record>& originalRecords) {
    cout << "1. Selection Sort  2. Quick Sort  3. Merge Sort\nChoice: ";
    int choice;
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    vector<Record> workingCopy = originalRecords;

    Timer t;
    t.start();

    if (choice == 1) selectionSort(workingCopy);
    else if (choice == 2) quickSort(workingCopy, 0, workingCopy.size() - 1);
    else if (choice == 3) mergeSort(workingCopy, 0, workingCopy.size() - 1);
    else { cout << "Invalid choice.\n"; return; }

    t.stop();
    cout << "Sorted in " << t.getElapsedMilliseconds() << " ms\n";

    cout << "View sorted result? (y/n): ";
    char view;
    cin >> view;
    if (view == 'y' || view == 'Y') {
        displayRecords(workingCopy);
    }
}

void searchMenu(vector<Record>& originalRecords) {
    vector<Record> workingCopy = originalRecords;
    selectionSort(workingCopy);

    int target;
    cout << "Enter number to search: ";
    cin >> target;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    cout << "1. Binary Search  2. Interpolation Search\nChoice: ";
    int choice;
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
        return;
    }

    Timer t;
    t.start();
    int result = -1;

    if (choice == 1) result = binarySearch(workingCopy, target);
    else if (choice == 2) result = interpolationSearch(workingCopy, target);
    else { cout << "Invalid choice.\n"; return; }

    t.stop();

    if (result != -1) cout << "Found at index " << result << endl;
    else cout << "Not found.\n";
    cout << "Search took " << t.getElapsedMilliseconds() << " ms\n";
}

int main() {
    int size;
    cout << "Enter dataset size (press Enter for default 100): ";

    string input;
    getline(cin, input);

    if (input.empty()) {
        size = 100;
    } else {
        try {
            size = stoi(input);
        } catch (...) {
            cout << "Invalid input. Using default size 100.\n";
            size = 100;
        }
        if (size < 100) {
            cout << "Minimum size is 100. Using 100.\n";
            size = 100;
        }
    }

    vector<Record> originalRecords = generateRecords(size);
    cout << size << " records generated.\n";

    char choice;
    do {
        cout << "\nA. Display  B. Sort  C. Search  D. Regenerate Dataset  E. Exit\nChoice: ";
        cin >> choice;
        choice = toupper(choice);
        cin.ignore();

        if (choice == 'A') displayRecords(originalRecords);
        else if (choice == 'B') sortMenu(originalRecords);
        else if (choice == 'C') searchMenu(originalRecords);
        else if (choice == 'D') {
            cout << "Enter new dataset size: ";
            string newInput;
            getline(cin, newInput);

            int newSize;
            try {
                newSize = stoi(newInput);
            } catch (...) {
                cout << "Invalid input. Keeping current dataset size.\n";
                newSize = originalRecords.size();
            }

            if (newSize < 100) {
                cout << "Minimum size is 100. Using 100.\n";
                newSize = 100;
            }
            originalRecords = generateRecords(newSize);
            cout << newSize << " records generated.\n";
        }
        else if (choice == 'E') cout << "Goodbye!\n";
        else cout << "Invalid choice.\n";

    } while (choice != 'E');

    return 0;
}