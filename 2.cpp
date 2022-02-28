#include <iostream>
#include <stack>

using namespace std;

//bruh
int main () {
    string s;
    cin >> s;
    int n = s.length();
    if (n%2==1||n>100000) {
        cout << "Impossible";
        return 0;
    }
    size_t order[n/2];
    size_t level[n/2+1];
    fill(level, level+n/2+1, 0);
    size_t cur_level=0;
    size_t a_s=0;
    size_t c_s=0;
    stack<char> stack;
    for (string::size_type i = 0; i < s.size(); i++) {
        if (islower(s[i])) {a_s++;} else {c_s++;}
        if (!stack.empty() && ((isupper(stack.top())&&islower(s[i])&&tolower(stack.top())==s[i])||(islower(stack.top())&&isupper(s[i])&&stack.top()==tolower(s[i])))) {
            stack.pop();
            if (islower(s[i])) {
                order[c_s-level[cur_level]-1]=a_s;
            } else {
                order[c_s-1]=a_s-level[cur_level];
            }
            cur_level--;
            level[cur_level]+=level[cur_level+1];
            level[cur_level+1]=0;
            continue;
        }

        level[cur_level]++;
        cur_level++;
        stack.push(s[i]);
    }
    if (!stack.empty()) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    for (size_t i: order) {
        cout << i << " ";
    }
}