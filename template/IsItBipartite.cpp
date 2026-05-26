#include <bits/stdc++.h>

using namespace std;

// Helper function for the DFS approach
bool checkBipartiteDFS(int u, int currentColor, vector<int>& nodeColor, const vector<vector<int>>& adjList) {
    nodeColor[u] = currentColor;
    for (int v : adjList[u]) {
        if (nodeColor[v] == -1) {
            if (!checkBipartiteDFS(v, 1 - currentColor, nodeColor, adjList)) return false;
        } else if (nodeColor[v] == nodeColor[u]) {
            return false;
        }
    }
    return true;
}
// 1. DFS Version
bool isBipartiteDFS(int n, const vector<vector<int>>& adjList) {
    vector<int> nodeColor(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (nodeColor[i] == -1) {
            if (!checkBipartiteDFS(i, 0, nodeColor, adjList)) return false;
        }
    }
    return true;
}


// 2. BFS Version
bool isBipartiteBFS(int n, const vector<vector<int>>& adjList) {
    vector<int> nodeColor(n + 1, -1); // -1: uncolored, 0: Color A, 1: Color B
    
    for (int i = 1; i <= n; ++i) {
        if (nodeColor[i] != -1) continue;
        
        queue<int> nodeQueue;
        nodeQueue.push(i);
        nodeColor[i] = 0;
        
        while (!nodeQueue.empty()) {
            int u = nodeQueue.front();
            nodeQueue.pop();
            
            for (int v : adjList[u]) {
                if (nodeColor[v] == -1) {
                    nodeColor[v] = 1 - nodeColor[u];
                    nodeQueue.push(v);
                } else if (nodeColor[v] == nodeColor[u]) {
                    return false; // Odd-length cycle detected
                }
            }
        }
    }
    return true;
}

/*
 * You can check:
 * CF: 1702E
 */
