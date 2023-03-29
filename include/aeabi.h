/*
===============================================================================

 C header file for aeabi

 Copyright (C) 2021-2022 agbabi contributors
 For conditions of distribution and use, see copyright notice in LICENSE.md

===============================================================================
*/

#ifndef _AEABI_H_
#define _AEABI_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "stddef.h"

/// Copies n bytes from src to dest (forward)
/// \param dest Destination address
/// \param src Source address
/// \param n Number of bytes to copy
void __aeabi_memcpy(void *__restrict__ dest, const void *__restrict__ src, size_t n);

/// Copies n bytes from src to dest (forward)
/// Assumes dest and src are 4-byte aligned
/// \param dest Destination address
/// \param src Source address
/// \param n Number of bytes to copy
void __aeabi_memcpy4(void *__restrict__ dest, const void *__restrict__ src, size_t n);

/// Alias of __aeabi_memcpy4
/// \param dest Destination address
/// \param src Source address
/// \param n Number of bytes to copy
void __aeabi_memcpy8(void *__restrict__ dest, const void *__restrict__ src, size_t n);

/// Set n bytes of dest to (c & 0xff)
/// \param dest Destination address
/// \param n Number of bytes to set
/// \param c Value to set
void __aeabi_memset(void *dest, size_t n, int c);

/// Set n bytes of dest to (c & 0xff)
/// Assumes dest is 4-byte aligned
/// \param dest Destination address
/// \param n Number of bytes to set
/// \param c Value to set
void __aeabi_memset4(void *dest, size_t n, int c);

/// Alias of __aeabi_memset4
/// \param dest Destination address
/// \param n Number of bytes to set
/// \param c Value to set
void __aeabi_memset8(void *dest, size_t n, int c);

/// Clears n bytes of dest to 0
/// \param dest Destination address
/// \param n Number of bytes to clear
void __aeabi_memclr(void *dest, size_t n);

/// Clears n bytes of dest to 0
/// Assumes dest is 4-byte aligned
/// \param dest Destination address
/// \param n Number of bytes to clear
void __aeabi_memclr4(void *dest, size_t n);

/// Alias of __aeabi_memclr4
/// \param dest Destination address
/// \param n Number of bytes to clear
void __aeabi_memclr8(void *dest, size_t n);

/// Safely copies n bytes of src to dest
/// \param dest Destination address
/// \param src Source address
/// \param n Number of bytes to copy
void __aeabi_memmove(void *dest, const void *src, size_t n);

/// Safely copies n bytes of src to dest
/// Assumes dest and src are 4-byte aligned
/// \param dest Destination address
/// \param src Source address
/// \param n Number of bytes to copy
void __aeabi_memmove4(void *dest, const void *src, size_t n);

/// Alias of __aeabi_memmove4
/// \param dest Destination address
/// \param src Source address
/// \param n Number of bytes to copy
void __aeabi_memmove8(void *dest, const void *src, size_t n);

/// Signed 32-bit division
/// \param numerator
/// \param denominator
/// \return quotient
int __aeabi_idiv(int numerator, int denominator);

/// Unsigned 32-bit division
/// \param numerator
/// \param denominator
/// \return quotient
unsigned int __aeabi_uidiv(unsigned int numerator, unsigned int denominator);

/// Signed 64-bit division
/// \param numerator
/// \param denominator
/// \return quotient
long long __aeabi_ldiv(long long numerator, long long denominator);

/// Unsigned 64-bit division
/// \param numerator
/// \param denominator
/// \return quotient
unsigned long long __aeabi_uldiv(unsigned long long numerator, unsigned long long denominator);

/// 64-bit multiplication
/// \param a
/// \param b
/// \return a * b
long long __aeabi_lmul(long long a, long long b);

/// 64-bit logical shift left
/// \param x
/// \param n
/// \return x << n
long long __aeabi_llsl(long long x, int n);

/// 64-bit logical shift right
/// \param x
/// \param n
/// \return (unsigned long long) x >> n
long long __aeabi_llsr(long long x, int n);

/// 64-bit arithmetic shift right
/// \param x
/// \param n
/// \return x >> n
long long __aeabi_lasr(long long x, int n);

#if defined __has_attribute
#if __has_attribute(__vector_size__)

/// Signed 32-bit division and modulo
/// \param numerator
/// \param denominator
/// \return [quotient, remainder]
int __attribute__((__vector_size__(8))) __aeabi_idivmod(int numerator, int denominator);

/// Unsigned 32-bit division and modulo
/// \param numerator
/// \param denominator
/// \return [quotient, remainder]
unsigned int __attribute__((__vector_size__(8))) __aeabi_uidivmod(unsigned int numerator, unsigned int denominator);

/// Signed 64-bit division and modulo
/// \param numerator
/// \param denominator
/// \return [quotient, remainder]
long long __attribute__((__vector_size__(16))) __aeabi_ldivmod(long long numerator, long long denominator);

/// Unsigned 64-bit division and modulo
/// \param numerator
/// \param denominator
/// \return [quotient, remainder]
unsigned long long __attribute__((__vector_size__(16))) __aeabi_uldivmod(unsigned long long numerator, unsigned long long denominator);

#endif
#endif

#ifdef __cplusplus
}
#endif
#endif // _AEABI_H_
