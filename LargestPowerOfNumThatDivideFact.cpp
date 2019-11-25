/*
    Find maximum power of a number k that divides a factorial n!
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;

int primeOf[N];
bool flags[N];

vector<int> factors;

void sieve(){
    for(int i=2;i<N;i++){
        if(!primeOf[i]){
            primeOf[i]=i;
            for(int j=i+i;j<N;j+=i){
                if(!primeOf[j])
                    primeOf[j]=i;
            }
        }
    }
}

int LargestPowerOfPrime(int n,int k){
    int ans=0;
    while(n>0){
        n/=k;
        ans+=n;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;

    sieve();

    int tmp = k;

    while(tmp>1){
        if(primeOf[tmp]!=1 && !flags[primeOf[tmp]]){
            factors.push_back(primeOf[tmp]);
            flags[primeOf[tmp]]=true;
        }

        tmp/=primeOf[tmp];
    }

    int res = 100000;

    for(int i=0;i<factors.size();i++)
        res = min(res,LargestPowerOfPrime(n,factors[i]));

    cout<<res<<endl;

    return 0;
}
