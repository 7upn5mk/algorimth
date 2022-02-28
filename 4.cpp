#include <iostream>
#include <ctgmath>

using namespace std;

int main() {
    int b,c,d;
    uint64_t a,k;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> k;
    if (!(a>=1 && b<=1000 && c>=0 && c<=1000 && d>=1 && d<=1000 && a<=d && k>=1 && k)) {
        return 1;
    }
    for (uint64_t i=1;i<=k;i++) {
        uint64_t tmp = a;
        a*=b;
        if (a<=c) {
            a=0;
            break;
        }
        a-=c;
        if (a>=d) {
            a=d;
            break;
        }
        if (tmp==a) {
            break;
        }
    }
    cout << a;
}

