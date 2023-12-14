#include "../include/GenerateUUID.h"

string GenerateUUID::generator() {
    random_device rd;
    mt19937_64 gen(rd());

    uniform_int_distribution<uint64_t> dis(0, UINT64_MAX);
    uint64_t section_1 = dis(gen);
    uint64_t section_2 = dis(gen);

    stringstream ss;

    ss << hex << setfill('0');
    ss << setw(16) << section_1 << "-";
    ss << setw(16) << section_2;
    return ss.str();    
}