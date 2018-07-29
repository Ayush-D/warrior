//See https://cp-algorithms.com/algebra/divisors.html no need to see below... except biggest prime divisor of number
#include <bits/stdc++.h>

using namespace std;
//***********************************************************************\\
//                   Forget from GeeksforGeeks and use this
//Using C++ bitset and much more optimisations
//Taken from https://github.com/kartikkukreja/blog-codes/blob/master/src/spoj_CPRIME.cpp

const int MAX = (int)1e8 + 8;

bitset<MAX/2+1> num;
vector<int> primes;

void EratostheneSieve() {
    int x = MAX/2, y =(sqrt(MAX)-1)/2, i, j, z;
    for (i = 1; i <= y; ++i) {
        if (num[i] == 0) {
            for (j = (i*(i+1))<<1, z = (i<<1); j <= x; j += z+1) {
                num[j] = 1;
            }
        }
    }
    primes.emplace_back(2);
    for (i = 3; i < MAX; i += 2) {
        if (!num[i>>1]) primes.emplace_back(i);
    }
}
//*************************************************************************\\

int main () {
    //precal( (int)1e7 );
    int n;
    cin>>n;
    
    //Divisor Sieve O(n log n)
    int divisors[n + 1]{0};
    for (int i = 1; i <= n; ++i)
     for (int j = i; j <= n; j += i)
      ++divisors[j];

    //Prints No of divisors from 1 to N
    for(int i=1;i<=n;i++){
        cout<<divisors[i]<<" ";
    }


    //Sum of all (including primes and non primes) Divisors Sieve O(n log n)
    int sumdiv[n + 1]{0};
    for (int i = 1; i <= n; ++i)
     for (int j = i; j <= n; j += i)
      sumdiv[j] += i;
    
    //Prints all divisors sum from 1 to N
    for(int i=1;i<=n;i++){
        cout<<sumdiv[i]<<" ";
    }
   
    //Sum of all prime Divisors of a number O(nlogn)
    int primediv[n+1]{0};
    for(int i=2;i<=n;i++){
        if(primediv[i] == 0){
            for(int j=i; j<=n; j+=i){
                primediv[j] += i;
            }
        }
    }
    //Print all divisors sum of primes till 1 to N
    for(int i=0; i<n; i++){
        cout<<primediv[i]<<" ";
    }
    
    //Biggest Prime Divisor Sieve O(n log log n)
    int big[n + 1] = {1, 1};
    for (int i = 1; i <= n; ++i)
     if (big[i] == 1)
      for (int j = i; j <= n; j += i)
       big[j] = i; 

    for(int i=1;i<=n;i++){
        cout<<big[i]<<" ";
    }

    //Euler Totient Sieve O(n log log n) also see for this https://forthright48.blogspot.com/search/label/LCM
    int totient[n + 1];
    for (int i = 1; i <= n; ++i) totient[i] = i;
    for (int i = 2; i <= n; ++i)
     if (totient[i] == i)
      for (int j = i; j <= n; j += i)
       totient[j] -= totient[j] / i;


}
