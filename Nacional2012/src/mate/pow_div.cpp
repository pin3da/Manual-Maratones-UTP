int pow_div_fact(int n, int p) {
  int sd = 0; 
  for (int t = n; t > 0; t /= p) 
    sd += t % p; 
  return (n-sd)/(p-1);
}
