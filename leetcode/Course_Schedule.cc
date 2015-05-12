class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> outedges(numCourses);

    for (auto &e : prerequisites) {
      ++indegree[e[0]];
      outedges[e[1]].push_back(e[0]);
    }

    // return BFS(numCourses, indegree, outedges);

    for (int i = 0; i < numCourses; ++i)
      if (indegree[i] == 0)
        DFS(i, indegree, outedges);

    for (int i = 0; i < numCourses; ++i)
      if (indegree[i] != -1)
        return false;
    return true;
  }

 private:
  bool BFS(int numCourses, vector<int> &indegree, const vector<vector<int>> &outedges) {
    queue<int> zeroin;
    int done = 0;
    for (int i = 0; i < numCourses; ++i)
      if (indegree[i] == 0) {
        zeroin.push(i);
        ++done;
      }

    while (!zeroin.empty()) {
      int x = zeroin.front();
      zeroin.pop();
      for (int y : outedges[x]) {
        if (--indegree[y] == 0) {
          zeroin.push(y);
          ++done;
        }
      }
    }
    
    return done == numCourses;
  }

  void DFS(int x, vector<int> &indegree, const vector<vector<int>> &outedges) {
    indegree[x] = -1;  // in-degree = 0 and visited
    for (int y : outedges[x])
      if (--indegree[y] == 0)
        DFS(y, indegree, outedges);
  }
};
