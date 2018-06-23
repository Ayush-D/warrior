// Program to print all prime factors, Let N = (2^5) * (3^4) * (5^3) * 7 .
// I used vector of pair first is prime no, and second is its times of its occurrences. 
# include <bits/stdc++.h>
using namespace std;

std::vector<pair<int,int> > v;
// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    int cnt=0;
    while (n%2 == 0)
    {
        //printf("%d ", 2);
        ++cnt;
        n = n/2;
    }
    if(cnt!=0)
    v.push_back(make_pair(2,cnt));

    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i*i <= n; i = i+2)
    {   
        cnt=0;
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            //printf("%d ", i);
            ++cnt;
            n = n/i;
        }
          if(cnt!=0)
          v.push_back(make_pair(i,cnt));
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2){
        v.push_back(make_pair(n,1));
     //   printf ("%d ", n);
    }
}
 
/* Driver program to test above function */
int main()
{
    int n = (int)1e5;
    primeFactors(n);
    for(int i=0;i<v.size();i++){
        std::cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}
