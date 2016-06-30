#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 1001
#define EPS 1e-8
using namespace std;
int A[MAX];

// d = m/10^floor(log(m))
// log(d) = log(m) - floor(log(m))
double first_digit(double m,int n){
	double aux = m - floor(m);
	if(n <= 10) return floor(pow10(aux));
	else return floor(pow10f(aux + EPS));
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int last = 1; // last digit
		for(int i = 0;i < n;i++){
			scanf("%d",&A[i]);
			last = (last * A[i]) % 10;
		}
		
		double acum = 0;
		for(int i = 0;i < n;i++) acum += log10((double)A[i]);
		
		double first = first_digit(acum,n); // first digit
		
		printf("%.0lf %d\n",first,last);
		
	}
	return 0;
}
