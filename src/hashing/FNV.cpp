unsigned fnv_hash (void *key, int len ){
  unsigned char *p = key;
  unsigned h = 2166136261;
  for (int i = 0; i < len; i++ )
    h = ( h * 16777619 ) ^ p[i];
  return h;
}
