double T[MAXP][MAXP];
bool comp[MAXP][MAXP];
double point[MAXP][2];
int N;

double dist(int p1, int p2) {
    double ans = 0;
    for (int i=0; i<2; i++) {
        ans += SQ(point[p1][i]-point[p2][i]);
    }
    return sqrt(ans);
}
    

double minTour(int e1, int e2) {
    if (e1==N-1 || e2==N-1) return dist(e1,e2);
    if (comp[e1][e2]) return T[e1][e2];
    
    int n = max(e1,e2)+1;
    double d1 = minTour(n,e2) + dist(e1,n);
    double d2 = minTour(e1,n) + dist(e2,n);
    
    T[e1][e2] = min(d1,d2); T[e2][e1]=T[e1][e2];
    comp[e1][e2] = true; comp[e2][e1]=true;
    return T[e1][e2];
}

int main() {
    while ( scanf("%d",&N) != EOF ) {
        for (int i=0; i<N; i++) {
            scanf("%lf %lf", &point[i][0], &point[i][1]);
        }
        for (int i=0; i<=N; i++)
            for (int j=0; j<=N; j++)
                comp[i][j]=false;
        double ans = minTour(0,0);
        printf("%.2lf\n",ans);
    }
}
