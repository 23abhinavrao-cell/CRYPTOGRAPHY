#ifndef DIFFIE_HELLMAN_H
#define DIFFIE_HELLMAN_H

#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

class DiffieHellman {
private:
    cpp_int p;
    cpp_int g;

public:
    DiffieHellman(int bits = 64);

    cpp_int getPrime() const;
    cpp_int getGenerator() const;

    cpp_int generatePrivateKey(int bits = 32);
    cpp_int generatePublicKey(const cpp_int& privateKey);
    cpp_int computeSharedSecret(const cpp_int& otherPublicKey, const cpp_int& privateKey);
    static cpp_int modPow(cpp_int base, cpp_int exp, const cpp_int& mod);
    static bool isPrime(const cpp_int& n, int iterations = 10);
    static cpp_int generatePrime(int bits);
    static cpp_int randomBigInt(int bits);
};

#endif
