class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> outedges(numCourses);

    for (const auto &p : prerequisites) {
      ++indegree[p.first];
      outedges[p.second].push_back(p.first);
    }

    vector<int> ret;
    for (int i = 0; i < numCourses; ++i)
      if (indegree[i] == 0)
        DFS(i, indegree, outedges, ret);
    
    if (ret.size() != numCourses)
      return vector<int>();
    return ret;
  }

 private:
  void DFS(int k, vector<int> &indegree, const vector<vector<int>> &outedges, vector<int> &ret) {
    ret.push_back(k);
    indegree[k] = -1;
    for (int i = 0; i < outedges[k].size(); ++i)
      if (--indegree[outedges[k][i]] == 0)
        DFS(outedges[k][i], indegree, outedges, ret);
  }
};
