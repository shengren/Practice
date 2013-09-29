class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
      int residual = 0;
      int min_residual = 0;
      int idx_min_residual = -1;
      for (int i = 0; i < gas.size(); ++i) {
        residual = residual + gas[i] - cost[i];
        if (idx_min_residual == -1 || min_residual > residual) {
          idx_min_residual = i;
          min_residual = residual;
        }
      }
      if (residual < 0)
        return -1;
      return (idx_min_residual + 1) % gas.size();
    }
};
