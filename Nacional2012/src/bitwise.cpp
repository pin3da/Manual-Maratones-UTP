typedef unsigned int uint;

//retorna el siguiente entero con la mimsma 
//cantidad de 1's en la representación binaria

uint next_popcount(uint n){
  uint c = (n & -n);
  uint r = n+c;
  return (((r ^ n) >> 2) / c) | r;
}

//retorna el primer entero con n 1's en binario
uint init_popcount(int n){
  return (1 << n) - 1;
}
