#include "compression.h"
#include "ANS.h"
#include "state_jump.h"
#include "PRBG.h"
#include <iostream>
#include <vector>

class Compression {
private:
    ANS ans;
    StateJump stateJump;
    PRBG prbg;

public:
    // Compresses data using ANS and applies a state jump
    void compressData(std::vector<uint8_t>& data) {
        // Generate randomness for state jumping
        std::vector<uint8_t> randomBytes = prbg.generateBytes(data.size());
        
        // Step 1: Apply compression with ANS
        ans.compress(data);

        // Step 2: Apply state jump to the compressed data
        stateJump.applyStateJump(data, randomBytes);
        
        std::cout << "Data compressed and state jump applied.\n";
    }

    // Decompresses data using ANS
    void decompressData(std::vector<uint8_t>& data) {
        std::cout << "Decompressing data...\n";
        ans.decompress(data);
    }

    // Encrypts the data using a simple XOR-based encryption (for illustration)
    void encrypt(std::vector<uint8_t>& data) {
        std::cout << "Encrypting data...\n";
        for (auto& byte : data) {
            byte ^= 0xFF; // Simple XOR with 0xFF for encryption
        }
    }

    // Decrypts the data using the same XOR-based decryption
    void decrypt(std::vector<uint8_t>& data) {
        std::cout << "Decrypting data...\n";
        for (auto& byte : data) {
            byte ^= 0xFF; // Simple XOR with 0xFF for decryption
        }
    }
};
