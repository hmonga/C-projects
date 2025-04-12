/* Includes you should need */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define ROUNDUP 0
#define ROUNDDOWN 1
#define ROUNDTOEVEN 2

/**
 * Part 1.1
 * @brief You'll be converting a Binary string into it's unsigned decimal value.
 * @param input_string the binary string you'll be converting to decimal.
 * @return the converting decimal value (an unsigned long)
 */
unsigned long binary_to_unsigned_decimal(const char *input_string)
{
    unsigned long sum = 0;
    int num_bits = strlen(input_string);

    for (int i = 0; i < num_bits; i++)
    {
        if (input_string[i] == '1')
        {
            sum += 1UL << (num_bits - 1 - i);
        }
    }
    return sum;
}

/**
 * Part 1.2
 * @brief You'll be converting a binary string into it's decimal value using the signed magnitude representation
 * @param input_string, the binary string you'll be converting to decimal
 * @return the signed decimal value (a signed long type using signed magnitude)
 */
long binary_to_signed_magnitude_decimal(const char *input_string)
{
    int length = strlen(input_string);

    int sign_bit = input_string[0] - '0';

    long magnitude = 0;

    for (int i = 1; i < length; i++)
    {
        magnitude = (magnitude << 1) | (input_string[i] - '0');
    }

    if (sign_bit == 1)
    {
        return -magnitude;
    }
    else
    {
        return magnitude;
    }
}

/**
 * Part 1.2
 * @brief You'll be converting a binary string into it's decimal value using ones complement.
 * @param input_string, the binary string you'll be converting to decimal
 * @return the signed decimal value (a signed long type using ones complement)
 */
long binary_to_ones_complement_decimal(const char *input_string)
{
    int length = strlen(input_string);
    int sign_bit = input_string[0] - '0';

    long result = 0;

    if (sign_bit == 1)
    {
        for (int i = 1; i < length; i++)
        {
            if (input_string[i] == '0')
            {
                result = (result << 1) | 1;
            }
            else
            {
                result = (result << 1) | 0;
            }
        }
        return -result;
    }
    else
    {
        for (int i = 1; i < length; i++)
        {
            result = (result << 1) | (input_string[i] - '0');
        }
        return result;
    }
}

/**
 * Part 1.4
 * @brief Convert a Binary string into it's decimal value using twos complement.
 * @param input_string: The string you're going to convert to decimal
 * @return the unsigned long using twos complement
 */
long binary_to_twos_complement_decimal(const char *input_string)
{
    int length = strlen(input_string);
    int sign_bit = input_string[0] - '0';
    long result = 0;

    if (sign_bit == 1)
    {
        result = -(1L << (length - 1));

        for (int i = 1; i < length; i++)
        {
            if (input_string[i] == '1')
            {
                result += (1L << (length - 1 - i));
            }
        }
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (input_string[i] == '1')
            {
                result += (1L << (length - 1 - i));
            }
        }
    }
    return result;
}

/**
 * part 2.1
 * @brief In this part, you'll be converting an unsigned decimal value into it's unsigned binary representation
 * @param input The decimal value you'll be converting to binary
 * @param numbits The the bitwidth of your converted value.
 * @return the binary string (you should be allocating the string on the heap!)
 */
char *unsigned_decimal_to_binary(unsigned long input, unsigned int numbits)
{
    char *binary = (char *)malloc(numbits + 1);
    if (binary == NULL)
    {
        return NULL;
    }

    binary[numbits] = '\0';

    for (int i = 0; i < numbits; i++)
    {
        unsigned long power = 1UL << (numbits - 1 - i);
        if (power <= input)
        {
            binary[i] = '1';
            input -= power;
        }
        else
        {
            binary[i] = '0';
        }
    }

    return binary;
}

/**
 * part 2.1
 * @brief In this part, you'll be converting an unsigned decimal value into it's binary representation using signed magnitude
 * @param input The decimal value you'll be converting to binary
 * @param numbits The the bitwidth of your converted value.
 * @return the binary string (you should be allocating the string on the heap!)
 */
