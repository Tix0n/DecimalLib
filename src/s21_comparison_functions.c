#include "s21_decimal.h"

int s21_is_greater_simplified(s21_decimal value_1, s21_decimal value_2) {
  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);
  int result = 0;
  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0 &&
      value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    result = 0;
  } else if (sign_1 == 0 && sign_2 == 1) {
    result = 1;
  } else if (sign_1 == 1 && sign_2 == 0) {
    result = 0;
  } else {
    for (int i = 95; i >= 0; i--) {
      int first_v = s21_get_bit(value_1, i);
      int second_v = s21_get_bit(value_2, i);
      if ((first_v > second_v) || (first_v < second_v)) {
        result = 1;
        if (first_v < second_v) result = 0;
        break;
      }
    }
  }
  return result;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 1;
  s21_equal_power(&value_1, &value_2);
  if (value_1.bits[0] == 0 && value_2.bits[0] == 0 && value_1.bits[1] == 0 &&
      value_2.bits[1] == 0 && value_1.bits[2] == 0 && value_2.bits[2] == 0)
    result = 1;
  else {
    result = value_1.bits[0] == value_2.bits[0] &&
             value_1.bits[1] == value_2.bits[1] &&
             value_1.bits[2] == value_2.bits[2] &&
             value_1.bits[3] == value_2.bits[3];
  }
  return result;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);
  int result = 0;
  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0 &&
      value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    result = 0;
  } else if (sign_1 == 0 && sign_2 == 1) {
    result = 1;
  } else if (sign_1 == 1 && sign_2 == 0) {
    result = 0;
  } else {
    s21_equal_power(&value_1, &value_2);
    for (int i = 95; i >= 0; i--) {
      int first_v = s21_get_bit(value_1, i);
      int second_v = s21_get_bit(value_2, i);
      if ((first_v > second_v) || (first_v < second_v)) {
        result = 1;
        if (first_v < second_v) result = 0;
        if (sign_1 && sign_2) result = !result;
        break;
      }
    }
  }
  return result;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_greater(value_1, value_2);
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_greater_or_equal(value_1, value_2);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}
