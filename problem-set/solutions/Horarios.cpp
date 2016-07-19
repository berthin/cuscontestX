#include<bits/stdc++.h> //g++ -std=c++11

#define inf 1<<30
#define repall(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define rep(i,x,y) for (int i = x; i < y; i++)
#define irep(i,x,y) for (int i = x; i >= y; i--)
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define mp make_pair
#define MAX 100005

using namespace std;

typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long int i64;
typedef vector < i64 > vi64;

bool cmp(pii a, pii b){
  return (a.first < b.first | (a.first == b.first && a.second < b.second));
}

int solve(){
  int N, t_init, t_end;
  cin >> N;
  vii times(N);
  rep(i, 0, N){
    cin >> t_init >> t_end;
    times[i] = mp(t_init, t_end);
  }
  sort(times.begin(), times.end(), cmp);

  stack <pii> S;
  pii prv_interval;
  S.push(times[0]);
  rep(i, 1, N){
    if (S.top().first <= times[i].first  && times[i].first <= S.top().second){
      times[i].first = S.top().first;
      times[i].second = max(S.top().second, times[i].second);
      S.pop();
    }
    S.push(times[i]);
  }
  int mx_interval_milked = 0;
  int mx_interval_non_milked = 0;
  prv_interval = S.top();
  while(true){
    mx_interval_milked = max(mx_interval_milked, prv_interval.second - prv_interval.first);
    S.pop();
    if (S.empty()) break;
    mx_interval_non_milked = max(mx_interval_non_milked, prv_interval.first - S.top().second);
    prv_interval = S.top();
  }
  cout << mx_interval_non_milked << " " << mx_interval_milked << endl;
}

int main(){
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
