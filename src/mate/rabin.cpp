/**
* Miller-Rabin. La probabilidad de error disminuye al aumentar
* el numero de iteraciones. Dicha probalidad es 1/4^iter
*/

long long modpow(long long a,long long b,long long c){
  long long x = 0,y=a%c;
  while(b > 0){
    if(b&1) x = (x+y)%c;
    y = (y*2)%c;
    b>>=1;
  }
  return x%c;
}
long long modmul(long long a,long long b,long long m){
  return (((a*(b>>20)%m)<<20)+a*(b&((1<<20)-1)))%m;
}

bool Miller(long long p,int iteration){
  if(p<2)
    return false;
  if(p!=2 && p%2==0)
    return false;
  long long s = p-1;

  while(s%2==0)s>>=1;

  for(int i=0;i<iteration;i++){
    long long a=rand()%(p-1)+1,temp=s;
    long long mod=modpow(a,temp,p);
    while(temp!=p-1 && mod!=1 && mod!=p-1){
      mod=modmul(mod,mod,p);
      temp <<=1;
    }
    if(mod!=p-1 && temp%2==0){
      return false;
    }
  }
  return true;
}