char *signed_decimal_to_signed_magnitude(long input, unsigned int numbits)
{
    if (numbits < 2)
        return NULL;

    char *binary = (char *)malloc(numbits + 1);
    if (binary == NULL)
    {
        return NULL;
    }

    binary[numbits] = '\0';

    if (input < 0)
    {
        binary[0] = '1';
        input = -input;
    }
    else
    {
        binary[0] = '0';
    }

    for (int i = 1; i < numbits; i++)
    {
        unsigned long power = 1UL << (numbits - 1 - i);
        if (power <= input)
        {
            binary[i] = '1';
            input -= power;
        }
        else
        {
            binary[i] = '0';
        }
    }

    return binary;
}

/**
 * part 2.1
 * @brief In this part, you'll be converting an unsigned decimal value into it's ones complement binary representation
 * @param input The decimal value you'll be converting to binary
 * @param numbits The the bitwidth of your converted value.
 * @return the binary string (you should be allocating the string on the heap!)
 */
char *signed_decimal_to_ones_complement(long input, unsigned int numbits)
{
    if (numbits == 0) return NULL;

    char *bin = malloc(numbits + 1);
    if (!bin) return NULL;
    bin[numbits] = '\0';

    // Get absolute value
    unsigned long val = (input < 0) ? -input : input;

    // Convert to binary
    for (int i = 0; i < (int)numbits; i++) {
        int bit_index = numbits - 1 - i;
        if ((1UL << bit_index) <= val) {
            bin[i] = '1';
            val -= (1UL << bit_index);
        } else {
            bin[i] = '0';
        }
    }

    // If negative, flip all bits (one's complement)
    if (input < 0) {
        for (int i = 0; i < (int)numbits; i++) {
            bin[i] = (bin[i] == '1') ? '0' : '1';
        }
    }

    return bin;
}

/**
 * part 2.1
 * @brief In this part, you'll be converting an unsigned decimal value into it's two complement binary representation
 * @param input The decimal value you'll be converting to binary
 * @param numbits The the bitwidth of your converted value.
 * @return the binary string (you should be allocating the string on the heap!)
 */
char *signed_decimal_to_twos_complement(long input, unsigned int numbits)
{
    if (numbits < 1)
    {
        return NULL;
    }

    char *binary = (char *)malloc(numbits + 1);
    if (binary == NULL)
    {
        return NULL;
    }

    binary[numbits] = '\0';

    unsigned long value;
    if (input < 0)
    {
        value = (1UL << numbits) + input;
    }
    else
    {
        value = input;
    }

    for (int i = numbits - 1; i >= 0; i--)
    {
        if ((value & 1) == 1)
        {
            binary[i] = '1';
        }
        else
        {
            binary[i] = '0';
        }
        value >>= 1;
    }

    return binary;
}

/**
 * Part 3.1
 * @brief In this part, you'll be converting an ieee754 string with a specified number of exponent and mantissa bits into it's decimal value (always 1 sign bit).
 * @param input the ieee 754 string to convert into it's decimal value.
 * @param exp The number of exponent bits in the input string.
 * @param mantissa The number of mantissa bits in the input string.
 */
double ieee754_to_decimal(char *input, int exp_bits, int mant_bits)
{
    int total_len = 1 + exp_bits + mant_bits;
    if ((int)strlen(input) != total_len) return NAN;

    // sign
    int sign = (input[0] == '1') ? -1 : 1;

    // exponent
    int exp_val = 0;
    for (int i = 0; i < exp_bits; i++) {
        if (input[1 + i] == '1') {
            exp_val |= (1 << (exp_bits - 1 - i));
        }
    }

    // mantissa (fractional part)
    double frac = 0;
    for (int i = 0; i < mant_bits; i++) {
        if (input[1 + exp_bits + i] == '1') {
            frac += pow(2, -(i + 1));
        }
    }

    int bias = (1 << (exp_bits - 1)) - 1;

    // Special cases
    int is_all_ones_exp = (exp_val == (1 << exp_bits) - 1);
    int is_all_zeros_exp = (exp_val == 0);
    int is_zero_mant = 1;

    for (int i = 0; i < mant_bits; i++) {
        if (input[1 + exp_bits + i] == '1') {
            is_zero_mant = 0;
            break;
        }
    }

    if (is_all_ones_exp && is_zero_mant) return sign * INFINITY;
    if (is_all_ones_exp && !is_zero_mant) return NAN;

    if (is_all_zeros_exp) {
        return sign * frac * pow(2, 1 - bias); // denormalized
    }

    return sign * (1.0 + frac) * pow(2, exp_val - bias); // normalized
}

