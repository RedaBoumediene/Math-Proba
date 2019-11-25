/*
  given n and conut number of divisor of n!
  read this before : https://github.com/RedaBoumediene/Math-Proba/blob/master/LargestPowerOfNumThatDivideFact.cpp
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e+3;

int primeOf[N];
bool flags[N];

vector<int> factors,primes;

void sieve(){
    for(int i=2;i<N;i++){
        if(!primeOf[i]){
            primeOf[i]=i;
            primes.push_back(i);
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
    int n;
    cin>>n;

    sieve();

    for(int i=0;;i++){
        if(primes[i]<=n)
            factors.push_back(primes[i]);
        else
            break;
    }

    long long res = 1;

    for(int i=0;i<factors.size();i++)
        res *= (LargestPowerOfPrime(n,factors[i])+1);

    //for(int i=0;i<factors.size();i++)
    //    cout<<factors[i]<<" "<<LargestPowerOfPrime(n,factors[i])<<endl;
    //cout<<endl;

    cout<<res<<endl;

    return 0;
}
