unsigned jsw_hash ( void *key, int len ){
  unsigned char *p = key;
  unsigned h = 16777551;
  for (int i = 0; i < len; i++ )
    h = ( h << 1 | h >> 31 ) ^ tab[p[i]];
  return h;
}