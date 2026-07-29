#include "searching.h"

int binarySearch(const std::vector<Record>& records, int target)
{
    if (records.empty())
        return -1;

    int low = 0;
    int high = static_cast<int>(records.size()) - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (records[mid].value == target)
        {
            return mid;
        }
        else if (records[mid].value < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int interpolationSearch(const std::vector<Record>& records, int target)
{
    if (records.empty())
        return -1;

    int low = 0;
    int high = static_cast<int>(records.size()) - 1;

    while (low <= high &&
           target >= records[low].value &&
           target <= records[high].value)
    {
        if (records[low].value == records[high].value)
        {
            if (records[low].value == target)
                return low;

            return -1;
        }

        int pos = low +
                  static_cast<int>(
                      (static_cast<double>(high - low) /
                       (records[high].value - records[low].value)) *
                      (target - records[low].value)
                  );

        if (records[pos].value == target)
        {
            return pos;
        }
        else if (records[pos].value < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    return -1;
}