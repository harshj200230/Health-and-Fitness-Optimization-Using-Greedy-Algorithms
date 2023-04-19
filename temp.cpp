#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int color, const vector<vector<int>>& graph, const vector<int>& colors) {
    for (int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];
        if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

bool graphColoringHelper(int node, int numNodes, int numColors, vector<vector<int>>& graph, vector<int>& colors) {
    if (node == numNodes) {
        return true;
    }

    for (int color = 1; color <= numColors; color++) {
        if (isSafe(node, color, graph, colors)) {
            colors[node] = color;
            if (graphColoringHelper(node+1, numNodes, numColors, graph, colors)) {
                return true;
            }
            colors[node] = 0; // backtrack
        }
    }

    return false;
}

bool graphColoring(int numNodes, int numColors, vector<vector<int>>& graph, vector<int>& colors) {
    return graphColoringHelper(0, numNodes, numColors, graph, colors);
}

int main() {
    int numNodes = 5;
    int numColors = 3;
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3, 4},
        {1, 2, 4},
        {2, 3}
    };
    vector<int> colors(numNodes, 0);
    if (graphColoring(numNodes, numColors, graph, colors)) {
        cout << "Graph is colored with " << numColors << " colors:" << endl;
        for (int i = 0; i < numNodes; i++) {
            cout << "Node " << i << " is colored with " << colors[i] << endl;
        }
    } else {
        cout << "Graph cannot be colored with " << numColors << " colors." << endl;
    }
    return 0;
}