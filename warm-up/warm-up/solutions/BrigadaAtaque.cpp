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
int force[MAX], n;
int best[MAX];
int LIS()
{
    int ans=1;
    best[0] = force[0];
    for(int i=1;i<n;i++)
    {
        if(force[i]>best[ans-1])
        {
            best[ans++] = force[i];
            continue;
        }
        int pos = lower_bound(best, best + ans, force[i]) - best;
        best[pos] = force[i];
    }
    return ans;
}
int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(int i=n-1;i>=0;i--)
            scanf("%d", &force[i]);
        printf("%d\n", LIS());
    }
}


