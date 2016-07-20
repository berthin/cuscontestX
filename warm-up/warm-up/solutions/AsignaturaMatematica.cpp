#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 50005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
typedef pair< ll, ll > pll;
string solution(int x, int y, int z)
{
    if(x - y == z) return "-";
    if(x + y == z) return "+";
    if(x * y == z) return "*";
    if(x / y == z) return "/";
}
int main()
{
    int x, y, z;
    while(scanf("%d %d %d", &x, &y, &z)==3)
    {
        if(x==0 && y==0 && z==0) break;
        cout<< solution(x, y, z) <<endl;
    }
}


