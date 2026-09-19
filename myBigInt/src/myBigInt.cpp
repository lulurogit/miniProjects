
#include "myBigInt.h"

#include <algorithm>

BigInt BigInt::operator+(const BigInt &other) const
{
    BigInt result;
    if (m_isNeg == other.m_isNeg)
    {
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
        // } else {
        //     if (m_isNeg) {
        //     } else {
        //     }
    }

    return result;
}
// BigInt BigInt::operator-(const BigInt& other ) const;
// BigInt BigInt::operator*(const BigInt& other ) const;
