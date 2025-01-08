#include "encryption.h"
#include <iostream>
#include <vector>

class Encryption {
public:
    // Simple XOR encryption for demonstration
    void encrypt(std::vector<uint8_t>& data) {
        std::cout << "Encrypting data...\n";
        for (auto& byte : data) {
            byte ^= 0xFF;  // XOR with 0xFF
        }
    }

    // Simple XOR decryption for demonstration
    void decrypt(std::vector<uint8_t>& data) {
        std::cout << "Decrypting data...\n";
        for (auto& byte : data) {
            byte ^= 0xFF;  // XOR with 0xFF
        }
    }
};
