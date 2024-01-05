// TITLE 이전 순열 #10973

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> curr(n);

    for (int i = 0; i < n; i++)
        cin >> curr[i];
    
    int key;
    bool flag = false;
    vector<int> v;
    v.push_back(curr[n-1]);
    for (int i = n-1; i > 0; i--) {
        v.push_back(curr[i-1]);
        if (curr[i-1] > curr[i]) {
            key = i-1;
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << -1 << endl;
        return 0;
    }

    sort(v.begin(), v.end(), greater<int>());

    vector<int> prev(curr.begin(), curr.begin() + key);
    prev.resize(n);

    int tmp = 1;
    prev[key+1] = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i-1] == curr[key]) {
            prev[key] = v[i];
            prev[key+tmp+i] = v[i+1];
            i++;
            tmp = 0;
        }
        prev[key+tmp+i] = v[i];
    }

    for (int i : prev)
        cout << i << " ";
    cout << endl;


    return 0;
}