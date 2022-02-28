#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    int s=0;
    int e;
    int max=0;
    for (int i=0;i<n;i++) {
        int c=0;
        int m=0;
        int p=i;
        for (int j=i;j<n;j++) {
            m++;
            if (j+1<n) {
                if (a[j]==a[j+1]) {c++;}
                else {c=0;}
            }
            if (c==2) {
                i=j-1;
                break;
            }
        }
        if (m>max) {
            max=m;
            s=p+1;
            e=p+m;
            if (m==n-i) {
                break;
            }
        }
    }
    cout << s << " " << e;
    return(0);
}