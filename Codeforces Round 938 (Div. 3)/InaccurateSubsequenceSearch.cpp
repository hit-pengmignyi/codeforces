#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int a, b, k;
    cin >> N;
    while(N-->0){
        cin >> a >> b >> k;
        vector<int> na;
        map<int, int> cb;
        int tep;
        int tr = 0;
        int ans = 0;
        for(int i = 0; i < a; ++i){
            cin >> tep;
            na.push_back(tep);
        }
        for(int i = 0; i < b; ++i){
            cin >> tep;
            cb[tep] += 1;
        }
        //初始化
        for(int i = 0; i < b; ++i){
            cb[na[i]] -= 1;
            if(cb[na[i]] >= 0) tr += 1;
        }
        if(tr >= k) ans += 1;
        for(int i = 1; i < a - b + 1; ++i){
            cb[na[i-1]] += 1;
            if(cb[na[i-1]] > 0) tr -= 1;
            cb[na[i+b-1]] -= 1;
            if(cb[na[i+b-1]] >= 0) tr += 1;
            if(tr >= k) ans += 1;
        }
        cout << ans << endl;
    }
    

}