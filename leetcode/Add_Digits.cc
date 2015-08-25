class Solution {
 public:
  int addDigits(int num) {
    // Define SumDigits(x) that sums all the digits of the nonnegative x.
    //
    // x > SumDigits(x) when x > 9; x = SumDigits(x) when 0 <= x <= 9.
    // For example, 123 = 100 + 20 + 3 > 1 + 2 + 3 = SumDigits(123).
    //
    // Except of 0, recursively applying SumDigits would eventually yield a
    // value between 1 and 9, inclusive.
    //
    // A positive k * 10^n, e.g., 90, 300, 40000, etc., is congruent to k mod 9.
    // k * 10^n = k * 99..9 + k where 99..9 has n 9s and is a multiple of 9.
    //
    // x is congruent to SumDigits(x) mod 9.
    // For example,
    // 456 mod 9 = ((4 * 100) mod 9 + (5 * 10) mod 9 + 6 mod 9) mod 9
    //           = (4 mod 9 + 5 mod 9 + 6 mod 9) mod 9
    //           = (4 + 5 + 6) mod 9
    //           = SumDigits(456) mod 9
    //
    // x mod 9 can indicate the final single digit achieved by recursively
    // applying SumDigits.
    if (num == 0) return 0;
    num %= 9;
    return num == 0 ? 9 : num;
  }
};
