#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  if (!dst) {
    error = 1;
  } else if (!s21_is_correct_decimal(src)) {
    error = 1;
    *dst = 0.0;
  } else {
    *dst = 0.0;
    double tmp = 0.00000000;
    int sign = s21_get_sign(src);
    int exponent = s21_get_power(src);
    for (int i = 0; i < 96; i++) {
      tmp += (s21_get_bit(src, i) * pow(2.0, i));
    }
    double power_of_new_number = pow(10, exponent);
    tmp /= power_of_new_number;
    if (sign) {
      tmp *= -1.0;
    }
    *dst = (float)tmp;
  }
  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int tmp = 0, flag = 0;
  int sign = s21_get_sign(src);
  s21_decimal truncated = DEC_ZERO;
  int truncate_err_flag = s21_truncate(src, &truncated);
  if (truncate_err_flag) {
    flag = 1;
  } else if (!dst) {
    flag = 1;
  } else if (!s21_is_correct_decimal(src)) {
    flag = 1;
  } else if (s21_is_less(truncated, (s21_decimal){{0x80000000, 0x00000000,
                                                   0x00000000, 0x80000000}})) {
    flag = 1;
  } else if (s21_is_greater(truncated,
                            (s21_decimal){{0x7FFFFFFF, 0x00000000, 0x00000000,
                                           0x00000000}})) {
    flag = 1;
  } else {
    *dst = 0;
    for (int i = 0; i < 32; i++) {
      tmp += s21_get_bit(truncated, i) * pow(2, i);
    }
    if (sign) tmp *= -1;
    *dst = tmp;
  }
  return flag;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0, sign = 0, current_bit;
  if (!dst) {
    error = 1;
  } else {
    *dst = DEC_ZERO;
    sign = (src < 0) ? 1 : 0;
    if (src >= pow(2, 96) || (-1e-28 < src && src < 1e-28 && src != 0)) {
      error = 1;
    }
    double lsrc = fabs(src);
    int digits_in_src = 0;
    double tempsrc = lsrc;
    while (tempsrc > 1.0) {
      tempsrc /= 10;
      digits_in_src++;
    }
    if (digits_in_src > 28) {
      error = 1;
    }
    int precision = 0;
    for (int f = 0; f < 6 && (digits_in_src < 29) && (lsrc * 10 < pow(2, 96));
         f++, digits_in_src++) {
      precision = f + 1;
      lsrc *= 10;
    }
    lsrc = round(lsrc);
    while (fmod(lsrc, 10) == 0.0 && precision > 0) {
      lsrc /= 10;
      precision--;
    }
    int i = 0;
    for (; i < 96 && error == 0; i++) {
      current_bit = (lsrc > 0) ? fmod(lsrc, 2.0) : 0;
      s21_set_bit(dst, i, current_bit);
      lsrc /= 2;
    }
    s21_set_power(dst, precision);
    s21_set_sign(dst, sign);
  }
  if (error) *dst = DEC_ZERO;
  return error;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (!dst) {
    error = 1;
  } else {
    int current_bit;
    *dst = DEC_ZERO;
    s21_set_sign(dst, (src < 0));
    src = (src < 0) ? src * -1 : src;
    if (src == INT_MIN) {
      s21_set_bit(dst, 31, 1);
    } else {
      for (int i = 0; src > 0 && i < 96; i++) {
        current_bit = (src > 0) ? src % 2 : 0;
        s21_set_bit(dst, i, current_bit);
        src /= 2;
      }
    }
  }
  return error;
}
