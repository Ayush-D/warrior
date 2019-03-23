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
