#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

bool is_number(const string& s) {
    string::const_iterator it = s.begin()+1;
    if (s[0] != '-' && !isdigit(s[0])) {return false;}
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
int get_value(map<int,int>& v, int i) {
    for (;i>=0;i--) {
        auto it = v.find(i);
        if (it != v.end()) {
            return it->second;
        }
    }
    return 0;
}

int main () {

    map<string,stack<int>> values;
    vector<vector<stack<int>*>> de;
    de.emplace_back();
    int level = 0;
    string c;
    string v1;
    string v2;
    while(getline(cin,c)) {
        if (c=="{") {
//            for (auto& it: values) {
//                if (it.second.empty()) {
//                    it.second.push(0);
//                }
//                it.second.push(it.second.top());
//            }
            de.emplace_back();
            level++;
            continue;
        }
        if (c=="}") {
            for (auto it: de[level]) {
                (*it).pop();
            }
            de.pop_back();
            level--;
            continue;
        }
        size_t p = c.find('=');
        if (p==string::npos) {continue;}
        v1 = c.substr(0,p);
        v2 = c.substr(p+1,c.length());
        if (is_number(v2)) {
            values[v1].push(stoi(v2));
            de[level].push_back(&(values[v1]));
        } else {
            if (values[v2].empty()) {
                values[v2].push(0);
//                cout << 0 << '\n';
//                continue;
            }
            if (v1==v2) {
                cout << values[v1].top() << '\n';
            } else {
                int temp = values[v2].top();
                cout << temp << '\n';
                values[v1].push(temp);
                de[level].push_back(&(values[v1]));
            }
        }
    }

//    map<string,map<int,int>> values;
//    int level = 0;
//    string c;
//    string v1;
//    string v2;
//    while(getline(cin,c)) {
//        if (c=="{") {
//            level++;
//            continue;
//        }
//        if (c=="}") {
//            for (auto& it: values) {
//                auto i = it.second.find (level);
//                if (i!=it.second.end()) {
//                    it.second.erase(i);
//                }
//            }
//            level--;
//            continue;
//        }
//        size_t p = c.find('=');
//        if (p==string::npos) {continue;}
//        v1 = c.substr(0,p);
//        v2 = c.substr(p+1,c.length());
//        if (is_number(v2)) {
//            values[v1][level]=stoi(v2);
//        } else {
//            int temp = get_value(values[v2],level);
//            cout << temp << '\n';
//            values[v1][level]=temp;
//        }
//    }

//    vector<map<string,int>> values;
//    values.emplace_back();
//    int level = 0;
//    string c;
//    string v1;
//    string v2;
//    while(getline(cin,c)) {
//        if (c=="{") {
//            if (values.size()>level+1) {
//                for (auto& it: values[level]) {
//                    values[level+1][it.first]=it.second;
//                }
//            } else {values.push_back(values[level]);}
//            level++;
//            continue;
//        }
//        if (c=="}") {
//
//            if(values[level].size() > 0)
//            {
//                for(auto it=values[level].begin() ; it!=values[level].end() ; it++)
//                {
//                    delete it->second;
//                }
//                values[level].clear();
//            }
//            level--;
//            continue;
//        }
//        size_t p = c.find('=');
//        if (p==string::npos) {continue;}
//        v1 = c.substr(0,p);
//        v2 = c.substr(p+1,c.length());
//        if (is_number(v2)) {
//            values[level][v1]=stoi(v2);
//        } else {
//            int temp = values[level][v2];
//            cout << temp << '\n';
//            values[level][v1]=temp;
//        }
//    }
}