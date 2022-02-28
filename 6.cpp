#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    vector<string> vector;
    string s;
    while(cin >> s) {
        //if (s=="a") break;
        vector.push_back(s);
    }
    for(int i=vector.size()-1;i>=0;i--) {
        for(int j = 0; j < i; j++) {
            if (vector[j+1]+vector[j] > vector[j]+vector[j+1]) {
                swap(vector[j],vector[j+1]);
            }
        }
    }
    for (auto & i:vector) {cout << i;}
}

////return true if a > b
//bool compare(const string& a, const string& b) {
//    //cout << a.size() << " " << b.size() << "\n";
//    if (stoi(a)==0) return false;
//    if (stoi(b)==0) return true;
//    if (a.size()>b.size()) {
//        for (int i=0;i<b.size();i++) {
//            if (a[i]==b[i]) continue;
//            return a[i]>b[i];
//        }
//        return false;
//    } else {
//        for (int i=0;i<a.size();i++) {
//            if (a[i]==b[i]) continue;
//            return a[i]>b[i];
//        }
//        return true;
//    }
//}
//int main() {
//    vector<string> vector;
//    string s;
//    string test1("2");
//    string test2("004");
//    cout << (test1.compare(test2));
//    while (cin >> s)  {
//        vector.push_back(s);
//    }
//    sort(vector.begin(),vector.end(),compare);
//    for (const auto& i: vector) {
//        cout << i;
//    }
//}
