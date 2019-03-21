// Lower Bound in C++.
Lower Bound: The bottom range from which the function starts to grow monotonically. If function not touches that Range's Bottom then
take the next higher range's value.

int main(){
    int n, a[100005];
    cin>>n;
    REP(i,n){
        cin>>a[i];
    }

    int x;
    cin>>x;
    auto it = lower_bound(a,a+n,x);
    cout<<it - a<<nl;
    
    // Implementing it as code :)
    int l = 0, r = n, ans = -1;
    while(l < r){
        int mid = l+r >> 1;
        if(a[mid] >= x){
            ans = mid;
            r = mid;
        }
        else l = mid+1;
    }
    // assuming valid answer, check if ans != -1
    if(ans != -1)
    cout<<ans;

}
