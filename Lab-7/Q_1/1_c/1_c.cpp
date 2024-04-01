#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
pair<int, vector<int>> knapSack(long long W, long long wt[], long long val[], long long n)
{
    long long i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    vector<int> includedItems;
    int j = W;
    for (i = n; i > 0 && j > 0; i--) {
        if (K[i][j] != K[i - 1][j]) {
            includedItems.push_back(i - 1);
            j -= wt[i - 1];
        }
    }

    return {K[n][W], includedItems};
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long w[n], v[n];

    long long max_weight;
    cin >> max_weight;

    for (long long i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto result = knapSack(max_weight, w, v, n);
    cout << "Maximum value: " << result.first << endl;
    cout << "Included items: ";
    for (int item : result.second) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
