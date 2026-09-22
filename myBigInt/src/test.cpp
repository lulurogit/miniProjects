#include "myBigInt.h"

#include <cassert>

void BigInt::testAddSub()
{
    //Normal addition
    {
        BigInt a(5);
        BigInt b(7);
        BigInt sum = a + b;

        assert(sum.m_digits.size() == 1);
        assert(sum.m_isNeg == false);
        assert(sum.m_digits[0] == 12);
    }
    //Negatives addition
    {
        BigInt a(-9);
        BigInt b(-1);
        BigInt sum = a + b;

        assert(sum.m_digits.size() == 1);
        assert(sum.m_isNeg == true);
        assert(sum.m_digits[0] == 10);
    }
    //Addition with carry
    {
        BigInt a(UINT_MAX);
        BigInt b(1);
        BigInt c(999);
        BigInt sum1 = a + b;
        BigInt sum2 = a + c;

        assert(sum1.m_digits.size() == 2);
        assert(sum1.m_isNeg == false);
        assert(sum1.m_digits[0] == 0);
        assert(sum1.m_digits[1] == 1);

        assert(sum2.m_digits.size() == 2);
        assert(sum2.m_isNeg == false);
        assert(sum2.m_digits[0] == 998);
        assert(sum2.m_digits[1] == 1);
    }

    // Normal subtraction
    {
        BigInt a(10);
        BigInt b(4);
        BigInt diff = a - b;

        assert(diff.m_digits.size() == 1);
        assert(diff.m_isNeg == false);
        assert(diff.m_digits[0] == 6);
    }

    // Subtract larger from smaller -> negative result
    {
        BigInt a(7);
        BigInt b(10);
        BigInt diff = a - b;

        assert(diff.m_digits.size() == 1);
        assert(diff.m_isNeg == true);
        assert(diff.m_digits[0] == 3);
    }

    // Multi word addition (carry)
    {
        BigInt a(UINT_MAX);
        BigInt big = a + BigInt(1);
        BigInt res = big - BigInt(1);

        assert(res.m_digits.size() == 1);
        assert(res.m_isNeg == false);
        assert(res.m_digits[0] == UINT_MAX);
    }

    // Sum to empty
    {
        BigInt a;
        BigInt b(5);
        BigInt res = a + b;

        assert(res.m_digits.size() == 1);
        assert(res.m_isNeg == false);
        assert(res.m_digits[0] == 5);
    }

    // Subtraction to 0
    {
        BigInt a(5);
        BigInt b(5);
        BigInt res = a - b;

        assert(res.m_digits.size() == 0);
        assert(res.m_isNeg == false);
        assert(res.m_digits[0] == 0);
    }

    // Subtraction involving negatives: a - (-b) == a + b
    {
        BigInt a(7);
        BigInt b(-3);
        BigInt res = a - b;

        assert(res.m_digits.size() == 1);
        assert(res.m_isNeg == false);
        assert(res.m_digits[0] == 10);

        BigInt c(-6);
        BigInt d(4);
        res = c - d;

        assert(res.m_digits.size() == 1);
        assert(res.m_isNeg == true);
        assert(res.m_digits[0] == 10);
    }

    // Big thing
    {
        BigInt a(false, {123456789, 987654321, 111111111});
        BigInt b(false, {UINT_MAX, UINT_MAX, UINT_MAX});
        BigInt res = a + b ;

        assert(res.m_digits.size() == 4);
        assert(res.m_isNeg == false);
        assert(res.m_digits[0] == 123456788);
        assert(res.m_digits[1] == 987654321);
        assert(res.m_digits[2] == 111111111);
        assert(res.m_digits[3] == 1);

        res = b - a;
        assert(res.m_digits.size() == 3);
        assert(res.m_isNeg == true);
        assert(res.m_digits[0] == UINT_MAX - 123456789);
        assert(res.m_digits[1] == UINT_MAX - 987654321);
        assert(res.m_digits[2] == UINT_MAX - 111111111);
    }
}

int main()
{
    BigInt::testAddSub();
    return 0;
}