/**
 * part 3.2
 * @brief In this part, you'll be converting a decimal value, and converting it into it's ieee 754 representation given the number of exp, mantissa bits, and what rounding mode to use.
 * @param input The number you'll be converting into it's ieee 754 representation
 * @param exp_bits The number of exponent bits your representation should have.
 * @param mantissa_bits The number of mantissa bits your representation should have.
 * @param rounding_mode The rounding mode you should use: 0 to round up, 1 to round down, 2 for round to even.
 */
char *decimal_to_ieee754_binary(double input, int exp_bits, int mantissa_bits, int rounding_mode)
{
    if (input == 0.0)
    {
        char *zero = malloc(exp_bits + mantissa_bits + 2);
        if (!zero)
            return NULL;
        memset(zero, '0', exp_bits + mantissa_bits + 1);
        zero[exp_bits + mantissa_bits + 1] = '\0';
        return zero;
    }

    char *result = malloc(1 + exp_bits + mantissa_bits + 1);
    if (!result)
        return NULL;

    int sign = input < 0;
    result[0] = sign ? '1' : '0';
    if (sign)
        input = -input;

    // Normalize input
    int E = 0;
    double norm = input;
    while (norm >= 2.0)
    {
        norm /= 2.0;
        E++;
    }
    while (norm < 1.0)
    {
        norm *= 2.0;
        E--;
    }

    int bias = (1 << (exp_bits - 1)) - 1;
    int exp = E + bias;
    if (exp < 0 || exp >= (1 << exp_bits))
    {
        free(result);
        return NULL; // Overflow
    }

    // Set exponent bits
    for (int i = 0; i < exp_bits; i++)
    {
        result[1 + i] = ((exp >> (exp_bits - 1 - i)) & 1) + '0';
    }

    // Generate mantissa (with a few extra bits for rounding)
    char temp[64] = {0}; // generous space
    double frac = norm - 1.0;
    for (int i = 0; i < mantissa_bits + 3; i++)
    {
        frac *= 2;
        temp[i] = (frac >= 1.0) ? '1' : '0';
        if (frac >= 1.0)
            frac -= 1.0;
    }

    // Basic rounding logic
    int g = temp[mantissa_bits] == '1';
    int r = temp[mantissa_bits + 1] == '1';
    int s = 0;
    for (int i = mantissa_bits + 2; i < mantissa_bits + 3; i++)
    {
        if (temp[i] == '1')
        {
            s = 1;
            break;
        }
    }

    int round_up = 0;
    if (rounding_mode == ROUNDUP)
    {
        round_up = g || r || s;
    }
    else if (rounding_mode == ROUNDTOEVEN)
    {
        round_up = g && (r || s || temp[mantissa_bits - 1] == '1');
    }

    // Copy mantissa
    strncpy(&result[1 + exp_bits], temp, mantissa_bits);

    // Handle rounding overflow
    if (round_up)
    {
        for (int i = mantissa_bits - 1; i >= 0; i--)
        {
            if (result[1 + exp_bits + i] == '0')
            {
                result[1 + exp_bits + i] = '1';
                break;
            }
            else
            {
                result[1 + exp_bits + i] = '0';
                if (i == 0)
                {
                    exp++;
                    if (exp >= (1 << exp_bits))
                    {
                        // overflow again
                        for (int j = 0; j < exp_bits; j++)
                            result[1 + j] = '1';
                        for (int j = 0; j < mantissa_bits; j++)
                            result[1 + exp_bits + j] = '0';
                        result[1 + exp_bits + mantissa_bits] = '\0';
                        return result;
                    }
                    for (int j = 0; j < exp_bits; j++)
                    {
                        result[1 + j] = ((exp >> (exp_bits - 1 - j)) & 1) + '0';
                    }
                }
            }
        }
    }

    result[1 + exp_bits + mantissa_bits] = '\0';
    return result;
}