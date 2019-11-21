#include <bits/stdc++.h>
using namespace std;
const int N = 103;
long long dp[10][N];


int main(){

    int n;
    cin>>n;

    for(int i=0;i<=9;i++)
        dp[i][1]=1;

    for(int digit=0;digit<=9;digit++){
        for(int i=0;i<=digit;i++){
            for(int ln=2;ln<=n;ln++){
                dp[digit][ln]+=dp[digit][ln-1];
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<=9;i++)
        ans+=dp[i][n];

    cout<<ans;

return 0;}
