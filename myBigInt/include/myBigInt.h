#pragma once

#include <vector>

class BigInt {
public:
    BigInt() : m_isNeg(false), m_digits() {}
    BigInt(unsigned int value) : m_isNeg(false), m_digits(1, value) {}
    BigInt(int value) : m_isNeg(value < 0), m_digits(1, static_cast<unsigned int>(value < 0 ? -value : value)) {}

    static void testAddition();

    BigInt operator+(const BigInt& other ) const;
    BigInt operator-(const BigInt& other ) const;
    BigInt operator*(const BigInt& other ) const;
    // BigInt operator/(const BigInt& other ) const;
private:
    bool m_isNeg;
    std::vector<unsigned int> m_digits;
};
