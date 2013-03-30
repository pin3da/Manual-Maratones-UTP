struct something{
    int price,cost;
	something(){}
	something(int P,int C):cost(C),price(P){}
};

vector <someting> todos;
//Llenar el vector con los datos correspondientes.

int dp[tengo+1];

dp[0] = 0;

for(int i = 0;i<=tengo;++i){
  int mm = 0;
  for(int j = 0; j<n ;++j)
    if(i - todos[j].p >= 0 )
  mm = max(mm, dp[i-todos[j].p] + todos[j].c);
  dp[i] = mm;
}

cout<<dp[tengo]<<endl;