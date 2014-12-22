class Solution {
 public:
  int majorityElement(vector<int> &num) {
    int majority;
    int count = 0;
    for (int x : num) {
      if (count == 0) {
        majority = x;
        count = 1;
      } else if (majority == x) {
        if (++count > num.size() / 2) return x;
      } else {
        count--;
      }
    }
    return majority;
  }
};