#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fx(i,x,y) for (i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define eps (1e-9)
#define oo (1<<30)
#define OO (1LL<<60)
#define N 110
#define in(i) cin>>i
#define in2(i,j) cin>>i>>j
#define in3(i,j,k) cin>>i>>j>>k
#define out(i) cout<<i
#define out2(i,j) cout<<i<<j
#define out3(i,j,k) cout<<i<<j<<k
#define readint(i) scanf("%d",&i)
#define readchr(i) scanf("%c",&i) 
#define readint2(i,j) scanf("%d %d",&i,&j)
#define readint3(i,j,k) scanf("%d %d %d",&i,&j,&k)
#define readstr(i) scanf("%s",i)
#define printint(i) printf("%d\n",i)
using namespace std;
typedef long long int ll;

typedef vector<int> vint;
typedef set<int> sint;
typedef vector<double> vdb;

int main(int argc, char const *argv[])
{
	int T;
	in(T);
	while(T--){
		int m,d;
		in2(m,d);
		int base=-1;
		f(i,2,8){
			
			if((int)pow(i,d)==m){
				base=i;	
				break;
			}
		}	
		int ans=0;
		f(i,1,base+1){
			ans+=(int)pow(i,d);
		}
		cout<<ans<<endl;
	}
	return 0;
}