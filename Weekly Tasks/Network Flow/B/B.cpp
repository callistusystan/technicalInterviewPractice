#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef pair<ll, int> lli;
typedef vector<lli> vlli;

int SOURCE = 0;
int SINK = 1;

template < typename T> struct Dinics {
struct edge { int to; T flow , cap ; }; T INF = numeric_limits <T >:: max ();
int n, m; vi dist , work ; queue <int > q; vector <edge > edges ; vvi adj ;
bool bfs ( int s, int t) {
dist . assign (n, -1); dist [s] = 0; q. push (s);
while (!q. empty ()) {
int u = q. front (); q. pop ();
for ( auto & i : adj[u]) {
edge & e = edges [i]; int v = e.to;
if ( dist [v] < 0 && e. flow < e. cap) dist [v] = dist [u] + 1, q. push (v);
}
}
return dist [t] >= 0;
}T
dfs( int u, int t, T f) {
if (u == t) return f;
for (int& i = work [u]; i < ( int ) adj [u]. size (); i ++) {
auto & e = edges [ adj [u][i]], & rev = edges [ adj [u][i ]^1];
if (e. flow < e. cap && dist [e.to] == dist [u] + 1) {
T df = dfs (e.to , t, min(f, e.cap - e. flow ));
if (df > 0) { e. flow += df; rev . flow -= df; return df; }
}
}
return 0;
}
// Create a flow network with n nodes -- add edges with add_edge (u,v, cap )
Dinics ( int n) : n(n), m (0) , adj (n) { }
int add_edge ( int from , int to , T cap ) { // add an edge ( from -> to) with
adj [ from ]. push_back (m++) , adj [to ]. push_back (m ++) ; // capacity of cap units .
edges . push_back ({to , 0, cap }) , edges . push_back ({ from , 0, 0}) ;
return m - 2; // Change {from ,0 ,0} to {from ,0, cap } for bidirectional edges
}
edge & get_edge ( int i) { return edges [i]; } // get a reference to the i’th edge
T max_flow ( int s, int t) { // find the maximum flow from s to t
T res = 0; for ( auto & e : edges ) e. flow = 0;
while ( work . assign (n, 0) , bfs (s, t))
while (T delta = dfs (s, t, INF )) res += delta ;
return res;
}
};

void solve() {
  int N, M;
  cin >> N >> M;
  vi a(N),b(N);
  for (int i=0;i<N;i++) cin >> a[i];
  for (int i=0;i<N;i++) cin >> b[i];

  Dinics<long long> d(2*N+2);
  for (int i=0;i<N;i++) {
    d.add_edge(SOURCE, i+2, a[i]);
    d.add_edge(i+2+N, SINK, b[i]);
    d.add_edge(i+2, i+2+N, LLONG_MAX);
  }
  for (int i=0;i<M;i++) {
    int u,v; cin >> u >> v;
    u--; v--;
    d.add_edge(u+2,v+2+N,LLONG_MAX);
    d.add_edge(v+2,u+2+N,LLONG_MAX);
  }

  int sA, sB; sA = sB = 0;
  for (int i=0;i<N;i++) {
    sA += a[i];
    sB += b[i];
  }

  if (sA != sB) {
    cout << "NO" << endl;
  } else {
    if (d.max_flow(SOURCE, SINK) == sA) {
      cout << "YES" << endl;

      vvi ans(N, vi(N, 0));
      for (int i=0;i<N;i++) {
        for (int edgeI : d.adj[i+2]) {
          int to, flow;
          to = d.get_edge(edgeI).to - 2 - N;
          flow = d.get_edge(edgeI).flow;
          if (to >= 0 && to < N) {
              ans[i][to] = flow;
          }
        }
      }

      for (vi v : ans) {
        for (int i=0;i<N;i++) {
          cout << v[i] << " \n"[i==N-1];
        }
      }
    } else {
      cout << "NO" << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}
