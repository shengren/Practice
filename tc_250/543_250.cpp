class EllysXors {
public:
 long long getXor(long long L, long long R) {
   long long ret, s;
   if (L % 2 == 1) {
     ret = L;
     s = L + 1;
   } else {
     ret = 0;
     s = L;
   }
   if ((R - s + 1) % 2 == 1) {
     if (((R - s) / 2) % 2 == 1) ret ^= 1;
     ret ^= R;
   } else {
     if (((R - s + 1) / 2) % 2 == 1) ret ^= 1;
   }
   return ret;
 }
};
