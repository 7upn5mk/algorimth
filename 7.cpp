#include <iostream>
#include <vector>

using namespace std;

struct LETTER {
    int value=0;
    int amount=0;
};
//true if a>b
bool compare(pair<int,int>& a,pair<int,int>& b) {
    return a.first<b.first;
}

int main() {
    vector<pair<int,int>> v; //value,amount
    //map<char,LETTER> m = map<char,LETTER>();
    string s;
    cin >> s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0;i<26;i++) {
        int j;
        cin >> j;
        v.emplace_back(j,0);
    }
    for (char c:s) {
        size_t pos=alphabet.find(c);
        v[pos].second+=1;
    }
    //sort(v.begin(),v.end());
//    for (auto& a:v) {
//        cout << a.first << " " << a.second << "\n";
//    }

//    //sort(m.begin(),m.end(), compare);
    for (int i=26-1;i>=0;--i) {
        for (int j=0;j<i;++j) {
            if (compare(v[j],v[j+1])) {
                swap(v[j],v[j+1]);
                swap(alphabet[j],alphabet[j+1]);
            }
        }
    }

//    for (char c:s) {
//        m[c]={.amount=m[c].amount+1};
//    }
    string re1;
    string re2;
    int odd=0;
    for (int i=0;i<26;++i) {
        if (v[i].second==0) {continue;}
        if (v[i].second==1) {re2+=alphabet[i]; continue;}

        re1.insert((re1.length()-odd)/2,v[i].second,alphabet[i]);

        if (v[i].second%2==1) {odd+=1;}
    }
    re1.insert((re1.length()-odd)/2,re2);
    cout << re1;
}
