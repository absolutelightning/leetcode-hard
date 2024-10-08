//
// Created by Ashesh Vidyut on 10/06/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <climits>
#include <algorithm>
#include <utility>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <cmath>

#define ll long long int

using namespace std;

vector<int> graph[5];
vector<vector<int> > grp;

class Person {
public:
    string name;
    int age;
};

struct PersonCmp {
    bool operator()(const Person * a, const Person * b) const {
        if (a->age == b->age) {
            return a->name < b->name;
        }
        return a->age < b->age;
    }
};

struct PersonCmpLesserAge {
    bool operator()(const Person * a, const Person * b) const {
        return a->age > b->age;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto p1 = new Person();
    p1->name = "ashesh";
    p1->age = 1;
    auto p2 = new Person();
    p2->name = "ashesh";
    p2->age = 3;
    auto p3 = new Person();
    p3->name = "ashesh";
    p3->age = 3;
    auto p4 = new Person();
    p4->name = "ashesh";
    p4->age = 3;
    set<Person *> s_without;
    auto m = 7;
    s_without.insert(p4);
    s_without.insert(p3);
    s_without.insert(p2);
    s_without.insert(p1);
    cout << "size of set without comparator " << s_without.size() << endl;
    set<Person *, PersonCmp> s;
    s.insert(p4);
    s.insert(p3);
    s.insert(p2);
    s.insert(p1);
    cout << "size of set with comparator " << s.size() << endl;
    cout << "elements of set " << endl;
    for (auto it: s) {
        cout << it->name << " " << it->age  << endl;
    }
    vector<Person *> vec;
    vec.push_back(p4);
    vec.push_back(p3);
    vec.push_back(p2);
    vec.push_back(p1);
    cout << "size of vector ";
    cout << vec.size() << endl;
    cout << "elements of vector " << endl;
    sort(vec.begin(), vec.end(), PersonCmp());
    for (auto it : vec) {
        cout << it->name << " " << it->age  << endl;
    }
    cout << "elements of map " << endl;
    map<Person *, int, PersonCmp> mp;
    for (auto it: vec) {
        mp[it] = it->age;
    }
    cout << mp.size() << endl;
    for (auto it : mp) {
        cout << it.first->name << " " << it.second << endl;
    }
    priority_queue<Person *, vector<Person *>, PersonCmpLesserAge> pq;
    pq.push(p4); pq.push(p1); pq.push(p2); pq.push(p3);
    cout << "size of queue " << endl;
    cout << pq.size() << endl;
    cout << "elements of priority queue " << endl;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        cout << it->name << " " << it->age << endl;
    }
    auto it = mp.lower_bound(p1);
    if (it != mp.end()) {
        cout << "found p1" << endl;
    }
    auto p5 = new Person();
    p5->name = "batman";
    p5->age = 100;
    it = mp.lower_bound(p5);
    if (it == mp.end()) {
        cout << "not found p5" << endl;
    }
    mp[p5] = p5->age;
    it = mp.lower_bound(p5);
    if (it != mp.end()) {
        cout << "found p5" << endl;
    }
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[2].push_back(0);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[3].push_back(1);
    graph[2].push_back(4);
    graph[4].push_back(2);
    cout << "graph" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "ad of node " << i << endl;
        for (auto ad : graph[i]) {
            cout << ad << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 5; ++i) {
        vector<int> vec(5, 0);
        grp.push_back(vec);
    }
    grp[0][0] = 1;
    grp[0][1] = 2;
    grp[2][0] = 0;
    grp[1][0] = 0;
    grp[1][1] = 3;
    grp[3][0] = 1;
    grp[2][0] = 4;
    grp[4][0] = 2;
    cout << "grp" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "ad of node " << i << endl;
        for (auto ad : graph[i]) {
            cout << ad << " ";
        }
        cout << endl;
    }
    deque<int> dq;
    dq.push_back(12);
    cout << dq.front() << endl;
    return 0;
}