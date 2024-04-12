#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int a, b, c;
    cin >> N;
    while(N-->0){
        cin >> a >> b >> c;
        int temp = 0;
        if(c/2 >= b) temp = a * b;
        else temp = a/2 * c + (a%2) * b;
        cout << temp << endl; 
    }
    return 0;
}