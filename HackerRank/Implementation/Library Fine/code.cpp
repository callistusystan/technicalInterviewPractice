#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
#define printArray(array) for (int i=0;i<array.size();i++) { cout << array[i] << " "; } cout << endl;
#define print2DArray(array) for (int i=0;i<array.size();i++) { for (int j=0;j<array[i].size();j++) { cout << array[i][j] << " "; } cout << endl; };
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
int even(int n) { return !(n%2); }
int odd(int n) { return n%2; }
const db pi=3.14159265358979323846264338327950288L;

int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vi date1(3), date2(3);

    cin >> date1[0] >> date1[1] >> date1[2];
    cin >> date2[0] >> date2[1] >> date2[2];

    if (date1[2] > date2[2]){
        cout << 10000 << endl;
    }
    else if (date1[2] == date2[2]){
        if (date1[1] > date2[1]){
            cout << 500*(date1[1]-date2[1]) << endl;
        }
        else if (date1[1] == date2[1]){
            if (date1[0] > date2[0]){
                cout << 15*(date1[0]-date2[0]) << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            cout << 0 << endl;
        }
    }
    else if (date1[2] < date2[2]){
        cout << 0 << endl;
    }



    return 0;
}