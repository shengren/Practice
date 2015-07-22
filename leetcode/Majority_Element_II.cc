class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int ca, cb, cc, na, nb, nc;
    na = nb = nc = 0;  // keep na >= nb >= nc
    for (int i = 0; i < nums.size(); ++i) {
      if (na == 0) {
        ca = nums[i];
        na = 1;
      } else if (ca == nums[i]) {
        ++na;
      } else if (nb == 0) {
        cb = nums[i];
        nb = 1;
      } else if (cb == nums[i]) {
        ++nb;
        if (na < nb) {
          swap(ca, cb);
          swap(na, nb);
        }
      } else if (nc == 0) {
        cc = nums[i];
        nc = 1;
      } else if (cc == nums[i]) {
        ++nc;
        if (nb < nc) {
          swap(cb, cc);
          swap(nb, nc);
        }
        if (na < nb) {
          swap(ca, cb);
          swap(na, nb);
        }
      } else {
        --nc;
      }
    }

    vector<int> ret;
    if (IsMajorityElement(nums, ca)) ret.push_back(ca);
    if (cb != ca && IsMajorityElement(nums, cb)) ret.push_back(cb);
    if (cc != cb && cc != ca && IsMajorityElement(nums, cc)) ret.push_back(cc);
    return ret;
  }

 private:
  bool IsMajorityElement(const vector<int> &nums, int c) {
    int n = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == c)
        ++n;
    return n > nums.size() / 3;
  }
};
