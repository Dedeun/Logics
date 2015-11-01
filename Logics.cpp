#include <cstddef>
#include "logics.hpp"

// Function Not
bool dd::Not (const bool a)
{
    return (! a);
}

// function And
bool dd::And (const bool a, const bool b)
{
    return (a & b);
}

// function And
bool dd::And (const bool a, const bool b, const bool c)
{
    return (a & b & c);
}

// function Or
bool dd::Or (const bool a, const bool b)
{
    return (a | b);
}

// function Or (3 inputs)
bool dd::Or (const bool a, const bool b, const bool c)
{
    return (a | b | c);
}

// function ExOr
bool dd::ExOr (const bool a, const bool b)
{
    return (a ^ b);
}

// function NAnd
bool dd::NAnd (const bool a, const bool b)
{
    return (dd::Not (And (a, b)));
}

// function NAnd (3 inputs)
bool dd::NAnd (const bool a, const bool b, const bool c)
{
    return dd::Not (And (a, b, c));
}

// function NAnd (4 inputs)
bool dd::NAnd (const bool a, const bool b, const bool c, const bool d)
{
    return dd::Not (dd::And (dd::And(a, b), dd::And(c, d)));
}

// Function  NOr
bool dd::NOr (const bool a, const bool b)
{
    return (dd::Not (dd::Or(a, b)));
}

// function Add1Bit
dd::OutAndCarry dd::Add1Bit (const bool a, const bool b, const bool carry)
{
    dd::OutAndCarry out {false, false};
//    // Simplest solution (with EXOR)
//    out.m_out = ExOr (ExOr (a, b), carry);
    // with only NAnd functions (3 and 4 inputs)
    out.m_out = dd::NAnd (dd::NAnd (a, dd::NAnd (b, b), dd::NAnd (carry, carry)),
                          dd::NAnd (dd::NAnd (a, a), b, dd::NAnd (carry, carry)),
                          dd::NAnd (dd::NAnd (a, a), dd::NAnd (b, b), carry),
                          dd::NAnd (a, b, carry));
//    // Simplest solution (with OR and AND)
//    out.m_carry = Or (And (a,b), And (a,carry),And (b,carry));
    // with only NAnd functions (2 and 3 functions)
    out.m_carry = dd::NAnd (dd::NAnd (a,b), dd::NAnd (a,carry), dd::NAnd (b,carry));
    return (out);
}

// function setBitN
int dd::setBitN (int number, int * integer)
{
    (*integer) |= (1 << number);
    return (*integer);
}

// Function resetBitN
int dd::resetBitN (int number, int * integer)
{
    (*integer) &= ~(1 << number);
    return (*integer);
}

// function Add4Bits
int dd::Add4Bit (const int a, const int b)
{
    dd::OutAndCarry out {false, false};
    int result {0};
    std::size_t i{0};
    for (i =0; i<4; i++) {
        bool a1 = (a >> i) & 0x0001;
        bool b1 = (b >> i) & 0x0001;
        out = dd::Add1Bit (a1, b1, out.m_carry);
        if (out.m_out) {
            dd::setBitN(i, &result);
        } // end if
//        result |= (out.m_out << i);
    } // end for
    if (out.m_carry) {
        dd::setBitN(i, &result);
    } // end if
//    result |= (out.m_carry << i);
    return result;
}

