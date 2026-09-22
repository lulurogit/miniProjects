
#include "myBigInt.h"

#include <algorithm>

BigInt BigInt::operator-() const
{
    BigInt result(*this);
    result.m_isNeg = !m_isNeg;
    return result;
}

bool BigInt::operator<(const BigInt &other) const
{
    return m_digits.size() < other.m_digits.size() || (m_digits.size() == other.m_digits.size() && m_digits.back() < other.m_digits.back());
}

void BigInt::recalcSize()
{
    while (!m_digits.empty() && m_digits.back() == 0)
    {
        m_digits.pop_back();
    }
    if (m_digits.empty())
    {
        m_isNeg = false; // Zero is not negative
    }
}

BigInt BigInt::operator+(const BigInt &other) const
{
    BigInt result;

    if (m_isNeg != other.m_isNeg)
    {
        if (m_isNeg)
        {
            return other - (-(*this));
        }
        else
        {
            return *this - (-other);
        }
    }

    result.m_isNeg = m_isNeg;

    const size_t maxSize = std::max(m_digits.size(), other.m_digits.size());
    unsigned int carry = 0;

    for (size_t i = 0; i < maxSize; ++i)
    {
        unsigned int digit1 = (i < m_digits.size()) ? m_digits[i] : 0;
        unsigned int digit2 = (i < other.m_digits.size()) ? other.m_digits[i] : 0;

        unsigned int sum = digit1 + digit2 + carry;
        carry = (sum < digit1) ? 1 : 0;
        result.m_digits.push_back(sum);
    }
    if (carry > 0)
    {
        result.m_digits.push_back(carry);
    }

    return result;
}

BigInt BigInt::operator-(const BigInt &other) const
{
    BigInt result;

    if (m_isNeg != other.m_isNeg)
    {
        if (m_isNeg)
        {
            return other + (-(*this));
        }
        else
        {
            return *this + (-other);
        }
    }

    const std::vector<unsigned int> &big = (*this < other) ? other.m_digits : m_digits;
    const std::vector<unsigned int> &small = (*this < other) ? m_digits : other.m_digits;
    result.m_isNeg = (*this < other) ? !m_isNeg : m_isNeg;

    const size_t maxSize = big.size();
    unsigned int carry = 0;
    unsigned int diff = 0;

    for (size_t i = 0; i < maxSize; ++i)
    {
        unsigned int digit1 = big[i];
        unsigned int digit2 = (i < small.size()) ? small[i] : 0;

        if (digit1 > digit2)
        {
            diff = digit1 - digit2 - carry;
            carry = 0;
        }
        else if (digit1 == digit2)
        {
            diff = (carry == 1) ? UINT_MAX : 0;
        }
        else
        {
            diff = UINT_MAX - digit2 + digit1 + 1 - carry;
            carry = 1;
        }
        result.m_digits.push_back(diff);
    }
    result.recalcSize();
    return result;
}

// BigInt BigInt::operator*(const BigInt& other ) const;
