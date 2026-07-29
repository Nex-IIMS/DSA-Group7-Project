#include <vector>
#include <utility>

// ---------------- Selection Sort ----------------
void selectionSort(std::vector<Record>& records) {
    int n = records.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (records[j].value < records[minIndex].value) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(records[i], records[minIndex]);
        }
    }
}

// ---------------- Quick Sort ----------------
int partition(std::vector<Record>& records, int low, int high) {
    int pivot = records[high].value;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (records[j].value < pivot) {
            i++;
            std::swap(records[i], records[j]);
        }
    }
    std::swap(records[i + 1], records[high]);
    return i + 1;
}

void quickSort(std::vector<Record>& records, int low, int high) {
    if (low < high) {
        int pi = partition(records, low, high);
        quickSort(records, low, pi - 1);
        quickSort(records, pi + 1, high);
    }
}

// ---------------- Merge Sort ----------------
void merge(std::vector<Record>& records, int left, int mid, int right) {
    std::vector<Record> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (records[i].value <= records[j].value) temp.push_back(records[i++]);
        else temp.push_back(records[j++]);
    }
    while (i <= mid) temp.push_back(records[i++]);
    while (j <= right) temp.push_back(records[j++]);

    for (int k = 0; k < temp.size(); k++) {
        records[left + k] = temp[k];
    }
}

void mergeSort(std::vector<Record>& records, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(records, left, mid);
        mergeSort(records, mid + 1, right);
        merge(records, left, mid, right);
    }
}