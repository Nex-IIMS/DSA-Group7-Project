# ITS60504 - Sorting & Searching Algorithm System

## Group 7 Assignment: Data Structures and Algorithms (May 2026)

A modular C++ console application that implements, applies, and analyses fundamental sorting and searching algorithms.

---

## Project Structure

```
DSA-Group7-Project/
├── main.cpp                    # CLI menu framework & entry point
├── record.h                    # Record struct definition
├── data_generator.h/.cpp       # Random data generation (100+ records)
├── timer.h                     # Execution time measurement utility
├── selection_sort.h/.cpp       # Selection Sort implementation
├── quick_sort.h/.cpp           # Quick Sort (stub — Aayesha)
├── merge_sort.h/.cpp           # Merge Sort (stub — Aayesha)
├── binary_search.h/.cpp        # Binary Search (stub — Rashik)
├── interpolation_search.h/.cpp # Interpolation Search (stub — Rashik)
├── Makefile                    # Build configuration
├── .gitignore                  # Git ignore rules
└── README.md                   # This file
```

## How to Build & Run

### Using g++ (MinGW on Windows / GCC on Linux/Mac)

**Option 1: Using Make**
```bash
make          # Build the application
make run      # Build and run
make clean    # Clean compiled files
```

**Option 2: Manual compilation**
```bash
g++ -std=c++11 -Wall -o dsa_app main.cpp data_generator.cpp selection_sort.cpp quick_sort.cpp merge_sort.cpp binary_search.cpp interpolation_search.cpp
./dsa_app       # Linux/Mac
dsa_app.exe     # Windows
```

---

## Task Distribution

| Member     | Responsibility                          | Files to Implement                         |
|------------|----------------------------------------|-------------------------------------------|
| **Deebek** | Core System + Selection Sort + Integration | `main.cpp`, `record.h`, `data_generator.*`, `timer.h`, `selection_sort.*` |
| **Aayesha** | Quick Sort + Merge Sort                | `quick_sort.cpp`, `merge_sort.cpp`        |
| **Rashik**  | Binary Search + Interpolation Search   | `binary_search.cpp`, `interpolation_search.cpp` |
| **Dev**     | Report Lead (Part 2)                   | Benchmarks, graphs, Q3 analysis           |

---

## Integration Guide for Teammates

### How to Add Your Algorithm

1. **Clone the repo**: `git clone https://github.com/Nex-IIMS/DSA-Group7-Project.git`
2. **Create a feature branch**: `git checkout -b feature/quick-sort`
3. **Open your `.cpp` file** (e.g., `quick_sort.cpp`) — it already has a skeleton with instructions.
4. **Implement the function** matching the signature in the `.h` header file.
5. **Do NOT modify**:
   - The header file (`.h`) — the function signature must stay the same.
   - `main.cpp` — it already calls your function.
   - Other teammates' files.
6. **Test locally**: `make run`
7. **Push and create a Pull Request** to `main`.

### Function Signatures (Do Not Change)

```cpp
// Sorting (modifies the vector in-place)
void selectionSort(std::vector<Record>& records);                          // ✅ DONE (Deebek)
void quickSort(std::vector<Record>& records, int low, int high);           // TODO (Aayesha)
void mergeSort(std::vector<Record>& records, int left, int right);         // TODO (Aayesha)

// Searching (returns index or -1 if not found)
int binarySearch(const std::vector<Record>& records, int target);          // TODO (Rashik)
int interpolationSearch(const std::vector<Record>& records, int target);   // TODO (Rashik)
```

---

## Menu Structure

```
Main Menu:
  A. Display All Records
  B. Sort Records
       1. Selection Sort
       2. Quick Sort
       3. Merge Sort
  C. Search for Number
       1. Binary Search
       2. Interpolation Search
  D. Regenerate Dataset (change input size for scalability testing)
  E. Exit Application
```

---

## Scalability Testing (Part 2)

Use menu option **D** to regenerate the dataset with different sizes for benchmarking:
- n = 100, 500, 1000, 5000, 10000, 50000

The system automatically records and displays execution time (in ms) for each algorithm run.
