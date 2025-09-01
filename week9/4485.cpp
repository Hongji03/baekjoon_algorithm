#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,pair<int,int>> edge;
const int INF = INT_MAX / 2;

int N;
int rupee[126][126];
int mcost[126][126];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                cin >> rupee[r][c];
                mcost[r][c] = INF;
            }
        }

        priority_queue<edge, vector<edge>, greater<edge>> pq;
        mcost[0][0] = rupee[0][0];
        pq.push({mcost[0][0], {0,0}});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (cost > mcost[r][c]) {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                    continue;
                }

                int ncost = cost + rupee[nr][nc];
                if (mcost[nr][nc] > ncost) {
                    mcost[nr][nc] = ncost;
                    pq.push({ncost, {nr, nc}});
                }
            }
        }

        cout << "Problem " << T++ << ": " << mcost[N-1][N-1] << '\n';
    }

    return 0;
}