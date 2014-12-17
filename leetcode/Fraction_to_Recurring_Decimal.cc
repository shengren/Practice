class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    long long nume = numerator;
    long long deno = denominator;

    if (nume == 0LL) return "0";

    bool negative = ((double)nume * deno < 0.0);
    nume = abs(nume);
    deno = abs(deno);

    ostringstream oss;
    if (negative) oss << "-";
    oss << nume / deno;
    string res = oss.str();

    if (nume % deno == 0) return res;

    nume %= deno;
    res += ".";

    long long r = nume;
    unordered_map<long long, int> t;
    string dec = "";
    int k = 0;
    while (true) {
      r *= 10;
      if (t.find(r) != t.end()) {
        res += dec.substr(0, t[r]);
        res += "(";
        res += dec.substr(t[r]);
        res += ")";
        break;
      }
      t[r] = k++;
      dec += char('0' + r / deno);
      r %= deno;
      if (r == 0) {
        res += dec;
        break;
      }
    }

    return res;
  }
};