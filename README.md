# Diffie-Hellman Key Exchange in C++
## Features
- Uses `boost::multiprecision::cpp_int` for large integer support
- Implements modular exponentiation from scratch
- Implements Miller-Rabin primality testing from scratch
- Generates a large prime number
- Simulates key exchange between Alice and Bob

## Files
- `DiffieHellman.h` - class declaration
- `DiffieHellman.cpp` - class 
- `main.cpp` - main program

## How it works
1. A large prime `p` is generated.
2. A generator `g` is chosen.
3. People say X and Y generate private keys.
4. They compute public keys using modular exponentiation.
5. They exchange public keys.
6. Both compute the same shared secret independently.

## Build
Use a C++17 compiler with Boost available.

```bash
g++ main.cpp DiffieHellman.cpp -o dh -std=c++17
```

## Run
```bash
./dh
```

## Sample output
The exact values change every run because keys and primes are generated randomly.

```text
Public Prime (p): 
Generator (g): 2
Alice Private Key: 
Alice Public Key: 
Bob Private Key: 
Bob Public Key:
Alice Shared Secret: 
Bob Shared Secret:
Key Exchange Successful: Shared secrets match
```

