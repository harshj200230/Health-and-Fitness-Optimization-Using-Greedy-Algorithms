// CPP program to implement traveling salesman
// problem using naive approach.
#include <bits/stdc++.h>
using namespace std;


// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int **graph, int s,int V)
{
	// store all vertex apart from source vertex
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {

		// store current Path weight(cost)
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		// update minimum
		min_path = min(min_path, current_pathweight);

	} while (
		next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

// Driver Code
int main()
{
	// matrix representation of graph
    int V;
    cout<<"Enter the number of places to be visitied in a day : "<<endl;
    cin>>V;

	int *graph=new int[V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
    }
    for (int  i = 0; i < V; i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"Enter the distance between"<<i+1<<"th and"<<j+1<<"th place"<<endl;
            cin>>graph[i][j];
        }
    }

	int s = 0;
	cout <<"Minimum path that you can walk in a day is:"<< travllingSalesmanProblem(graph, s,V) << endl;
	return 0;
}