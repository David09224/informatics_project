#include <iostream>
typedef long long ll;

using namespace std;

int N, M;
int nxt[5001];
int cost[5001];
int visited[5001];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=M; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        nxt[a]=b;
        cost[a]=c;
    }
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int x, K;
        scanf("%d %d", &x, &K);
        for(int i=1; i<=N; i++) visited[i]=0;
        int c=0, f=1, prv=x;
        for(int i=0; i<K; i++){
            visited[x]=1;
            c+=cost[x];
            prv=x;
            x=nxt[x];
            if(x==0){
                f=0;
                break;
            }
            if(visited[x]==1){
                f=2; break;
            }
        }
        if(f==1) printf("%d %d\n", x, c);
        if(f==0) printf("%d\n", prv);
        if(f==2) printf("CYCLE\n");
    }
    return 0;
}
/*for(int i=1; i<=n; i++){
        int x=i, cnt=0, C=0;

        for(int j=0; j<=n; j++) visited[j]=0;
        visited[i]=1;
        while(1){
            memo[i][cnt]=x;
            if(cnt>0){
                c[i][cnt]=C;
            }
            cnt++;
            C+=cost[x];
            x=nxt[x];

            if(x==0 || cnt>n || visited[x]==1) break;
        }
        for(int j=0; j<=n; j++) printf("%d ", c[i][j]);
        printf("\n");
    }*/
