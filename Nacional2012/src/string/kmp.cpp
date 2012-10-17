/*
 * String Matching KMP
 * preprocessing time: O(m) - pattern
 * matching time: O(n) - text
 *
 * Key idea:
 * prefix function : pi
 * pi[q] = max { k : k < q and P_k is suffix of P_q }
 * P_i are the i first characters of the pattern
 */
static int[] compute_prefix_function(char[] p) {
  int[] pi = new int[p.length];
  pi[0] = -1;
  int k = -1;
  for (int i = 1; i < p.length; i++) {
    while (k >= 0 && p[k + 1] != p[i]) k = pi[k];
    if (p[k + 1] == p[i]) k++;
    pi[i] = k;
  }
  return pi;
}

static void KMP_Matcher(String pattern, String text) {
  char[] p = pattern.toCharArray();
  char[] t = text.toCharArray();
  int[] pi = compute_prefix_function(p);
  int q = -1;
  for (int i = 0; i < text.length(); i++) {
    while (q >= 0 && p[q + 1] != t[i]) q = pi[q];
    if (p[q + 1] == t[i]) q++;
    if (q == p.length - 1) {
      //	Pattern matched in  position i-p.length+1
      q = pi[q];
    }
  }
  return;
}
