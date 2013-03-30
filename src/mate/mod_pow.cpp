// Retorna (a^b)%c
long long mod_pow(long long a,long long b,long long c){
  long long x = 0,y=a%c;
  while(b > 0){
    if(b%2 == 1)
      x = (x+y)%c;
      y = (y*2)%c;
      b>>=1;
    }
  return x%c;
}