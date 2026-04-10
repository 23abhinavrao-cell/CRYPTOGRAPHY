#include <iostream>
#include "DiffieHellman.h"

int main() {
    DiffieHellman dh(64);

    cpp_int p = dh.getPrime();
    cpp_int g = dh.getGenerator();

    cpp_int alicePrivate = dh.generatePrivateKey(32);
    cpp_int bobPrivate = dh.generatePrivateKey(32);

    cpp_int alicePublic = dh.generatePublicKey(alicePrivate);
    cpp_int bobPublic = dh.generatePublicKey(bobPrivate);

    cpp_int aliceSecret = dh.computeSharedSecret(bobPublic, alicePrivate);
    cpp_int bobSecret = dh.computeSharedSecret(alicePublic, bobPrivate);

    std::cout << "Public Prime (p): " << p << "\n";
    std::cout << "Generator (g): " << g << "\n\n";

    std::cout << "Alice Private Key: " << alicePrivate << "\n";
    std::cout << "Alice Public Key: " << alicePublic << "\n\n";

    std::cout << "Bob Private Key: " << bobPrivate << "\n";
    std::cout << "Bob Public Key: " << bobPublic << "\n\n";

    std::cout << "Alice Shared Secret: " << aliceSecret << "\n";
    std::cout << "Bob Shared Secret: " << bobSecret << "\n\n";

    if (aliceSecret == bobSecret) {
        std::cout << "Key Exchange Successful: Shared secrets match\n";
    } else {
        std::cout << "Key Exchange Failed: Shared secrets do not match\n";
    }

    return 0;
}
