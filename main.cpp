#include <iostream>
#include "Logics.hpp"

void printTest1 (bool const a, bool const b)
{
    std::cout << "|    " << a << "   |    " << b << "   |   " << dd::And (a,b)<< "    |   " << dd::Or (a,b)<< "    |   " << dd::ExOr (a,b)<< "    |   " << dd::NAnd (a,b)<< "    |   " << dd::NOr (a,b)<< "    |";
    std::cout << std::endl;
}

void test1()
{
    std::cout << "****************************" << std::endl;
    std::cout << "* Test of the basic logics *" << std::endl;
    std::cout << "****************************" << std::endl << std::endl;
    std::cout << "|   A    |   B    |A and B | A or B |A exor B|A nand B|A nor B |" << std::endl;
    std::cout << "+--------+--------+--------+--------+--------+--------+--------+" << std::endl;
    printTest1 (false, false);
    printTest1 (false, true);
    printTest1 (true, false);
    printTest1 (true, true);
    std::cout << std::endl;
}

void printTest2 (bool const a, bool const b, bool const carry)
{
    dd::OutAndCarry out {false, false};
    out = dd::Add1Bit (a, b, carry);
    std::cout << "|    " << carry << "   |   " << a << "    |    " << b << "   |    " << out.m_out<< "   |   " << out.m_carry << "    |";
    std::cout << std::endl;
}

void test2()
{
    std::cout << "*********************" << std::endl;
    std::cout << "* Test of Add 1 bit *" << std::endl;
    std::cout << "*********************" << std::endl << std::endl;
    std::cout << "|Carry in|   A    |   B    |  Out   |Carry ou|" << std::endl;
    std::cout << "+--------+--------+--------+--------+--------+" << std::endl;
    printTest2 (false, false, false);
    printTest2 (false, true, false);
    printTest2 (true, false, false);
    printTest2 (true, true, false);
    printTest2 (false, false, true);
    printTest2 (false, true, true);
    printTest2 (true, false, true);
    printTest2 (true, true, true);
    std::cout << std::endl;
}

void printTest3 (int const a, int const b)
{
    std::cout << " A = " << a << ", B = " << b << ", A+B = " << dd::Add4Bit(a, b) << ",";
    std::cout << std::endl;
}

void test3()
{
    std::cout << "*********************" << std::endl;
    std::cout << "* Test of Add 4 bit *" << std::endl;
    std::cout << "*********************" << std::endl << std::endl;
    printTest3 (0, 0);
    printTest3 (1, 0);
    printTest3 (0, 1);
    printTest3 (1, 1);
    printTest3 (5, 9);
    printTest3 (15, 1);
    printTest3 (1, 15);
    printTest3 (15, 15);
    std::cout << std::endl;
}

int main()
{
    test1 ();
    test2 ();
    test3 ();
    return 0;
}
