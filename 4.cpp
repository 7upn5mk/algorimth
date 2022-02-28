#include <iostream>
#include <ctgmath>

using namespace std;

int main() {
    int a,b,c,d;
    double r,k;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> k;
    if (!(a>=1 && b<=1000 && c>=0 && c<=1000 && d>=1 && d<=1000 && a<=d && k>=1)) {
        return 1;
    }
    r=a*pow(b,k)-c*((pow(b,k)-1)/(b-1));
    if (r>=d) {
        r=d;
    }
    if (r<=0) {
        r=0;
    }
    cout << r << '\n';

    for (long i=1;i<=k;i++) {
        r*=b;
        if (r<=c) {
            r=0;
            break;
        }
        r-=c;
        if (r>=d) {
            r=d;
            break;
        }
    }
    cout << r;
}

