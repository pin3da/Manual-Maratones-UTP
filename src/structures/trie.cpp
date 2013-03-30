struct Trie {
  struct Node {
    int ch[26];
    int n;
    Node() {
      n = 0;
      memset(ch,0,sizeof(ch));
    }
  };
  int sz;
  vector < Node > nodes;
  void init() {
    nodes.clear();
    nodes.resize(1);
    sz = 1;
  }
  void insert(const char * s) {
    int idx, cur = 0;

    for (; * s; ++s) {
      idx = * s - 'A';
      if (!nodes[cur].ch[idx]) {
        nodes[cur].ch[idx] = sz++;
        nodes.resize(sz);
      }

      cur = nodes[cur].ch[idx];
    }
  }
};