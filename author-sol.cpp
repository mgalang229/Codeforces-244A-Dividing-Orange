#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // input
    int n, k;
    cin >> n >> k;
    set<int> s;
    // store the segments in a set (because searching in a set is log(N))
    int a[k];
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    // create a sequence from 1 to n(k) (inclusive)
    int len = n * k;
    int arr[len] = {0};
    iota(arr, arr + len, 1);
    // store segments of length n together with the segment that each child wants
    // note: don't forget to mark the segments that are already stored (to avoid overlap)
    vector<int> adj[k];
    bool visited[len] = {false};
    for (int i = 0; i < k; i++) {
        adj[i].push_back(a[i]);
        int temp = n - 1;
        for (int j = 0; j < len; j++) {
            if (!visited[j] && temp > 0 && s.find(arr[j]) == s.end()) {
                adj[i].push_back(arr[j]);
                visited[j] = true;
                temp--;
            }
        }
    }
    // output
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (int) adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
