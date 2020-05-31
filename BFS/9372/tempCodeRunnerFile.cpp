        vector<vector<int>> v(N + 1);
        vector<bool> check(N + 1, false);
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            v[a].push_back(b);
            v[b].push_back(a);
        }