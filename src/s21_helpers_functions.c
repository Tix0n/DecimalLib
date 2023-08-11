#include "s21_decimal.h"

char *s21_bitwise_int_to_str(int a) {
  s21_decimal dec = {{a, 0, 0, 0}};
  char *res = malloc(sizeof(char) * 32);
  for (int i = 0; i < 32; i++) {
    res[i] = s21_get_bit(dec, i);
  }
  return res;
}

char *s21_decimal_to_string(s21_decimal value) {
  char *result_string = (char *)calloc(32, sizeof(char));
  memset(result_string, '0', 29);
  char pow_of_two[30];
  memset(pow_of_two, '0', 28), pow_of_two[28] = '1', pow_of_two[29] = '\0';
  if (s21_get_bit(value, 0)) result_string[28] = '1';
  for (int bits = 1; bits < 96; bits++) {
    int flag = 0;
    for (int i = 28; i >= 0; i--) {
      int sym = pow_of_two[i] - '0';
      sym = (flag) ? (sym * 2 + flag) : (sym * 2);
      pow_of_two[i] = sym % 10 + '0';
      flag = sym / 10;
    }
    if (s21_get_bit(value, bits)) {
      flag = 0;
      for (int i = 28; i >= 0; i--) {
        int sym = pow_of_two[i] - '0' + result_string[i] - '0';
        sym = (flag) ? (sym + flag) : sym;
        result_string[i] = sym % 10 + '0';
        flag = sym / 10;
      }
    }
  }
  int pow = s21_get_power(value);
  if (pow < 0 || pow > 28) pow = 0;
  if (pow) {
    memmove(result_string + 30 - pow, result_string + 29 - pow, pow);
    result_string[29 - pow] = '.';
  }
  int numer = 0;
  while (result_string[numer] == '0' && numer < 29 - pow - 1) numer++;
  if (numer != 0) memmove(result_string, result_string + numer, 32 - numer);
  if (s21_get_bit(value, 127)) {
    memmove(result_string + 1, result_string, 30);
    result_string[0] = '-';
  }
  return result_string;
}

int s21_get_bit(s21_decimal decimal, int index) {
  int res = (decimal.bits[index / 32] & (1 << (index % 32))) ? 1 : 0;
  return res;
}

int s21_get_power(s21_decimal decimal) {
  int res = decimal.bits[3];
  res <<= 1;
  res >>= 17;
  res = (res > 28) ? res - 257 : res;
  return res;
}

int s21_get_sign(s21_decimal decimal) {
  int res = -1;
  if (s21_get_bit(decimal, 127) == 0) {
    res = 0;
  } else {
    res = 1;
  }
  return res;
}

int s21_is_correct_decimal(s21_decimal decimal) {
  int code = 1;
  int power = s21_get_power(decimal);
  if (power < 0 || power > 28) {
    code = 0;
  }
  for (int i = 96; i < 112; i++) {
    if (s21_get_bit(decimal, i)) code = 0;
  }
  for (int i = 120; i < 127; i++) {
    if (s21_get_bit(decimal, i)) code = 0;
  }
  return code;
}

void s21_print_int_value(s21_decimal dec) {
  if (s21_get_sign(dec))
    printf("-");
  else
    printf("+");
  for (int i = 95; i >= 0; i--) {
    printf("%d", s21_get_bit(dec, i));
  }
  printf("\n");
}

void s21_set_bit(s21_decimal *decimal, int index, int v_bit) {
  if (v_bit == 1) {
    (decimal->bits[index / 32] |= (1 << (index % 32)));
  }
  if (v_bit == 0) {
    (decimal->bits[index / 32] &= ~(1 << (index % 32)));
  }
}

void s21_set_bit_1(s21_decimal *decimal, int index) {
  (decimal->bits[index / 32] |= (1 << (index % 32)));
}

void s21_set_bit_0(s21_decimal *decimal, int index) {
  (decimal->bits[index / 32] &= ~(1 << (index % 32)));
}

void s21_set_power(s21_decimal *decimal, int power) {
  for (int i = 112; i < 120; i++) {
    s21_set_bit(decimal, i, power & 1);
    power >>= 1;
  }
}

void s21_set_sign(s21_decimal *decimal, int sign) {
  s21_set_bit(decimal, 127, sign);
}

int s21_shift_left(s21_decimal *value) {
  int val = 0, v = 0;
  if (value->bits[2] & (1 << 31))
    val = 1;
  else
    val = 0;
  if (!val) {
    for (int i = 0; i <= 2; i++) {
      if (value->bits[i] & (1 << 31))
        v = 1;
      else
        v = 0;
      value->bits[i] <<= 1;
      value->bits[i] = value->bits[i] + val;
      val = v;
    }
  }
  return val;
}

void s21_shift_right(s21_decimal *value) {
  int val = 0, v = 0;
  if (value->bits[0] & 1)
    val = 1;
  else
    val = 0;
  if (!val) {
    for (int i = 2; i >= 0; i--) {
      if (value->bits[i] & 1)
        v = 1;
      else
        v = 0;
      value->bits[i] >>= 1;
      s21_set_bit(value, 32 * i + 31, val);
      val = v;
    }
  }
}
