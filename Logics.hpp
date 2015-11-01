#ifndef LOGICS_HPP
#define LOGICS_HPP

///  \file   Logics.hpp
///  \brief  This file is a short mathematical library which manage the low level operation:
///          AND, OR, NOT, ADD, ... (Boolean algebra)
///  \author Dedeun
///  \date   1st November 2015
///  \version Alpha 1

namespace dd {

    /// \fn     Not
    /// \brief  return Not A
    /// \param  boolean A
    /// \return Not (A)
    bool Not (const bool a);

    /// \fn     And
    /// \brief  return (A And B)
    /// \param  boolean A
    /// \param  boolean B
    /// \return (A And B)
    bool And (const bool a, const bool b);

    /// \fn     And
    /// \brief  return (A And B)
    /// \param  boolean A
    /// \param  boolean B
    /// \return (A And B)
    bool And (const bool a, const bool b, const bool c);

    /// \fn     Or
    /// \brief  return (A Or B)
    /// \param  boolean A
    /// \param  boolean B
    /// \return (A Or B)
    bool Or (const bool a, const bool b);

    /// \fn     Or
    /// \brief  return (A Or B)
    /// \param  boolean A
    /// \param  boolean B
    /// \return (A Or B)
    bool Or (const bool a, const bool b, const bool c);

    /// \fn     ExOr
    /// \brief  return (A ExOr B)
    /// \param  boolean A
    /// \param  boolean B
    /// \return (A ExOr B)
    bool ExOr (const bool a, const bool b);

    /// \fn     NAnd
    /// \brief  return (A NAnd B)
    /// \param  boolean A
    /// \param  boolean B
    /// \return (A NAnd B)
    bool NAnd (const bool a, const bool b);

    /// \fn     NAnd
    /// \brief  return (A NAnd B NAnd C): 3 inputs
    /// \param  boolean A
    /// \param  boolean B
    /// \param  boolean C
    /// \return (A NAnd B NAnd C)
    bool NAnd (const bool a, const bool b, const bool c);

    /// \fn     NAnd
    /// \brief  return (A NAnd B NAnd C NAnd D): 4 inputs
    /// \param  boolean A
    /// \param  boolean B
    /// \param  boolean C
    /// \param  boolean D
    /// \return (A NAnd B NAnd C NAnd D)
    bool NAnd (const bool a, const bool b, const bool c, const bool d);

    /// \fn     NOr
    /// \brief  return (A NOr B)
    /// \param  boolean A
    /// \param  boolean B
    /// \return (A NOr B)
    bool NOr (const bool a, const bool b);

    /// \struct result of the addition of 2 * 1 bit
    struct OutAndCarry {
        /// \var   m_out
        /// \brief value of the output bit
        bool m_out;
        /// \var   m_carry
        /// \brief value of the carry bit
        bool m_carry;
    };

    /// \fn     Add1Bit
    /// \brief  return (A + B + Carry)
    /// \param  boolean A
    /// \param  boolean B
    /// \param  boolean Carry
    /// \return struct (OutAndCarry: bool Out, bool Carry)
    OutAndCarry Add1Bit (const bool a, const bool b, const bool carry);

    /// \fn     setBitN
    /// \brief  Set one bit of an integer
    /// \param  int number: number of the bit to set
    /// \param  int integer: pointer to the integer to be modified
    /// \return int : integer modified
    int setBitN (int number, int * integer);

    /// \fn     resetBitN
    /// \brief  Reset one bit of an integer
    /// \param  int number: number of the bit to reset
    /// \param  int integer: pointer to the integer to be modified
    /// \return int : integer modified
    int resetBitN (int number, int * integer);

    /// \fn     Add4Bits
    /// \brief  return (A + B) on 5 bits
    /// \param  int A
    /// \param  int B
    /// \return int (A + B)
    int Add4Bit (const int a, const int b);


} // end namespace
#endif // LOGICS_HPP
