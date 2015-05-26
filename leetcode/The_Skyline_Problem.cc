struct Segment {
  int l;
  int r;
  int h;
  int m;
  Segment *lc;
  Segment *rc;

  Segment(
      int left, int right, int mid, Segment *left_child, Segment *right_child)
      : l(left), r(right), h(0), m(mid), lc(left_child), rc(right_child) {}
};

class Solution {
 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> ret;
    if (buildings.empty()) return ret;

    vector<int> endpoints;
    for (auto &b : buildings) {
      endpoints.push_back(b[0]);
      endpoints.push_back(b[1]);
    }
    sort(endpoints.begin(), endpoints.end());

    vector<Segment *> segments;
    queue<Segment *> nodes[2];
    for (int i = 1; i < endpoints.size(); ++i)
      if (endpoints[i - 1] != endpoints[i]) {
        Segment *seg =
            new Segment(endpoints[i - 1], endpoints[i], -1, nullptr, nullptr);
        segments.push_back(seg);
        nodes[0].push(seg);
      }

    int p = 0;
    int q = 1;
    while (nodes[p].size() > 1) {
      while (nodes[p].size() > 1) {
        Segment *left_child = nodes[p].front();
        nodes[p].pop();
        Segment *right_child = nodes[p].front();
        nodes[p].pop();
        nodes[q].push(new Segment(left_child->l, right_child->r, left_child->r,
                                  left_child, right_child));
      }
      if (!nodes[p].empty()) {
        nodes[q].push(nodes[p].front());
        nodes[p].pop();
      }
      swap(p, q);
    }
    Segment *root = nodes[p].front();

    for (auto &b : buildings) {
      Update(root, b[0], b[1], b[2]);
    }

    for (int i = 0; i < segments.size(); ++i)
      if (i == 0 || segments[i - 1]->h != segments[i]->h)
        ret.push_back(make_pair(segments[i]->l, segments[i]->h));
    ret.push_back(make_pair(segments[segments.size() - 1]->r, 0));
    return ret;
  }

 private:
  void Update(Segment *seg, int xl, int xr, int ht) {
    if (seg->h > ht) return;

    if (xl <= seg->l && seg->r <= xr) seg->h = ht;

    if (seg->m == -1) return;

    if (xl < seg->m) Update(seg->lc, xl, xr, ht);
    if (seg->m < xr) Update(seg->rc, xl, xr, ht);
  }

};
