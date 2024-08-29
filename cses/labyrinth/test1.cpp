#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            cin >> map[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; i++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    pair<int, int> startMaze(-1, -1);
    pair<int, int> endMaze(-1, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (startMaze.second < 0 || endMaze.second < 0)
            {
                char currChar = map[i][j];

                if (currChar == 'A')
                {
                    startMaze.first = i;
                    startMaze.second = j;
                }
                if (currChar == 'B')
                {
                    endMaze.first = i;
                    endMaze.second = j;
                }
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> evaluated;
    vector<vector<int>> distances;
    int distToEnd;

    q.push(startMaze);
    evaluated[startMaze.first][startMaze.second] = true;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int uColumn = -1;
            int uLine = -1;

            if (i == 0 && v.second <= m)
            {
                uColumn = v.first;
                uLine = v.second + 1;
            }

            if (i == 1 && v.first <= n)
            {
                uColumn = v.first + 1;
                uLine = v.second;
            }

            if (i == 2 && v.first >= 0)
            {
                uColumn = v.first - 1;
                uLine = v.second;
            }

            if (i == 0 && v.second >= 0)
            {
                uColumn = v.first;
                uLine = v.second - 1;
            }

            if ((uColumn != -1 && uLine != -1) && !evaluated[uColumn][uLine])
            {
                if (map[uColumn][uLine] == 'B')
                {
                    evaluated[uColumn][uLine] == true;
                }

                if (map[uColumn][uLine] == '#')
                {
                    evaluated[uColumn][uLine] == true;
                }

                if (map[uColumn][uLine] == '.')
                {
                    evaluated[uColumn][uLine] == true;
                    q.emplace(uColumn, uLine);
                    distances[uColumn][uLine] = distances[v.first][v.second];
                }
            }
        }
    }

    cout << "" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC)
    {
        cin >> TC;
        while (TC--)
        {
            solve();
        }
    }
    else
    {
        solve();
    }

    return 0;
}