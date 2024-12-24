 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int dia;
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<vector<int>> graph1(n1);
        vector<vector<int>> graph2(n2);

        for (auto& edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        dia = -1;
        vector<bool> visited1(n1, false);
        getDia(0, graph1, visited1);
        int d1 = dia;

        dia = -1;
        vector<bool> visited2(n2, false);
        getDia(0, graph2, visited2);
        int d2 = dia;

        int cand = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
        return max(cand, max(d1, d2));
    }

    int getDia(int src, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[src] = true;
        int dch = -1, sdch = -1;

        for (int child : graph[src]) {
            if (!visited[child]) {
                int ch = getDia(child, graph, visited);
                if (ch > dch) {
                    sdch = dch;
                    dch = ch;
                } else if (ch > sdch) {
                    sdch = ch;
                }
            }
        }

        if (dch + sdch + 2 > dia) dia = dch + sdch + 2;
        return dch + 1;
    }
};