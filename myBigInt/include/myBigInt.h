#pragma once

#include <vector>

class BigInt {
public:
    BigInt() : m_isNeg(false), m_digits() {}
    BigInt(unsigned int value) : m_isNeg(false), m_digits(1, value) {}
    BigInt(int value) : m_isNeg(value < 0), m_digits(1, static_cast<unsigned int>(value < 0 ? -value : value)) {}
    BigInt(bool isNeg, const std::vector<unsigned int> &digits) : m_isNeg(isNeg), m_digits(digits) {}
    BigInt(const BigInt &other) : m_isNeg(other.m_isNeg), m_digits(other.m_digits) {}

    static void testAddSub();
    

    BigInt operator-() const;
    bool operator<(const BigInt &other) const;
    void recalcSize();

    BigInt operator+(const BigInt &other ) const;
    BigInt operator-(const BigInt &other ) const;
    BigInt operator*(const BigInt &other ) const;
    // BigInt operator/(const BigInt& other ) const;

private:
    bool m_isNeg;
    std::vector<unsigned int> m_digits;
};
