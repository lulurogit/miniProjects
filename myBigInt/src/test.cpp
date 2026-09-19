#include "myBigInt.h"

#include <cassert>

void BigInt::testAddition()
{
    //Normal addition
    {
        BigInt a(5);
        BigInt b(7);
        BigInt sum = a + b;

        assert(sum.m_digits.size() == 1);
        assert(sum.m_isNeg == false);
        assert(sum.m_digits[0] == 12u);
    }
    //Negatives addition
    {
        BigInt a(-9);
        BigInt b(-1);
        BigInt sum = a + b;

        assert(sum.m_digits.size() == 1);
        assert(sum.m_isNeg == true);
        assert(sum.m_digits[0] == 10u);
    }
    //Addition with carry
    {
        BigInt a(UINT_MAX);
        BigInt b(1u);
        BigInt c(999u);
        BigInt sum1 = a + b;
        BigInt sum2 = a + c;

        assert(sum1.m_digits.size() == 2);
        assert(sum1.m_isNeg == false);
        assert(sum1.m_digits[0] == 0u);
        assert(sum1.m_digits[1] == 1u);

        assert(sum2.m_digits.size() == 2);
        assert(sum2.m_isNeg == false);
        assert(sum2.m_digits[0] == 998u);
        assert(sum2.m_digits[1] == 1u);
    }
}

int main()
{
    BigInt::testAddition();
    return 0;
}
