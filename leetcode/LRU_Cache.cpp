class LRUCache{
  int size;
  int timer;
  unordered_map<int, pair<int, int> > T;  // key - value, time
  queue<pair<int, int> > B;  // key, time

  private:
  void dequeue() {  // Make sure the front of the queue is the LRU element.
    while (true) {
      pair<int, int> e = B.front();
      if (e.second == T[e.first].second)
        break;
      B.pop();
    }
  }

  public:
  LRUCache(int capacity) {
    size = capacity;
    timer = 0;
    T.clear();
    while (!B.empty())  // queue does not have clear() method.
      B.pop();
  }

  int get(int key) {
    if (T.find(key) == T.end())
      return -1;

    ++timer;
    T[key].second = timer;
    B.push(make_pair(key, timer));

    dequeue();

    return T[key].first;
  }

  void set(int key, int value) {
    ++timer;

    if (T.find(key) != T.end()) {  // Overwrite existing entry
      T[key] = make_pair(value, timer);
      B.push(make_pair(key, timer));

      dequeue();

      return;
    }

    if (T.size() == size) {
      pair<int, int> e = B.front();
      B.pop();
      T.erase(e.first);  // Delete an entry

      dequeue();
    }

    T[key] = make_pair(value, timer);  // Add a new entry
    B.push(make_pair(key, timer));
  }
};
