#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  vi seen(1e6);
  int N; cin >> N;
  int onTable, best;
  onTable = best = 0;
  for (int i=0;i<2*N;i++) {
    int ai; cin >> ai;
    if (!seen[ai]) {
      onTable++;
      best = max(best, onTable);
    } else {
      onTable--;
    }
    seen[ai]++;
  }

  cout << best << endl;
  return 0;
}
