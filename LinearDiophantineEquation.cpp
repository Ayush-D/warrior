#include <bits/stdc++.h>
using namespace std;
// This is Extended Euclid Part
int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

//For finding all the solutions for the LDE in the given range 1. Method 1 ->

void shift_solution (int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions (int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (! find_any_solution (a, b, c, x, y, g))
        return 0;
    a /= g;  b /= g;

    int sign_a = a>0 ? +1 : -1;
    int sign_b = b>0 ? +1 : -1;

    shift_solution (x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution (x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift_solution (x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution (x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution (x, y, a, b, - (miny - y) / a);
    if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift_solution (x, y, a, b, - (maxy - y) / a);
    if (y > maxy)
        shift_solution (x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap (lx2, rx2);
    int lx = max (lx1, lx2);
    int rx = min (rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}

// Method 2 from GeeksforGeeks

// function to find the solution just write : solution(a,b,c); inside main function
void solution(int a, int b, int n)
{
    // traverse for all possible values
    for (int i = 0; i * a <= n; i++) {
 
        // check if it is satisfying the equation
        if ((n - (i * a)) % b == 0) {
              if((n - (i * a)) / b >= 0)
              cout<<"YES";
            else  cout<<"NO";
            return;
        }
    }
 
    cout << "NO";
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int x = 0,y = 0,g = 0;  //Take any values doen't matter
    
    //find_all_solutions (int a, int b, int c, int minx, int maxx, int miny, int maxy) is the function 
    //where minx<=x<=maxx && miny<=y<=maxy
    if(find_all_solutions(a,b,c,0,10000,0,10000)>0){
            cout<<"Yes";
            return 0;
    }
    cout<<"No";

}
