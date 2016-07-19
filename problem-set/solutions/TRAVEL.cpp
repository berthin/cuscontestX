#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double vt,vo,d;
		cin >> vt >> vo >> d;
		if(vt <= vo) printf("-1\n");
		else printf("%.10lf\n",d/(vt - vo));
	}
	return 0;
}

