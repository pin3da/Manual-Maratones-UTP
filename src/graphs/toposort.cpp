queue<int> Q;

for(int i=0;i<v;++i)
  if(in[i]==0) Q.push(i);

while(!Q.empty()){
  int act = Q.front();Q.pop();
  for(int i=0;i<G[act].size();++i){
    in[G[act][i]]--;
    if(in[G[act][i]]==0) Q.push(G[act][i]);
  }
}