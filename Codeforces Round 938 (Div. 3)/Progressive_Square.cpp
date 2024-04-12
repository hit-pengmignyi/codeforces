#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int a, b, c;
    cin >> N;
    while(N-->0){
        int temp;
        vector<int> record;
        cin >> a >> b >> c;
        for(int i = 0; i < a * a; ++i){
            cin >> temp;
            record.push_back(temp);
        }
        sort(record.begin(), record.end());
        vector<int> origin;
        int startnum = record[0];
        for(int i = 0; i < a; ++i)
            origin.push_back(startnum + c * i);
        for(int i = 1; i < a; ++i)
            for(int j = 0; j < a; ++j)
                origin.push_back(origin[j]+ i * b);
        sort(origin.begin(), origin.end());
        bool yes = true;
        for(int i = 0; i < a * a; ++i)
            if(origin[i] != record[i]){
                yes = false;
                break;
            }
        if(yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}