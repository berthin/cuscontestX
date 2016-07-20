#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 10005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
typedef pair< ll, ll > pll;
int n, frec[MAX];
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        memset(frec, 0, sizeof frec);
        for(int i=n-1;i>=0;i--)
        {
            int x;
            scanf("%d", &x);
            frec[x]++;            
        }
        vi ans;
        ans.clear();
        for(int i=1;i<=n;i++)
            if(frec[i]==1) ans.push_back(i);
        
        if(ans.size()!=1)
            printf("Devagar\n");
        else
            printf("%d\n", ans[0]);
    }
}


