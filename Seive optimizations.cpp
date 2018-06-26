#include <bits/stdc++.h>

using namespace std;

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


    //Sum of Divisors Sieve O(n log n)
    int sumdiv[n + 1]{0};
    for (int i = 1; i <= n; ++i)
     for (int j = i; j <= n; j += i)
      sumdiv[j] += i;
    
    //Prints all divisors sum from 1 to N
    for(int i=1;i<=n;i++){
        cout<<sumdiv[i]<<" ";
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
