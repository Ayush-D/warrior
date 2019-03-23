Question: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/query-multiples-6cf951be/description/
Solution: Mine or Kmcode are best

Factors are Finite divisors while Multiples are infinite numbers.
Eg: Factors(9): 1 3 9
    Multiples(9): 9 18 27 36 45 .....
    
int main(){
    std::vector<int> v[MAX];
    
    //Factor of Number's 
    for(int i = 1; i <= MAX; i++){
        for(int j = i; j < MAX; j+=i){
            v[j].pb(i);
        }
    }

    for(int i = 1; i <= MAX; i++){
        for(auto x: v[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

int main(){

std::vector<int> v[41];
    
    //Multiples of Number's
    for(int i = 1; i <= MAX; i++){
        for(int j = i; j < MAX; j+=i){
            v[i].pb(j);                  // Only Difference here
        }
    }

    for(int i = 1; i <= MAX; i++){
        for(auto x: v[i]){
            cout<<x<<" ";
        }
        cout<<nl;
    }
}

**************Abdullah's Prime Code*************
int main(){
    int N = (int)1e6 + 5;
    LL pr[N];
    fill(pr,pr+N,0);
    for(int i=2;i<N;i++)
    {
        if(pr[i]==0)
        {
            for(int j=i+i;j<N;j+=i)
                pr[j]++;
            pr[i]=1;
        }
    }
}

***********Ashish Gupta's Prime Code**************
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

Solve Problem: https://www.codechef.com/WCS2019/problems/WCSE (using any of Ashish or Abdullah Code)

