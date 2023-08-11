#ifndef SRC_DECIMAL_FUNCTIONS_S21_DECIMAL_H_
#define SRC_DECIMAL_FUNCTIONS_S21_DECIMAL_H_

#define SIZE 32

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define U_MAX_INT 4294967295

typedef struct {
  int bits[4];
} s21_decimal;

#define DEC_28_DIGITS                                                         \
  (s21_decimal) {                                                             \
    {                                                                         \
      0b00010000000000000000000000000000, 0b00111110001001010000001001100001, \
          0b00100000010011111100111001011110,                                 \
          0b00000000000000000000000000000000                                  \
    }                                                                         \
  }

#define DEC_ZERO   \
  (s21_decimal) {  \
    { 0, 0, 0, 0 } \
  }

#define DEC_TEN     \
  (s21_decimal) {   \
    { 10, 0, 0, 0 } \
  }

#define DEC_ONE    \
  (s21_decimal) {  \
    { 1, 0, 0, 0 } \
  }
//  вспомогательные функции
int s21_get_bit(s21_decimal decimal, int index);
void s21_set_bit(s21_decimal *decimal, int index, int v_bit);
int s21_get_sign(s21_decimal decimal);
void s21_set_sign(s21_decimal *decimal, int sign);
int s21_get_power(s21_decimal decimal);
void s21_set_power(s21_decimal *decimal, int power);
int s21_is_correct_decimal(s21_decimal decimal);
char *s21_decimal_to_string(s21_decimal value);

int s21_shift_left(s21_decimal *value);
void s21_shift_right(s21_decimal *value);

void s21_print_int_value(s21_decimal dec);
char *s21_bitwise_int_to_str(int a);

// void bank_round_if_need(int *power, s21_decimal *res);

//  вспомогательные арифмитические функции
s21_decimal s21_bank_round(s21_decimal *value);
s21_decimal s21_div_10(s21_decimal *value_1);
int s21_equal_power(s21_decimal *value_1, s21_decimal *value_2);
int s21_mul_10(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_signif_bit(s21_decimal value_1);
int s21_signif_digits(s21_decimal value);
int s21_simplified_add(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
s21_decimal s21_simplified_div(s21_decimal value_1, s21_decimal value_2,
                               s21_decimal *result);
int s21_simplified_mul(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
int s21_simplified_sub(s21_decimal value_1, s21_decimal value_2,
                       s21_decimal *result);
int s21_is_zero(s21_decimal value);
void s21_splitting(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *int_v1, s21_decimal *int_v2,
                   s21_decimal *frac_v1, s21_decimal *frac_v2);
int s21_addit_int_frac_mul(s21_decimal value_1, s21_decimal value_2,
                           s21_decimal *result, int digits_i, int digits_f);
int s21_addit_frac_frac_mul(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *result, int digits_f_1,
                            int digits_f_2);
void s21_bank_if_need(int *power, s21_decimal *res);

//  арифмитические функции
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//  функции сравнения
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater_simplified(s21_decimal value_1, s21_decimal value_2);

//  другие функции
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value_1, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

//  Conversion functions
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

//  Helper functions
char *s21_bitwise_int_to_str(int a);
int bits_quantity(s21_decimal value);
int exp_check(s21_decimal value_1, s21_decimal value_2);
void simple_dividing(s21_decimal *remainder, s21_decimal *quotient,
                     s21_decimal value_1, s21_decimal value_2);

void print_bits(s21_decimal decimal);

void s21_set_bit_1(s21_decimal *decimal, int index);
void s21_set_bit_0(s21_decimal *decimal, int index);

#endif  // SRC_DECIMAL_FUNCTIONS_S21_DECIMAL_H_
