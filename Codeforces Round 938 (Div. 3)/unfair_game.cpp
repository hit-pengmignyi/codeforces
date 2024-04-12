#include<bits/stdc++.h>
using namespace std;

int main(){
	int N = 0;
	int a, b, c, d;
	cin >> N;
	for(int i = 0; i < N; ++i){
		int temp = 0;
		cin >> a >> b >> c >> d;
		temp += (a/2 + b/2 + c/2 + d/2);
		if( a %2 == 1 && b % 2 == 1 && c % 2 == 1)
			temp += 1;
		cout << temp << endl;
	}
	return 0;
} 
