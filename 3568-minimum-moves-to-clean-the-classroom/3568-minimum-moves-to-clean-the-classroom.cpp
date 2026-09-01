class Solution {
public:

    struct State {
        int r;
        int c;
        int mask;
        int energy;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        // Find S and assign IDs to L
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if(classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int fullMask = (1 << litterCount) - 1;

        queue<State> q;

        q.push({sr, sc, 0, energy});

        /*
            visited[r][c][mask][energy]

            We flatten the 4D state into one vector.
        */

        int totalStates = m * n * (1 << litterCount) * (energy + 1);

        vector<bool> visited(totalStates, false);

        auto getId = [&](int r, int c, int mask, int e) {

            return (((r * n + c) * (1 << litterCount) + mask)
                    * (energy + 1) + e);
        };

        visited[getId(sr, sc, 0, energy)] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while(sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int e = cur.energy;

                // All litter collected
                if(mask == fullMask)
                    return moves;

                // Cannot move if energy is 0
                if(e == 0)
                    continue;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid ke bhar jo hai
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle jo grid me present hai..
                    if(classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = e - 1;

                    // Reset area jo grid ka baccha hua area hai
                    if(classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    // Litter
                    if(classroom[nr][nc] == 'L') {

                        int id = litterId[nr][nc];

                        newMask |= (1 << id);
                    }

                    int id = getId(nr, nc, newMask, newEnergy);

                    if(!visited[id]) {

                        visited[id] = true;

                        q.push({
                            nr,
                            nc,
                            newMask,
                            newEnergy
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};