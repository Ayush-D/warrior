It is possible to find NOD(Number of Divisors) from prime factorization of N. Suppose N=12. 
Its prime factorization is 2^2×3. Is it possible to divide 12 with 5? 
No. Cause the prime factorization of 12 does not contain 5. We can divide N with primes that appear in factorization of N.
Next, can we divide 12 with 2^3? No. The power of 2 in prime factorization of 12 is 2^2. 
So we cannot divide 12 with 2^3, since 2^2 is not divisible by 23.
Take Help from Here for NOD(): https://forthright48.com/2015/07/number-of-divisors-of-integer.html

It is possible to find SOD(N) using the prime factorization of N. Let us see an example for it.
Let N=12, 
SOD(12)=1+2+3+4+6+12, 
SOD(12)=(2^0×3^0)+(2^1×3^0)+(2^0×3^1)+(2^2×3^0)+(21×3^1)+(2^2×3^1), 
SOD(12)=2^0(30+31)+2^1(30+31)+2^2(30+31), 
SOD(12)=(2^0+2^1+2^2)×(3^0+3^1)
Take Help from Here for SOD(): https://forthright48.com/category/cpps/number-theory/page/9 


**********************Prime Factorization of Number (Full Working Code) **********************

const int N = 1e6 + 5;
int seive[N];

void pre(){
    fill(seive+2, seive+N, 1);

    for(int i = 2; i < N; i++){
        if(seive[i]){
            for(int j = 2; j*i <= N; j++){
                seive[i*j] = 0;
            }
        }
    }

}

int main(){
    
    pre();
    int n;
    cin>>n;

    std::vector<int> v, factor;
    REP(i,(int)1e5+5){
        if(seive[i])    v.pb(i);
    }
    
    int sqrts = sqrt(n);
    for(int i = 0; v[i] <= sqrts && i <= v.size(); i++){
        if(n%v[i] == 0){
            while(n%v[i] == 0){
                factor.pb(v[i]);
                n /= v[i];
            }
            sqrts = sqrt(n);
        }
    }
    if(n!=1)    factor.pb(n);   // Important to Check if number is not 1 then the only prime greater than 1 is n.

    REP(i,factor.size()){
        cout<<factor[i]<<" ";
    }

}

***************Number of Prime Factors/or Prime Numbers in the Range*****************

const int N = 1e6 + 5;
int seive[N];

void precompute()
{
	fill(seive+2, seive+N, 1);
	for(int i=2;i<N;i++)
	{
		if(seive[i])
		{
			for(int j=2;i*j<N;j++)
			{
				cnt[i*j]++;         // Only this part to analyze this yourself :)  for prime Number's add cnt[i*j].pb(i)  :))
				seive[i*j]=0;
			}
			cnt[i]++;               // For Prime Number's to add Themself, LOL :))
		}
	}
}
