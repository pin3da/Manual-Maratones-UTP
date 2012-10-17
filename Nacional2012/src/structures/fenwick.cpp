//one dimension
// Creates a zero-initialized Fenwick tree for n elements.
vector < int > create(int n){
  return vector < int > (n, 0);
}
// Returns sum of elements with indexes a..b, inclusive
int query(const vector < int > & tree, int a, int b){
  if (a == 0)  {
    int sum = 0;
    for (; b >= 0; b = (b & (b + 1)) - 1)
    sum += tree[b];
    return sum;
  }
  else  {
    return query(tree, 0, b) - query(tree, 0, a - 1);
  }
}
// Increases value of k-th element by inc.
void increase(vector < int > & tree, int k, int inc){
  for (; k < (int) tree.size(); k |= k + 1)
  tree[k] += inc;
}
//Two dimension
typedef long long lint;
typedef unsigned long long ulint;
const int MAX = 1050;
int tree[MAX][MAX], lastx, lasty;
int M[MAX][MAX];
int
readx(int x, int y){
  int sum = 0;
  while (x > 0)  {
    sum += tree[x][y];
    x -= (x & -x);
  }
  return sum;
}
int getsum(int x, int y){
  int sum = 0;
  while (y > 0)  {
    sum += readx(x, y);
    y -= (y & -y);
  }
  return sum;
}
void updatey(int x, int y, int val){
  while (y = lasty)
  {
    tree[x][y] += val;
    y += (y & -y);
  }
}
void update(int x, int y, int val){
  while (x = lastx)  {
    updatey(x, y, val);
    x += (x & -x);
  }
}
int get(int x1, int y1, int x2, int y2){
  int a = getsum(x1 - 1, y1 - 1);
  int b = getsum(x2, y2);
  int c = getsum(x2, y1 - 1);
  int d = getsum(x1 - 1, y2);
  return a + b - c - d;
}