#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<Record> generateRecords(int count) {
    std::vector<Record> records;
    srand(time(0));

    for (int i = 0; i < count; i++) {
        Record r;
        r.id = i + 1;
        r.value = rand() % 10000 + 1;
        records.push_back(r);
    }

    return records;
}