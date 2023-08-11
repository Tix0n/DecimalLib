#include "../s21_decimal.h"

#include <check.h>
Suite *s21_test_decimal_convert();
Suite *s21_test_compare();
Suite *s21_test_another();
Suite *s21_test_arithm();
START_TEST(s21_addit) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(51354, &a);
  s21_from_int_to_decimal(1111, &b);
  s21_mul(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(51354 * 1111, rrr);
}
END_TEST
START_TEST(s21_add1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(51354, &a);
  s21_from_int_to_decimal(1111, &b);
  s21_add(a, b, &res);
  int rrr = 0;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(52465, rrr);
}
END_TEST
START_TEST(s21_add2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-9403, &a);
  s21_from_int_to_decimal(234, &b);
  s21_add(a, b, &res);
  int rrr = 0;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(-9169, rrr);
}
END_TEST
START_TEST(s21_add3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(4294967, &a);
  s21_from_int_to_decimal(-4294967, &b);
  s21_add(a, b, &res);
  int rrr = 0;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(4294967 + (-4294967), rrr);
}
END_TEST
START_TEST(s21_add5) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-41523, &a);
  s21_from_int_to_decimal(-11111, &b);
  s21_add(a, b, &res);
  int rrr = 0;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(-(41523 + 11111), rrr);
}
END_TEST
START_TEST(s21_add6) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(6871, &a);
  s21_from_int_to_decimal(6871, &b);
  s21_add(a, b, &res);
  int rrr = 0;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(6871 + 6871, rrr);
}
END_TEST
START_TEST(s21_add7) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(2, &a);
  s21_from_int_to_decimal(10, &b);
  s21_add(a, b, &res);
  int rrr = 0;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(12, rrr);
}
END_TEST
START_TEST(s21_add8) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(123321, &a);
  s21_from_int_to_decimal(-10, &b);
  s21_add(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 123321 - 10);
}
END_TEST
START_TEST(s21_add9) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(56789, &a);
  s21_from_int_to_decimal(341111, &b);
  s21_set_power(&a, 3);
  s21_set_power(&b, 6);
  s21_add(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, 56.789 + 0.341111);
}
END_TEST
START_TEST(s21_add10) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-56789, &a);
  s21_from_int_to_decimal(-341111, &b);
  s21_set_power(&a, 3);
  s21_set_power(&b, 6);
  s21_add(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -56.789 + (-0.341111));
}
END_TEST
START_TEST(s21_add11) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(56789, &a);
  s21_from_int_to_decimal(-34, &b);
  s21_set_power(&a, 3);
  s21_set_power(&b, 2);
  s21_add(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, 56.789 + (-0.34));
}
END_TEST
START_TEST(s21_sub1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(123, &a);
  s21_from_int_to_decimal(23, &b);
  s21_sub(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 123 - 23);
}
END_TEST
START_TEST(s21_sub2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(72364, &a);
  s21_from_int_to_decimal(235472, &b);
  s21_sub(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 72364 - 235472);
  ck_assert_int_eq(s21_get_sign(res), 1);
}
END_TEST
START_TEST(s21_sub3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-123, &a);
  s21_from_int_to_decimal(-23, &b);
  s21_sub(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, -123 - (-23));
}
END_TEST
START_TEST(s21_sub4) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(123, &a);
  s21_from_int_to_decimal(-23, &b);
  s21_sub(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 123 - (-23));
}
END_TEST
START_TEST(s21_sub5) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-123, &a);
  s21_from_int_to_decimal(23, &b);
  s21_sub(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, -123 - 23);
}
END_TEST
START_TEST(s21_sub6) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(+56789, &a);
  s21_from_int_to_decimal(-341111, &b);
  s21_set_power(&a, 3);
  s21_set_power(&b, 6);
  s21_sub(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, +56.789 - (-0.341111));
}
END_TEST
START_TEST(s21_sub7) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-56789, &a);
  s21_from_int_to_decimal(-341111, &b);
  s21_set_power(&a, 3);
  s21_set_power(&b, 6);
  s21_sub(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -56.789 - (-0.341111));
}
END_TEST
START_TEST(s21_sub8) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-0, &a);
  s21_from_int_to_decimal(0, &b);
  s21_set_power(&a, 0);
  s21_set_power(&b, 0);
  s21_sub(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -0.0 - 0.0);
}
END_TEST
START_TEST(s21_sub9) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-0, &a);
  s21_from_int_to_decimal(-12345665, &b);
  s21_set_power(&a, 0);
  s21_set_power(&b, 8);
  s21_sub(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -0.0 - (-0.12345665));
}
END_TEST
START_TEST(s21_sub10) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-0, &a);
  s21_from_int_to_decimal(+12345665, &b);
  s21_set_power(&a, 0);
  s21_set_power(&b, 8);
  s21_sub(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -0.0 - (+0.12345665));
}
END_TEST
START_TEST(s21_mul1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(123, &a);
  s21_from_int_to_decimal(23, &b);
  s21_mul(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 123 * 23);
}
END_TEST
START_TEST(s21_mul2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(723, &a);
  s21_from_int_to_decimal(2354, &b);
  s21_mul(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 723 * 2354);
  ck_assert_int_eq(s21_get_sign(res), 0);
}
END_TEST
START_TEST(s21_mul3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-123, &a);
  s21_from_int_to_decimal(-23, &b);
  s21_mul(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, -123 * (-23));
}
END_TEST
START_TEST(s21_mul4) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(123, &a);
  s21_from_int_to_decimal(-23, &b);
  s21_mul(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 123 * (-23));
}
END_TEST
START_TEST(s21_mul5) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-123, &a);
  s21_from_int_to_decimal(23, &b);
  s21_mul(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, -123 * 23);
}
END_TEST
START_TEST(s21_mul6) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(+56789, &a);
  s21_from_int_to_decimal(-341111, &b);
  s21_set_power(&a, 3);
  s21_set_power(&b, 6);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, +56.789 * (-0.341111));
}
END_TEST
START_TEST(s21_mul7) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-56789, &a);
  s21_from_int_to_decimal(-341111, &b);
  s21_set_power(&a, 3);
  s21_set_power(&b, 6);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -56.789 * (-0.341111));
}
END_TEST
START_TEST(s21_mul8) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-0, &a);
  s21_from_int_to_decimal(0, &b);
  s21_set_power(&a, 0);
  s21_set_power(&b, 0);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -0.0 * 0.0);
}
END_TEST
START_TEST(s21_mul9) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-0, &a);
  s21_from_int_to_decimal(-12345665, &b);
  s21_set_power(&a, 0);
  s21_set_power(&b, 8);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -0.0 * (-0.12345665));
}
END_TEST
START_TEST(s21_mul10) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-0, &a);
  s21_from_int_to_decimal(+12345665, &b);
  s21_set_power(&a, 0);
  s21_set_power(&b, 8);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, -0.0 * (+0.12345665));
}
END_TEST
START_TEST(s21_mul11) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal b = DEC_ONE;
  s21_decimal res = DEC_ZERO;
  s21_set_power(&a, 28);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, 7.9228162514264337593543950335);
}
END_TEST
START_TEST(s21_mul12) {
  s21_decimal a = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal b = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal res = DEC_ZERO;
  s21_set_power(&a, 28);
  s21_set_power(&b, 28);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(
      f, 7.9228162514264337593543950335 * 7.9228162514264337593543950335);
}
END_TEST
START_TEST(s21_mul13) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 0b11111111111111111111111111111111;
  a.bits[1] = 0b11111111111111111111111111111111;
  a.bits[2] = 0b11111111111111111111111111111111;
  b.bits[0] = 0b01011101100010100000000000000000;
  b.bits[1] = 0b00000001011000110100010101111000;
  b.bits[2] = 0b00000000000000000000000000000000;
  s21_set_power(&a, 28);
  s21_set_power(&b, 13);
  s21_mul(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f,
                     7.9228162514264337593543950335 * 10000.00000000000000000);
}
START_TEST(s21_div1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(123456, &a);
  s21_from_int_to_decimal(2, &b);
  int check = s21_div(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 123456 / 2);
  ck_assert_int_eq(check, 0);
}
END_TEST
START_TEST(s21_div2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(100000, &a);
  s21_from_int_to_decimal(10, &b);
  s21_div(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 100000 / 10);
  ck_assert_int_eq(s21_div(a, b, &res), 0);
}
END_TEST
START_TEST(s21_div3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(370412, &a);
  s21_from_int_to_decimal(37, &b);
  int check = s21_div(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, 370412.0 / 37.0);
  ck_assert_int_eq(check, 0);
}
END_TEST
START_TEST(s21_div4) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(1, &a);
  s21_from_int_to_decimal(3, &b);
  int check = s21_div(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 1 / 3);
  ck_assert_int_eq(check, 0);
}
END_TEST
START_TEST(s21_div5) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(121.0F, &a);
  s21_from_float_to_decimal(11.0F, &b);
  int check = s21_div(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, 121.0 / 11.0);
  ck_assert_int_eq(check, 0);
}
END_TEST
START_TEST(s21_div6) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-370412, &a);
  s21_from_int_to_decimal(+37, &b);
  int check = s21_div(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, -370412 / (+37));
  ck_assert_int_eq(check, 0);
}
END_TEST
START_TEST(s21_div7) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(+0, &a);
  s21_from_int_to_decimal(-0, &b);
  int check = s21_div(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(check, 3);
}
END_TEST
START_TEST(s21_div8) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(-0, &a);
  s21_from_int_to_decimal(+0, &b);
  int check = s21_div(a, b, &res);
  int rrr;
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(check, 3);
}
END_TEST
START_TEST(s21_div9) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(0, &a);
  s21_from_int_to_decimal(1000, &b);
  int check = s21_div(a, b, &res);
  ck_assert_int_eq(check, 0);
}
END_TEST
START_TEST(s21_div10) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(1, &a);
  s21_from_float_to_decimal(3, &b);
  s21_div(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, 1.0 / 3.0);
}
END_TEST
START_TEST(s21_div11) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(12.5, &a);
  s21_from_float_to_decimal(2.2, &b);
  s21_div(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, 12.5F / 2.2F);
}
END_TEST
START_TEST(s21_mod1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  int rrr;
  s21_from_int_to_decimal(11, &a);
  s21_from_int_to_decimal(2, &b);
  s21_mod(a, b, &res);
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 11 % 2);
}
END_TEST
START_TEST(s21_mod2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  int rrr;
  s21_from_int_to_decimal(11123, &a);
  s21_from_int_to_decimal(232, &b);
  s21_mod(a, b, &res);
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 11123 % 232);
}
END_TEST
START_TEST(s21_mod3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  int rrr;
  s21_from_int_to_decimal(121, &a);
  s21_from_int_to_decimal(11, &b);
  s21_mod(a, b, &res);
  s21_from_decimal_to_int(res, &rrr);
  ck_assert_int_eq(rrr, 121 % 11);
}
END_TEST
START_TEST(s21_mod4) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(12.5, &a);
  s21_from_float_to_decimal(2.2, &b);
  s21_mod(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, fmod(12.5, 2.2));
}
END_TEST
START_TEST(s21_mod5) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal((float)12.55, &a);
  s21_from_float_to_decimal((float)2.2, &b);
  s21_mod(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, fmod(12.55, 2.2));
}
END_TEST
START_TEST(s21_mod6) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(12.5, &a);
  s21_from_float_to_decimal(2.22, &b);
  s21_mod(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, fmod(12.5, 2.22));
}
END_TEST
START_TEST(s21_mod7) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(12.5, &a);
  s21_from_float_to_decimal(2.22, &b);
  int code = s21_mod(a, b, NULL);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_int_eq(code, 3);
}
END_TEST
START_TEST(s21_mod8) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_int_to_decimal(12, &a);
  s21_from_int_to_decimal(12, &b);
  s21_mod(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, fmod(12, 12));
}
END_TEST
START_TEST(s21_mod9) {
  s21_decimal a = {{0x000004E7, 0, 0, 0}};
  s21_decimal b = {{0x00000016, 0, 0, 0}};
  s21_decimal res = DEC_ZERO;
  s21_set_power(&a, 2);
  s21_set_power(&b, 1);
  s21_mod(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, fmod(12.55, 2.2));
}
END_TEST
START_TEST(s21_mod10) {
  s21_decimal a = {{0x0000007D, 0, 0, 0}};
  s21_decimal b = {{0x000000DE, 0, 0, 0}};
  s21_decimal res = DEC_ZERO;
  s21_set_power(&a, 1);
  s21_set_power(&b, 2);
  s21_mod(a, b, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, fmod(12.5, 2.22));
}
END_TEST
START_TEST(mul_inf1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 1629782456;
  a.bits[1] = 11805;
  a.bits[2] = 0;
  a.bits[3] = 0;
  b.bits[0] = 4018017772U;
  b.bits[1] = 3669184606U;
  b.bits[2] = 2418487;
  b.bits[3] = 0;
  ck_assert_int_eq(s21_mul(a, b, &res), 1);
}
END_TEST
START_TEST(mul_inf2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 3949088011U;
  a.bits[1] = 3470698511U;
  a.bits[2] = 162247649;
  a.bits[3] = 2147483648U;
  b.bits[0] = 3317551950U;
  b.bits[1] = 523896;
  b.bits[2] = 0;
  b.bits[3] = 0;
  ck_assert_int_eq(s21_mul(a, b, &res), 2);
}
END_TEST
START_TEST(float_add1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 265601884;
  a.bits[1] = 2255822589U;
  a.bits[2] = 147331;
  a.bits[3] = 0;
  s21_set_power(&a, 10);
  b.bits[0] = 1709438099;
  b.bits[1] = 3663741029U;
  b.bits[2] = 418;
  b.bits[3] = 0;
  s21_set_power(&b, 10);
  float f = 0.0;
  s21_add(a, b, &res);
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(272551341447866.041819F, f);
}
END_TEST
START_TEST(float_add2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 2166790002U;
  a.bits[1] = 0;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_set_power(&a, 13);
  b.bits[0] = 3392233072U;
  b.bits[1] = 3637809032U;
  b.bits[2] = 14984;
  b.bits[3] = 0;
  s21_set_power(&b, 7);
  float f = 0.0;
  s21_add(a, b, &res);
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(27642163747128884.706400F, f);
}
END_TEST
START_TEST(float_add3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 169607453;
  a.bits[1] = 169607453;
  a.bits[2] = 6719924;
  a.bits[3] = 0;
  s21_set_sign(&a, 1);
  s21_set_power(&a, 6);
  b.bits[0] = 2348326755U;
  b.bits[1] = 24191108;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_set_power(&b, 9);
  float f = 0.0;
  s21_add(a, b, &res);
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(-123960718951133149053.000000F, f);
}
END_TEST
START_TEST(float_add4) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  float f = 0.0;
  a.bits[0] = 1090361570;
  a.bits[1] = 1457815228;
  a.bits[2] = 28677749;
  a.bits[3] = 2147942400U;
  b.bits[0] = 358283188;
  b.bits[1] = 1671661052;
  b.bits[2] = 2250;
  b.bits[3] = 393216;
  s21_add(a, b, &res);
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(-5.2859598456878E19F, f);
}
END_TEST
START_TEST(float_sub1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  float f = 0.0;
  a.bits[0] = 1712443877;
  a.bits[1] = 213419;
  a.bits[2] = 0;
  a.bits[3] = 0;
  s21_set_power(&a, 11);
  b.bits[0] = 67994708;
  b.bits[1] = 0;
  b.bits[2] = 0;
  b.bits[3] = 0;
  s21_set_power(&b, 9);
  s21_sub(a, b, &res);
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(9166.225383F, f);
}
END_TEST
START_TEST(float_sub2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal b = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  float f = 0.0;
  a.bits[0] = 4068769078U;
  a.bits[1] = 27063;
  a.bits[2] = 0;
  a.bits[3] = 2147483648U;
  b.bits[0] = 1182798747;
  b.bits[1] = 792410;
  b.bits[2] = 0;
  b.bits[3] = 2147483648U;
  s21_set_power(&b, 14);
  s21_sub(a, b, &res);
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(-116238768700691.966238F, f);
}
END_TEST
Suite *s21_test_arithm(void) {
  Suite *s = suite_create("!!!!ARITHM!!!!!");
  TCase *arithm_a_test;
  arithm_a_test = tcase_create("--ADD--");
  tcase_add_test(arithm_a_test, s21_addit);
  tcase_add_test(arithm_a_test, s21_add1);
  tcase_add_test(arithm_a_test, s21_add2);
  tcase_add_test(arithm_a_test, s21_add3);
  tcase_add_test(arithm_a_test, s21_add5);
  tcase_add_test(arithm_a_test, s21_add6);
  tcase_add_test(arithm_a_test, s21_add7);
  tcase_add_test(arithm_a_test, s21_add8);
  tcase_add_test(arithm_a_test, s21_add9);
  tcase_add_test(arithm_a_test, s21_add10);
  tcase_add_test(arithm_a_test, s21_add11);
  tcase_add_test(arithm_a_test, float_add1);
  tcase_add_test(arithm_a_test, float_add2);
  tcase_add_test(arithm_a_test, float_add3);
  tcase_add_test(arithm_a_test, float_add4);
  suite_add_tcase(s, arithm_a_test);
  arithm_a_test = tcase_create("--SUB--");
  tcase_add_test(arithm_a_test, s21_sub1);
  tcase_add_test(arithm_a_test, s21_sub2);
  tcase_add_test(arithm_a_test, s21_sub3);
  tcase_add_test(arithm_a_test, s21_sub4);
  tcase_add_test(arithm_a_test, s21_sub5);
  tcase_add_test(arithm_a_test, s21_sub6);
  tcase_add_test(arithm_a_test, s21_sub7);
  tcase_add_test(arithm_a_test, s21_sub8);
  tcase_add_test(arithm_a_test, s21_sub9);
  tcase_add_test(arithm_a_test, s21_sub10);
  tcase_add_test(arithm_a_test, float_sub1);
  tcase_add_test(arithm_a_test, float_sub2);
  suite_add_tcase(s, arithm_a_test);
  arithm_a_test = tcase_create("--MUL--");
  tcase_add_test(arithm_a_test, s21_mul1);
  tcase_add_test(arithm_a_test, s21_mul2);
  tcase_add_test(arithm_a_test, s21_mul3);
  tcase_add_test(arithm_a_test, s21_mul4);
  tcase_add_test(arithm_a_test, s21_mul5);
  tcase_add_test(arithm_a_test, s21_mul6);
  tcase_add_test(arithm_a_test, s21_mul7);
  tcase_add_test(arithm_a_test, s21_mul8);
  tcase_add_test(arithm_a_test, s21_mul9);
  tcase_add_test(arithm_a_test, s21_mul10);
  tcase_add_test(arithm_a_test, s21_mul11);
  tcase_add_test(arithm_a_test, s21_mul12);
  tcase_add_test(arithm_a_test, mul_inf1);
  tcase_add_test(arithm_a_test, mul_inf2);
  tcase_add_test(arithm_a_test, s21_mul13);
  suite_add_tcase(s, arithm_a_test);
  arithm_a_test = tcase_create("--DIV--");
  tcase_add_test(arithm_a_test, s21_div1);
  tcase_add_test(arithm_a_test, s21_div2);
  tcase_add_test(arithm_a_test, s21_div3);
  tcase_add_test(arithm_a_test, s21_div4);
  tcase_add_test(arithm_a_test, s21_div5);
  tcase_add_test(arithm_a_test, s21_div6);
  tcase_add_test(arithm_a_test, s21_div7);
  tcase_add_test(arithm_a_test, s21_div8);
  tcase_add_test(arithm_a_test, s21_div9);
  tcase_add_test(arithm_a_test, s21_div10);
  tcase_add_test(arithm_a_test, s21_div11);
  suite_add_tcase(s, arithm_a_test);
  arithm_a_test = tcase_create("--MOD--");
  tcase_add_test(arithm_a_test, s21_mod1);
  tcase_add_test(arithm_a_test, s21_mod2);
  tcase_add_test(arithm_a_test, s21_mod3);
  tcase_add_test(arithm_a_test, s21_mod4);
  tcase_add_test(arithm_a_test, s21_mod5);
  tcase_add_test(arithm_a_test, s21_mod6);
  tcase_add_test(arithm_a_test, s21_mod7);
  tcase_add_test(arithm_a_test, s21_mod8);
  tcase_add_test(arithm_a_test, s21_mod9);
  tcase_add_test(arithm_a_test, s21_mod10);
  suite_add_tcase(s, arithm_a_test);
  return s;
}
START_TEST(s21_negate_1) {
  int a = 10;
  s21_decimal res_a = {0};
  s21_decimal src = {0};
  int result = 0;
  s21_from_int_to_decimal(a, &src);
  s21_negate(src, &res_a);
  s21_from_decimal_to_int(res_a, &result);
  ck_assert_int_eq(-10, result);
}
END_TEST
START_TEST(s21_negate_2) {
  s21_decimal res_a = {0};
  s21_decimal src = {0};
  float result = 0;
  s21_from_float_to_decimal(10.12345, &src);
  s21_negate(src, &res_a);
  s21_from_decimal_to_float(res_a, &result);
}
END_TEST
START_TEST(s21_negate_3) {
  float a = 10.1234e5;
  s21_decimal res_a = {0};
  s21_decimal src = {0};
  float result = 0;
  s21_from_float_to_decimal(a, &src);
  s21_negate(src, &res_a);
  s21_from_decimal_to_float(res_a, &result);
}
END_TEST
START_TEST(trunc1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 12345678;
  s21_set_power(&a, 4);
  float f;
  s21_from_decimal_to_float(a, &f);
  ck_assert_int_eq(0, a.bits[1]);
  ck_assert_int_eq(0, a.bits[2]);
  ck_assert_int_eq(0, s21_get_sign(a));
  ck_assert_float_eq(f, 1234.5678);
  s21_truncate(a, &res);
  int res_int;
  s21_from_decimal_to_int(res, &res_int);
  ck_assert_int_eq(res_int, 1234);
}
END_TEST
START_TEST(trunc2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 28473621;
  s21_set_power(&a, 5);
  s21_set_sign(&a, 1);
  float f;
  s21_from_decimal_to_float(a, &f);
  ck_assert_int_eq(0, a.bits[1]);
  ck_assert_int_eq(0, a.bits[2]);
  ck_assert_int_eq(1, s21_get_sign(a));
  ck_assert_float_eq(f, -284.73621);
  s21_truncate(a, &res);
  int res_int;
  s21_from_decimal_to_int(res, &res_int);
  ck_assert_int_eq(res_int, -284);
}
END_TEST
START_TEST(trunc3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  a.bits[0] = 0;
  s21_set_power(&a, 4);
  float f;
  s21_from_decimal_to_float(a, &f);
  ck_assert_int_eq(0, a.bits[1]);
  ck_assert_int_eq(0, a.bits[2]);
  ck_assert_int_eq(0, s21_get_sign(a));
  ck_assert_float_eq(f, 0.0f);
  s21_truncate(a, &res);
  int res_int;
  s21_from_decimal_to_int(res, &res_int);
  ck_assert_int_eq(res_int, 0);
}
END_TEST
START_TEST(trunc4) {
  s21_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_truncate(decimal, &decimal);
  ck_assert_int_eq(1, s21_is_equal(decimal, decimal_check));
}
START_TEST(trunc5) {
  s21_decimal decimal = {{0x0, 0x0, 0x0, 0x800E0000}};
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_truncate(decimal, &decimal);
  ck_assert_int_eq(1, s21_is_equal(decimal, decimal_check));
}
START_TEST(round1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(12345.6789F, &a);
  s21_round(a, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, roundf(12345.6789F));
}
END_TEST
START_TEST(round2) {
  s21_decimal a = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  s21_from_float_to_decimal(12763547.8915937694581F, &a);
  s21_round(a, &res);
  float f;
  s21_from_decimal_to_float(res, &f);
  ck_assert_float_eq(f, roundf(12763547.8915937694581F));
}
END_TEST
START_TEST(round3) {
  s21_decimal a = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  float f;
  for (float i = -31231.123F; i < 134763.0F; i += 412.92234F) {
    s21_from_float_to_decimal(i, &a);
    s21_round(a, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, roundf(i));
  }
}
END_TEST
START_TEST(floor1) {
  s21_decimal a = DEC_ZERO;
  s21_decimal res = DEC_ZERO;
  float f;
  for (float i = -41231.123; i < 213340.0; i += 1141.92234) {
    s21_from_float_to_decimal(i, &a);
    s21_floor(a, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, floorf(i));
  }
}
END_TEST
Suite *s21_test_another(void) {
  Suite *s = suite_create("!!!!!ANOTHER!!!!!!");
  TCase *test_another;
  test_another = tcase_create("--TRUNCATE--");
  tcase_add_test(test_another, s21_negate_1);
  tcase_add_test(test_another, trunc1);
  tcase_add_test(test_another, trunc2);
  tcase_add_test(test_another, trunc3);
  tcase_add_test(test_another, trunc4);
  tcase_add_test(test_another, trunc5);
  tcase_add_test(test_another, s21_negate_2);
  tcase_add_test(test_another, s21_negate_3);
  suite_add_tcase(s, test_another);
  test_another = tcase_create("--ROUND--");
  tcase_add_test(test_another, round1);
  tcase_add_test(test_another, round2);
  tcase_add_test(test_another, round3);
  suite_add_tcase(s, test_another);
  test_another = tcase_create("--ROUND--");
  tcase_add_test(test_another, floor1);
  suite_add_tcase(s, test_another);
  return s;
}
START_TEST(compare_less) {
  s21_decimal dst1 = DEC_ZERO, dst2 = DEC_ZERO;
  s21_from_int_to_decimal(12, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_less(dst2, dst1), 0);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(12, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_less(dst2, dst1), 1);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_less(dst2, dst1), 0);
  s21_from_int_to_decimal(-1, &dst1);
  s21_from_int_to_decimal(-5, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_less(dst2, dst1), 1);
  s21_from_int_to_decimal(-5, &dst1);
  s21_from_int_to_decimal(33, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_less(dst2, dst1), 0);
  s21_from_int_to_decimal(0, &dst1);
  s21_from_int_to_decimal(0, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_less(dst2, dst1), 0);
  s21_from_int_to_decimal(0, &dst1);
  s21_from_int_to_decimal(1, &dst2);
  ck_assert_int_eq(s21_is_less(dst1, dst2), 1);
  dst1 = DEC_ZERO;
  dst2 = DEC_ZERO;
  dst1.bits[0] = 123456789;
  dst1.bits[1] = 9999999;
  dst2.bits[0] = 123456788;
  dst2.bits[1] = 9999999;
  ck_assert_int_eq(s21_is_less(dst1, dst2), 0);
}
END_TEST
START_TEST(compare_greater) {
  s21_decimal dst1 = DEC_ZERO, dst2 = DEC_ZERO;
  s21_from_int_to_decimal(12, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 1);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(12, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 0);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 0);
  s21_from_int_to_decimal(-1, &dst1);
  s21_from_int_to_decimal(-5, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 1);
  s21_from_int_to_decimal(-5, &dst1);
  s21_from_int_to_decimal(33, &dst2);
  ck_assert_int_eq(s21_is_greater(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_greater(dst2, dst1), 1);
}
END_TEST
START_TEST(compare_less_or_equal) {
  s21_decimal dst1 = DEC_ZERO, dst2 = DEC_ZERO;
  s21_from_int_to_decimal(12, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), 0);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(12, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(-1, &dst1);
  s21_from_int_to_decimal(-5, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(-5, &dst1);
  s21_from_int_to_decimal(33, &dst2);
  ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), 0);
}
END_TEST
START_TEST(compare_greater_or_equal) {
  s21_decimal dst1 = DEC_ZERO, dst2 = DEC_ZERO;
  s21_from_int_to_decimal(12, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(12, &dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), 0);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(-1, &dst1);
  s21_from_int_to_decimal(-5, &dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), 0);
  s21_from_int_to_decimal(-5, &dst1);
  s21_from_int_to_decimal(33, &dst2);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), 1);
}
END_TEST
START_TEST(compare_equal) {
  s21_decimal dst1 = DEC_ZERO, dst2 = DEC_ZERO;
  s21_from_int_to_decimal(12, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_equal(dst2, dst1), 0);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(12, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_equal(dst2, dst1), 0);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(-1, &dst1);
  s21_from_int_to_decimal(-5, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_equal(dst2, dst1), 0);
  s21_from_int_to_decimal(-5, &dst1);
  s21_from_int_to_decimal(33, &dst2);
  ck_assert_int_eq(s21_is_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_equal(dst2, dst1), 0);
}
END_TEST
START_TEST(lol_kek_123) {
  s21_decimal dst1 = DEC_ZERO, dst2 = DEC_ZERO;
  dst1 = DEC_ZERO;
  dst2 = DEC_ZERO;
  dst1.bits[0] = 56789;
  s21_set_power(&dst1, 3);
  dst2.bits[0] = 340;
  s21_set_power(&dst2, 3);
  ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), 1);
}
END_TEST
START_TEST(compare_not_equal) {
  s21_decimal dst1 = DEC_ZERO, dst2 = DEC_ZERO;
  s21_from_int_to_decimal(12, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(12, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(22, &dst1);
  s21_from_int_to_decimal(22, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 0);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 0);
  s21_from_int_to_decimal(-1, &dst1);
  s21_from_int_to_decimal(-5, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 1);
  s21_from_int_to_decimal(-5, &dst1);
  s21_from_int_to_decimal(33, &dst2);
  ck_assert_int_eq(s21_is_not_equal(dst1, dst2), 1);
  ck_assert_int_eq(s21_is_not_equal(dst2, dst1), 1);
}
END_TEST
START_TEST(int_to_decimal_0) {
  s21_decimal var = DEC_ZERO;
  int a = 123;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(123, var.bits[0]);
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(0, var.bits[3]);
  ck_assert_int_eq(0, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_1) {
  int a = 1237325487;
  ck_assert_int_eq(1, s21_from_int_to_decimal(a, NULL));
}
END_TEST
START_TEST(int_to_decimal_2) {
  s21_decimal var = {{0, 1234253647, 3245678, 0}};
  int a = -2147483648;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(1, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_3) {
  s21_decimal var = {{1231, 343567, 12343, 0}};
  long int a = -2147481231236491;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(1, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_4) {
  s21_decimal var = {{1231, 343567, 12343, 0}};
  long int a = 2147481231236491;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(0, var.bits[3]);
  ck_assert_int_eq(0, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_5) {
  s21_decimal var = {{0, 1234253647, 3245678, 0}};
  unsigned long int a = 2147481231236491;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(0, var.bits[3]);
  ck_assert_int_eq(0, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_6) {
  s21_decimal var = {{0, 1234253647, 3245678, 0}};
  int a = 1;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(1, var.bits[0]);
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(0, var.bits[3]);
  ck_assert_int_eq(0, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_7) {
  s21_decimal var = {{0, 1234253647, 3245678, 0}};
  int a = -0;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(0, var.bits[0]);
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(0, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_8) {
  s21_decimal var = {{0, 1234253647, 3245678, 0}};
  int a = +99;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(99, var.bits[0]);
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(0, var.bits[3]);
  ck_assert_int_eq(0, s21_get_bit(var, 127));
}
END_TEST
START_TEST(int_to_decimal_9) {
  s21_decimal var = {{0, 1234253647, 3245678, 0}};
  int a = 2147483647;
  ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
  ck_assert_int_eq(2147483647, var.bits[0]);
  ck_assert_int_eq(0, var.bits[1]);
  ck_assert_int_eq(0, var.bits[2]);
  ck_assert_int_eq(0, var.bits[3]);
  ck_assert_int_eq(0, s21_get_bit(var, 127));
}
END_TEST
START_TEST(s21_from_decimal_to_float_1) {
  s21_decimal src;
  int result = 0;
  float number = 0.00;
  src.bits[0] = 18122;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_power(&src, 3);
  s21_set_sign(&src, 1);
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -18.122);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(s21_from_decimal_to_float_2) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147483648;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(s21_from_decimal_to_float_3) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 0XFFFFFF;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 16777215);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(s21_from_decimal_to_float_4) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 23450987;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0;
  s21_set_sign(&src, 1);
  s21_set_power(&src, 4);
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, -2345.0987);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(s21_from_decimal_to_float_5) {
  s21_decimal src;
  int result = 0;
  float number = 0.0;
  src.bits[0] = 4294967295;
  src.bits[1] = 4294967295;
  src.bits[2] = 0;
  src.bits[3] = 0;
  result = s21_from_decimal_to_float(src, &number);
  ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(s21_from_decimal_to_int_1) {
  s21_decimal src;
  int result = 0;
  int number = 0;
  src.bits[0] = 1812;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 2147483648;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_float_eq(number, -1812);
  ck_assert_int_eq(result, 0);
}
END_TEST
START_TEST(s21_from_decimal_to_int_2) {
  s21_decimal src = DEC_ZERO;
  int result = 0;
  result = s21_from_decimal_to_int(src, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(s21_from_decimal_to_int_3) {
  s21_decimal src;
  int result = 0;
  int number = 0;
  src.bits[0] = 0;
  src.bits[1] = 0;
  src.bits[2] = 0;
  src.bits[3] = 0xFFFFFFFF;
  result = s21_from_decimal_to_int(src, &number);
  ck_assert_int_eq(result, 1);
}
END_TEST
START_TEST(s21_from_float_to_decimal_1) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = 123.456;
  s21_from_float_to_decimal(b, &val);
  s21_from_decimal_to_float(val, &f);
  ck_assert_float_eq(f, b);
}
END_TEST
START_TEST(s21_from_float_to_decimal_2) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = 116987.21930;
  s21_from_float_to_decimal(b, &val);
  s21_from_decimal_to_float(val, &f);
  ck_assert_float_eq(f, b);
}
END_TEST
START_TEST(s21_from_float_to_decimal_3) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = 12623532.7256347;
  s21_from_float_to_decimal(b, &val);
  s21_from_decimal_to_float(val, &f);
  ck_assert_float_eq(f, b);
}
END_TEST
START_TEST(s21_from_float_to_decimal_4) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = -342123124124321432143.6411;
  int check = s21_from_float_to_decimal(b, &val);
  if (check == 0) {
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
  }
}
END_TEST
START_TEST(s21_from_float_to_decimal_5) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = 126235235432532.7256123512347F;
  int check = s21_from_float_to_decimal(b, &val);
  s21_from_decimal_to_float(val, &f);
  if (check == 0) {
    ck_assert_float_eq(f, b);
  }
}
END_TEST
START_TEST(s21_from_float_to_decimal_6) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = 1262351243126523463632.725633246234673247;
  int check = s21_from_float_to_decimal(b, &val);
  if (check == 0) {
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
  }
}
END_TEST
START_TEST(s21_from_float_to_decimal_7) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = -234632612623532.7256347;
  s21_from_float_to_decimal(b, &val);
  s21_from_decimal_to_float(val, &f);
  ck_assert_float_eq(f, b);
}
END_TEST
START_TEST(s21_from_float_to_decimal_8) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = 12623532.7256347;
  s21_from_float_to_decimal(b, &val);
  s21_from_decimal_to_float(val, &f);
  ck_assert_float_eq(f, b);
}
END_TEST
START_TEST(s21_from_float_to_decimal_9) {
  s21_decimal val = DEC_ZERO;
  float f;
  float b = 12724536456745374772623532.7256347;
  s21_from_float_to_decimal(b, &val);
  s21_from_decimal_to_float(val, &f);
  ck_assert_float_eq(f, b);
}
END_TEST
START_TEST(s21_from_float_to_decimal_10) {
  s21_decimal dst = {{0, 0, 0, 0}};
  float src = 89228162514264337593543950336.0;
  int s21_error_code = s21_from_float_to_decimal(src, &dst);
  int error_code = 1;
  ck_assert_int_eq(error_code, s21_error_code);
}
END_TEST
START_TEST(s21_from_float_to_decimal_11) {
  s21_decimal dst = {{0, 0, 0, 0}};
  float src = -89228162514264337593543950336.0;
  int s21_error_code = s21_from_float_to_decimal(src, &dst);
  int error_code = 1;
  ck_assert_int_eq(error_code, s21_error_code);
}
END_TEST
START_TEST(s21_from_float_to_decimal_15) {
  s21_decimal s21_result = {{0, 0, 0, 0}};
  float src = -0.00000000000000000000000000009554;
  int s21_error_code = s21_from_float_to_decimal(src, &s21_result);
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = 1;
  ck_assert_int_eq(error_code, s21_error_code);
  ck_assert_uint_eq(result.bits[0], s21_result.bits[0]);
  ck_assert_uint_eq(result.bits[1], s21_result.bits[1]);
  ck_assert_uint_eq(result.bits[2], s21_result.bits[2]);
  ck_assert_uint_eq(result.bits[3], s21_result.bits[3]);
}
END_TEST
START_TEST(s21_from_float_to_decimal_16) {
  s21_decimal s21_result = {{0, 0, 0, 0}};
  float src = -0.000000000000000000000000000000;
  int s21_error_code = s21_from_float_to_decimal(src, &s21_result);
  s21_decimal result = {{0, 0, 0, 0}};
  int error_code = 0;
  ck_assert_int_eq(error_code, s21_error_code);
  ck_assert_uint_eq(result.bits[0], s21_result.bits[0]);
  ck_assert_uint_eq(result.bits[1], s21_result.bits[1]);
  ck_assert_uint_eq(result.bits[2], s21_result.bits[2]);
  ck_assert_uint_eq(result.bits[3], s21_result.bits[3]);
}
END_TEST
START_TEST(s21_from_float_to_decimal_17) {
  s21_decimal s21_result = {{0, 0, 0, 0}};
  float src = -2453678.97564396565;
  s21_from_float_to_decimal(src, &s21_result);
  s21_decimal result = {{2453679, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_uint_eq(result.bits[0], s21_result.bits[0]);
  ck_assert_uint_eq(result.bits[1], s21_result.bits[1]);
  ck_assert_uint_eq(result.bits[2], s21_result.bits[2]);
  ck_assert_uint_eq(result.bits[3], s21_result.bits[3]);
}
END_TEST
START_TEST(s21_from_float_to_decimal_18) {
  s21_decimal s21_result = {{0, 0, 0, 0}};
  float src = -2453644787554578.0000, resf;
  s21_from_float_to_decimal(src, &s21_result);
  s21_from_decimal_to_float(s21_result, &resf);
  ck_assert_double_eq(src, resf);
}
END_TEST
START_TEST(s21_from_float_to_decimal_19) {
  s21_decimal s21_result = {{0, 0, 0, 0}};
  float src = 79228162514264337593543950336.0, resf;
  int error = s21_from_float_to_decimal(src, &s21_result);
  s21_from_decimal_to_float(s21_result, &resf);
  ck_assert_double_eq(0, resf);
  ck_assert_int_eq(1, error);
}
END_TEST
START_TEST(s21_from_float_to_decimal_20) {
  s21_decimal dst = {{0, 0, 0, 0}};
  float src = 892281625142643375935439503369.0;
  int s21_error_code = s21_from_float_to_decimal(src, &dst);
  int error_code = 1;
  ck_assert_int_eq(error_code, s21_error_code);
}
END_TEST
Suite *s21_test_decimal_convert(void) {
  Suite *s = suite_create("!!!CONVERT TYPE!!!");
  TCase *convert_a_case;
  convert_a_case = tcase_create("--INT TO DECIMAL--");
  tcase_add_test(convert_a_case, int_to_decimal_0);
  tcase_add_test(convert_a_case, int_to_decimal_1);
  tcase_add_test(convert_a_case, int_to_decimal_2);
  tcase_add_test(convert_a_case, int_to_decimal_3);
  tcase_add_test(convert_a_case, int_to_decimal_4);
  tcase_add_test(convert_a_case, int_to_decimal_5);
  tcase_add_test(convert_a_case, int_to_decimal_6);
  tcase_add_test(convert_a_case, int_to_decimal_7);
  tcase_add_test(convert_a_case, int_to_decimal_8);
  tcase_add_test(convert_a_case, int_to_decimal_9);
  tcase_add_test(convert_a_case, s21_from_decimal_to_int_1);
  tcase_add_test(convert_a_case, s21_from_decimal_to_int_2);
  tcase_add_test(convert_a_case, s21_from_decimal_to_int_3);
  suite_add_tcase(s, convert_a_case);
  convert_a_case = tcase_create("--FLOAT TO DECIMAL--");
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_1);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_2);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_3);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_4);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_5);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_6);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_7);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_8);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_9);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_10);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_11);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_15);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_16);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_17);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_18);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_19);
  tcase_add_test(convert_a_case, s21_from_float_to_decimal_20);
  suite_add_tcase(s, convert_a_case);
  convert_a_case = tcase_create("--DECIMAL TO FLOAT--");
  tcase_add_test(convert_a_case, s21_from_decimal_to_float_1);
  tcase_add_test(convert_a_case, s21_from_decimal_to_float_2);
  tcase_add_test(convert_a_case, s21_from_decimal_to_float_3);
  tcase_add_test(convert_a_case, s21_from_decimal_to_float_4);
  tcase_add_test(convert_a_case, s21_from_decimal_to_float_5);
  suite_add_tcase(s, convert_a_case);
  return s;
}
Suite *s21_test_compare(void) {
  Suite *s = suite_create("!!!!!COMPARE!!!!!");
  TCase *compare_a_test;
  compare_a_test = tcase_create("COMPARE: ");
  tcase_add_test(compare_a_test, compare_less);
  tcase_add_test(compare_a_test, compare_greater);
  tcase_add_test(compare_a_test, compare_less_or_equal);
  tcase_add_test(compare_a_test, compare_greater_or_equal);
  tcase_add_test(compare_a_test, compare_equal);
  tcase_add_test(compare_a_test, compare_not_equal);
  tcase_add_test(compare_a_test, lol_kek_123);
  suite_add_tcase(s, compare_a_test);
  return s;
}
int main() {
  int no_failed = 0;
  Suite *s1 = s21_test_decimal_convert();
  Suite *s2 = s21_test_compare();
  Suite *s4 = s21_test_another();
  Suite *s5 = s21_test_arithm();
  SRunner *test_convert;
  SRunner *test_compare;
  SRunner *test_another;
  SRunner *test_arithm;
  test_convert = srunner_create(s1);
  test_compare = srunner_create(s2);
  test_another = srunner_create(s4);
  test_arithm = srunner_create(s5);
  srunner_set_fork_status(test_convert, CK_NOFORK);
  srunner_set_fork_status(test_compare, CK_NOFORK);
  srunner_set_fork_status(test_another, CK_NOFORK);
  srunner_set_fork_status(test_arithm, CK_NOFORK);
  srunner_run_all(test_convert, CK_NORMAL);
  srunner_run_all(test_compare, CK_NORMAL);
  srunner_run_all(test_another, CK_NORMAL);
  srunner_run_all(test_arithm, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_convert);
  no_failed += srunner_ntests_failed(test_compare);
  no_failed += srunner_ntests_failed(test_another);
  no_failed += srunner_ntests_failed(test_arithm);
  srunner_free(test_convert);
  srunner_free(test_compare);
  srunner_free(test_another);
  srunner_free(test_arithm);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
