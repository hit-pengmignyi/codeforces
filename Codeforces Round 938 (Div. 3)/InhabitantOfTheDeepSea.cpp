#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, n;
    long long k; //得是long long才能处理
    cin >> N;
    while(N-- > 0){
        cin >> n >> k;
        vector<int> dura;
        int temp;
        for(int i = 0; i < n; ++i){
            cin >> temp;
            dura.push_back(temp);
        }
        int hit = 0, q = dura.size()-1;
        int ans = 0;
        while(k > 0){
            if(hit == q){ //只有一艘船
                ans += k >= dura[hit] ? 1 : 0;
                break;
            }
            else{ //至少两艘船
                if(dura[hit] <= dura[q]){
                    if(k >= dura[hit] * 2 - 1){ // 能够击沉
                        k -= (dura[hit] + dura[hit] - 1);
                        // cout << "K1:" << k << endl;
                        dura[q] -= (dura[hit] - 1);
                        dura[hit] -= dura[hit];
                        ans += 1;
                        // 交换击打位置
                        int temp = hit < q ? hit+1 : hit-1;
                        hit = q;
                        q = temp;
                    }
                    else{ // 不能够击沉
                        break;
                    }
                } 
                else{
                    if(k >= dura[q] * 2){ // 能够击沉
                        k -= (dura[q] + dura[q]);
                        //cout << "K2:" << k << endl;
                        dura[hit] -= dura[q];
                        dura[q] -= dura[q];
                        ans += 1;
                        // 无需交换击打位置
                        q = hit < q ? q-1 : q+1;
                    }
                    else{ // 不能够击沉
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}