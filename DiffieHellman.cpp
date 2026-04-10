#include "DiffieHellman.h"
#include <random>

DiffieHellman::DiffieHellman(int bits) {
    p = generatePrime(bits);
    g = 2;
}

cpp_int DiffieHellman::getPrime() const {
    return p;
}

cpp_int DiffieHellman::getGenerator() const {
    return g;
}

cpp_int DiffieHellman::generatePrivateKey(int bits) {
    cpp_int key = randomBigInt(bits);
    if (key < 2) {
        key = 2;
    }
    return key;
}

cpp_int DiffieHellman::generatePublicKey(const cpp_int& privateKey) {
    return modPow(g, privateKey, p);
}

cpp_int DiffieHellman::computeSharedSecret(const cpp_int& otherPublicKey, const cpp_int& privateKey) {
    return modPow(otherPublicKey, privateKey, p);
}

cpp_int DiffieHellman::modPow(cpp_int base, cpp_int exp, const cpp_int& mod) {
    cpp_int result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

cpp_int DiffieHellman::randomBigInt(int bits) {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());

    cpp_int num = 0;

    for (int i = 0; i < bits; i += 64) {
        num <<= 64;
        num += gen();
    }

    if (bits > 1) {
        num |= cpp_int(1) << (bits - 1);
    }
    num |= 1;

    return num;
}

bool DiffieHellman::isPrime(const cpp_int& n, int iterations) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    cpp_int d = n - 1;
    int r = 0;

    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    for (int i = 0; i < iterations; i++) {
        cpp_int a = 2 + (cpp_int(gen()) % (n - 3));
        cpp_int x = modPow(a, d, n);

        if (x == 1 || x == n - 1) {
            continue;
        }

        bool witnessFound = true;
        for (int j = 0; j < r - 1; j++) {
            x = (x * x) % n;
            if (x == n - 1) {
                witnessFound = false;
                break;
            }
        }

        if (witnessFound) {
            return false;
        }
    }

    return true;
}

cpp_int DiffieHellman::generatePrime(int bits) {
    while (true) {
        cpp_int candidate = randomBigInt(bits);
        if (isPrime(candidate)) {
            return candidate;
        }
    }
}
