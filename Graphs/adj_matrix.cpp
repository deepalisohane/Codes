
Adjcenecy matrix from 2D matrix

    vector<int>adj[n];
    for(auto it:connections){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
