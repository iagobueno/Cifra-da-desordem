#include <bits/stdc++.h>
using namespace std;
#define PL cout << "\n"

// Recursive function to implement the Josephus problem

// Driver code
int main()
{
    int n, k; cin >> n >> k;

    list<int> l;

    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }

    list<int>::iterator it = l.begin();

    while (!l.empty()) {

        for (int j = 0; j < k-1; j++) {
            it++;
            if (it == l.end()) { it = l.begin(); }
        }

        cout << *it << "\n";
        it = l.erase(it);

        if (it == l.end()){
            it = l.begin();
        }
    }

}