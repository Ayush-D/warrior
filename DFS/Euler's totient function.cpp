Euler's totient function, also known as phi-function ϕ(n), counts the number of integers between 1 and n inclusive, which are coprime to n,
Two numbers are coprime if their greatest common divisor equals 1 (1 is considered to be coprime to any number).

Since we have to factorize n in order to calculate ϕ(n), 
we can modify our factorize() function from post “Prime Factorization of Integer Number” to handle Euler Phi.

ϕ(n) = n×((p1–1)/p1)×((p2–1)/p2) .... × ((pk–1)/pk).

**********************See Seive from Prime Factorization of Number*******************

// For Single Number not good for multiple numbers rather use Seive for this, take this just as hint, Code like Prime Factorization 
// of Numbers

int eulerPhi ( int n ) {
    int res = n;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
            }
            sqrtn = sqrt ( n );
            res /= prime[i];              // first we are dividing so that there will not any overflow
            res *= prime[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}

************************* Using Sieve *************************

int main(){
// Calculate phi from 1 to n using sieve
    MYREP(i,1,n) phi[i] = i;
    MYREP(i,2,n) {
        if ( phi[i] == i ) {
        for ( int j = i; j <= n; j += i ) {
            phi[j] /= i;
            phi[j] *= i - 1;
        }
    }
 }
 }
