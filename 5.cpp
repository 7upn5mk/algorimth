#include <iostream>
#include <vector>

using namespace std;

//progressive cows, binary search
int main() {
    size_t n,k;
    cin >> n;
    cin >> k;
    vector<size_t> a(n);
    for (auto& i : a) {std::cin >> i;}
    size_t l  = 0;
    size_t r = a.back()-a[0]+1;
    while(l<r) {
        size_t mid=(l+r)/2;
        size_t cows=1;
        size_t last=a[0];
        for(size_t i=1;i<n;i++) {
            size_t cur=a[i];
            if((cur-last)>mid) {
                cows+=1;
                last=cur;
            }
        }
        if(cows<k) {r=mid;} else {l=mid+1;}
    }
    cout << l;
}