// TITLE 다음 순열 #10972

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    bool flag = false;
    vector<int> v;
    v.push_back(arr[n-1]);
    for (int i = n-1; i > 0; i--) {
        v.push_back(arr[i-1]);
        if (arr[i] > arr[i-1]) {
            key = i-1;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return 0;
    }
    sort(v.begin(), v.end());

    vector<int> next(n);

    for (int i = 0; i < key; i++)
        next[i] = arr[i];
    
    int tmp = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == arr[key]) {
            next[key+1+i] = v[i];
            next[key] = v[i+1];
            i++;
            tmp = -1;
            continue;
        }
        next[key+1+i+tmp] = v[i];
    }

    for (int i : next)
        cout << i << " ";
    cout << endl;

    return 0;
}