#include "PRBG.h"
#include <iostream>
#include <random>
#include <vector>

class PRBG {
public:
    uint8_t generate() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        return dis(gen);
    }

    std::vector<uint8_t> generateBytes(size_t length) {
        std::vector<uint8_t> randomBytes;
        for (size_t i = 0; i < length; ++i) {
            randomBytes.push_back(generate());
        }
        return randomBytes;
    }
};
