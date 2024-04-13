/*
这道题考差分数组
暴力是n^2*k,优化之后是n^2
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, n;
    cin >> N;
    while(N-->0){
        cin >> n;
        string temp;
        cin >> temp;
        vector<int> input(temp.size());
        vector<int> dif(temp.size());
        for(int i = 0; i < n; ++i){
            input[i] = temp[i] - '0';
        }
        dif[0] = input[0];
        for(int i = 1; i < n; ++i){
            dif[i] = input[i] - input[i-1];
        }
        int maxlength = 1;
        for(int i = n; i > 1; i--){
            vector<int> inputcopy = input;
            vector<int> difcopy = dif;
            for(int j = 0; j <= n-i; j++){
                if(j == 0){
                    if((difcopy[j] + 0)%2==0){ // 翻转[j, j+i-1]
                        difcopy[j] += 1;
                        if(j+i < n) difcopy[j+i] -= 1;
                    }
                    inputcopy[j] = difcopy[j] + 0;
                }
                else{
                    if((difcopy[j] + inputcopy[j-1])%2==0){ // 翻转[j, j+i-1]
                        difcopy[j] += 1;
                        if(j+i < n) difcopy[j+i] -= 1;
                    }
                    inputcopy[j] = difcopy[j] + inputcopy[j-1];
                }
            }
            bool ok = true;
            for(int j = n-i; j < n; ++j){
                if(j != 0){
                    if(!((difcopy[j] + inputcopy[j-1]) % 2)){
                        ok = false;
                        break;
                    }
                    inputcopy[j] = difcopy[j] + inputcopy[j-1];
                }
                else{
                    if(!((difcopy[j] + 0) % 2)){
                        ok = false;
                        break;
                    }
                    inputcopy[j] = difcopy[j] + 0;
                }
            }
            if(ok){
                maxlength = i;
                break;
            }
        }
        cout << maxlength << endl;
    }
}