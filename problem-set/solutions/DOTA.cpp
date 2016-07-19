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
int n,m,p;
int T;
bool ady[N][N];
int vis[N];
int s1_len,s2_len;
int s2[N];

bool kunt(int u){
	f(v,0,s2_len){
		if(ady[u][v] && !vis[v]){
			vis[v]=true;
			if(s2[v]<0 || kunt(s2[v])){
				s2[v]=u;
				return true;
			}
		}
	}
	return false;
}
int max_maching(){
	int ans=0;
	clr(s2,-1);
	f(i,0,s1_len){
		clr(vis,0);
		ans+=kunt(i);
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	in(T);
	while(T--){
		clr(ady,0);
		in3(n,m,p);
		int u,v;
		f(i,0,p){
			in2(u,v);
			ady[u][v]=true;
		}
		s1_len=n+1;
		s2_len=m;
		cout<<max_maching()-1<<endl;	
	}
	return 0;
}