#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int overflow = 0;
  if (!result) {
    overflow = 1;
  } else {
    *result = DEC_ZERO;
    s21_truncate(value, result);
    if (s21_get_sign(value)) s21_sub(*result, DEC_ONE, result);
    s21_set_sign(result, s21_get_sign(value));
  }
  return overflow;
}

int s21_negate(s21_decimal value_1, s21_decimal *result) {
  int res = 0;
  if (!result) {
    res = 1;
  } else if (!s21_is_correct_decimal(value_1)) {
    res = 1;
  } else {
    *result = value_1;
    int sign = s21_get_sign(value_1);
    if (sign)
      sign = 0;
    else
      sign = 1;
    s21_set_sign(result, sign);
    if (result)
      res = 0;
    else
      res = 1;
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  *result = DEC_ZERO;
  s21_decimal truncate_value = DEC_ZERO, truncate_value1 = DEC_ZERO,
              truncate_value2 = DEC_ZERO, sub_value = DEC_ZERO,
              for_comparison_pos = {{5, 0, 0, 0}},
              for_comparison_neg = {{5, 0, 0, 0}};
  s21_set_sign(&for_comparison_neg, 1);
  int sign = s21_get_sign(value);
  int flag = 0;
  s21_truncate(value, result);
  s21_simplified_mul(value, DEC_TEN, &truncate_value);
  s21_set_power(&truncate_value, s21_get_power(value));
  s21_truncate(truncate_value, &truncate_value1);
  s21_truncate(value, &truncate_value2);
  s21_simplified_mul(truncate_value2, DEC_TEN, &truncate_value2);
  s21_sub(truncate_value1, truncate_value2, &sub_value);
  s21_set_sign(&sub_value, sign);
  if (s21_is_greater_or_equal(sub_value, for_comparison_pos) && !sign) {
    s21_add(*result, DEC_ONE, result);
  } else if (s21_is_less_or_equal(sub_value, for_comparison_neg) && sign) {
    s21_sub(*result, DEC_ONE, result);
  }
  s21_set_sign(result, sign);
  return flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (!result) {
    error = 1;
  } else {
    s21_decimal buffer1 = DEC_ZERO, buffer2 = DEC_ZERO;
    *result = DEC_ZERO;
    int sign = s21_get_sign(value);
    int exponent = s21_get_power(value);
    if (!s21_is_correct_decimal(value)) {
      error = 1;
    } else if (!exponent || ((value.bits[0] == 0) && (value.bits[1] == 0) &&
                             (value.bits[2] == 0))) {
      s21_set_power(&value, 0);
      *result = value;
    } else {
      value.bits[3] = 0;
      s21_decimal number_of_divisions = DEC_ONE;
      for (int i = 0; i < exponent; i++) {
        s21_simplified_mul(number_of_divisions, DEC_TEN, &number_of_divisions);
      }
      simple_dividing(&buffer1, &buffer2, value, number_of_divisions);
      *result = buffer2;
    }
    s21_set_sign(result, sign);
  }
  return error;
}
