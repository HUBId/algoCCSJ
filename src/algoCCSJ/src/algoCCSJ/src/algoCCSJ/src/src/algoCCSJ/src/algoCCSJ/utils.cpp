#include "utils.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

class Utils {
public:
    // Convert a byte vector to a hex string for printing or hashing purposes
    std::string byteToHex(const std::vector<uint8_t>& bytes) {
        std::stringstream ss;
        for (auto byte : bytes) {
            ss << std::setfill('0') << std::setw(2) << std::hex << (int)byte;
        }
        return ss.str();
    }

    // Print a byte vector
    void printBytes(const std::vector<uint8_t>& bytes) {
        for (auto byte : bytes) {
            std::cout << (int)byte << " ";
        }
        std::cout << std::endl;
    }
};
