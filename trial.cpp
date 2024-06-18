// C++ program to solve fractional Knapsack Problem

#include <bits/stdc++.h>
#include <iostream>
#include <list>

using namespace std;

#define size1 15

vector<int> item_selected;

// Structure for an item which stores weight and
// corresponding value of Item
class User{

	public:
		string name ;
		float age;
		float weight;
		float height;
		float bmi;
		char gender;



		User(string name,
		float age,
		float weight,
		float height,
		char gender){
			this-> name = name;
			this-> age = age;
			this-> weight = weight;
			this-> height = height;
			this-> gender = gender;
			bmi = weight / (height*height);
				}


};
class Item {
	public:
	float protein,carbs, calories;
    string name;
	int item_number;

	// Constructor
	Item(float protein, float carbs,float calories, string name, int item_number)
	{
		this->protein = protein;
		this->carbs = carbs;
		this->calories = calories;
		this->name = name;
		this->item_number = item_number;
	}
};

// Comparison function to sort Item
// according to profit/weight ratio
static bool cmp_P(class Item &a, class Item &b)
{
	double r1 = (double)a.protein / (double)a.calories;
	double r2 = (double)b.protein / (double)b.calories;
	return r1 > r2;
}

static bool cmp_C(class Item &a, class Item &b)
{
	double r1 = (double)a.carbs / (double)a.calories;
	double r2 = (double)b.carbs / (double)b.calories;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack_P(int W, class Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp_P);

	double finalvalue = 0.0;

	// Looping through all items
	cout<<"Items to be consumed : "<<endl;
	for (int i = 0; i < N; i++) {

		// If adding Item won't overflow,
		// add it completely
		if (arr[i].calories <= W) {
			W -= arr[i].calories;
			finalvalue += arr[i].protein;
			item_selected.push_back(arr[i].item_number) ;

			cout<<arr[i].name<<": 100 gm"<<endl;
		}

		// If we can't add current Item,
		// add fractional part of it

		else {
			double x =  arr[i].protein
				* ((double)W / (double)arr[i].calories);
			finalvalue
				+= x;
			item_selected.push_back(arr[i].item_number) ;

			cout<<arr[i].name<<" : "<<x<<"gm"<<endl;
			break;
		}
	}

	// Returning final value
	cout<<endl;
	return finalvalue;
}



double fractionalKnapsack_C(int W, class Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp_C);

	double finalvalue = 0.0;

	// Looping through all items
	cout<<"Items to be consumed : "<<endl;
	for (int i = 0; i < N; i++) {

		// If adding Item won't overflow,
		// add it completely
		if (arr[i].calories <= W) {
			W -= arr[i].calories;
			finalvalue += arr[i].carbs;
			item_selected.push_back(arr[i].item_number) ;
			cout<<arr[i].name<<": 100 gm"<<endl;
		}

		// If we can't add current Item,
		// add fractional part of it

		else {
			double x =  arr[i].carbs
				* ((double)W / (double)arr[i].calories);
			finalvalue
				+= x;
			item_selected.push_back(arr[i].item_number) ;

			cout<<arr[i].name<<" : "<<x<<"gm"<<endl;
			break;
		}
	}

	// Returning final value
	cout<<endl;
	return finalvalue;
}


//  Graph coloring ki starmting

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
public:
	// Constructor and destructor
	Graph(int V) { this->V = V; adj = new list<int>[V]; }
	~Graph()	 { delete [] adj; }

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Prints greedy coloring of the vertices
	void greedyColoring(Item arr[]);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring(Item arr[])
{
	int result[V];

	// Assign the first color to first vertex
	result[0] = 0;

	// Initialize remaining V-1 vertices as unassigned
	for (int u = 1; u < V; u++)
		result[u] = -1; // no color is assigned to u

	// A temporary array to store the available colors. True
	// value of available[cr] would mean that the color cr is
	// assigned to one of its adjacent vertices
	bool available[V];
	for (int cr = 0; cr < V; cr++)
		available[cr] = false;

	// Assign colors to remaining V-1 vertices
	for (int u = 1; u < V; u++)
	{
		// Process all adjacent vertices and flag their colors
		// as unavailable
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = true;

		// Find the first available color
		int cr;
		for (cr = 0; cr < V; cr++)
			if (available[cr] == false)
				break;

		result[u] = cr; // Assign the found color

		// Reset the values back to false for the next iteration
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[*i] != -1)
				available[result[*i]] = false;
	}

	// print the result
	// for (int u = 0; u < V; u++)

	// 	cout << "Vertex " << u << " ---> Color "
	// 		<< result[u] << endl;

	cout<<"Items to be not consumed together : "<<endl;

	for (int  i = 0; i < item_selected.size()-1; i++)
	{
		int temp_color1 = result[item_selected[i]];
		for (int j = i+1; j <item_selected.size(); j++)
		{
			int temp_color2 = result[item_selected[j]];
			if (temp_color1=!temp_color2)
			{
				cout<<"("<<arr[item_selected[i]].name<<","<<arr[item_selected[j]].name<<")"<<endl;
			}

		}

	}


}

void final_edge_set(Graph &g1){
    g1.addEdge(0, 4);
    g1.addEdge(0, 7);
    g1.addEdge(0, 8);
    g1.addEdge(1, 6);
    g1.addEdge(1,7 );
    g1.addEdge(1, 8);
    g1.addEdge(1, 10);
    g1.addEdge(1, 12);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 13);
    g1.addEdge(3,5 );
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(3, 8);
    g1.addEdge(4, 6);
    g1.addEdge(4, 8);
    g1.addEdge(4, 13);
    g1.addEdge(4, 14);
    g1.addEdge(10, 7);
    g1.addEdge(10, 8);
    g1.addEdge(10, 14);
    g1.addEdge(11, 13);
    g1.addEdge(12, 14);




}

void calculate_sugar(float sugar)
{
	if(sugar<70)
	{
		cout<<"Your sugar is low!"<<endl<<endl;
		cout<<"It is adviced that you should incorporate such meals in your diet:";
		cout<<"1. Sugarcane-juice"<<endl;
		cout<<"2. Dry fruits"<<endl;
		cout<<"3. fruit-juice"<<endl;
		cout<<"4. Candy"<<endl;
		cout<<"5. Honey"<<endl;
	}
	else if(sugar>126)
	{
		cout<<"Your sugar is high! You are diabetic."<<endl<<endl;
		cout<<"It is adviced that you should incorporate such meals in your diet:";
		cout<<"1. Whole-wheat bread"<<endl;
		cout<<"2. Garlic"<<endl;
		cout<<"3. Fatty-fish"<<endl;
		cout<<"4. Leafy-Green vegetables"<<endl;
		cout<<"5. Blackberry"<<endl;
		cout<<"Some light excercises and yoga is highly recommended."<<endl<<endl;
	}
	else
	{
		cout<<"Your sugar is normal."<<endl;
		cout<<"No precautions needed. Just maintain a healthy balanced diet."<<endl<<endl;
	}
}

void calculate_chol(float chol)
{
	if(chol>240)
	{
		cout<<"Your cholestrol-level is high!"<<endl<<endl;
		cout<<"It is adviced that you should avoid eating:"<<endl;
		cout<<"1. Deep-fried"<<endl;
		cout<<"2. Junk food"<<endl;
		cout<<"3. Processed food"<<endl;
		cout<<"4. Full-cream milk"<<endl;
		cout<<"5. Alcohol consumption or Smoking"<<endl<<endl;
		cout<<"It is adviced that you should eat such meals in your diet:"<<endl;
		cout<<"1. Whole-grains"<<endl;
		cout<<"2. Beans"<<endl;
		cout<<"3. Olive-oil"<<endl;
		cout<<"4. Dark-chocolate"<<endl;
		cout<<"5. Citrus-fruits"<<endl;
		cout<<"Some light excercises and yoga is highly recommended."<<endl<<endl;
	}
	else
	{
		cout<<"Your cholestrol is normal."<<endl;
	    cout<<"No precautions needed. Just maintain a healthy balanced diet."<<endl<<endl;
	}
}

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


// Driver code
int main()
{
	string name;
	float age;
	float weight;
	float height;
	float bmi;
	string goal;
	char gender;
	int option;

	cout<<"**************************************************************"<<endl;
	cout<<"*                       *************                        *"<<endl;
	cout<<"*                        ***********                         *"<<endl;
	cout<<"*                         *********                          *"<<endl;
	cout<<"*                          *******                           *"<<endl;
	cout<<"*                           *****                            *"<<endl;
	cout<<"*                            ***                             *"<<endl;
	cout<<"*                             *                              *"<<endl;
	cout<<"***************** WELCOME  TO  FIT - WIT *********************"<<endl;
	cout<<"*                             *                              *"<<endl;
	cout<<"*                            ***                             *"<<endl;
	cout<<"*                           *****                            *"<<endl;
	cout<<"*                          *******                           *"<<endl;
	cout<<"*                         *********                          *"<<endl;
	cout<<"*                        ***********                         *"<<endl;
	cout<<"*                       *************                        *"<<endl;
	cout<<"**************************************************************"<<endl;

	cout<<"Enter your name : "<<endl;
	cin>>name;

	cout<<"Enter your age (in years): "<<endl;
	cin>>age;

	cout<<"Enter your weight (in kgs) : "<<endl;
	cin>>weight;

	cout<<"Enter your height (in meters) : "<<endl;
	cin>>height;

	cout<<"Enter your gender : "<<endl;
	cin>>gender;

	User user1(name, age, weight, height, gender);
	float cal_intake;

	if (gender =='m'||gender=='M')
	{
		cal_intake = 66 + (13.7* user1.weight) + (5*  user1.height*100) - (6.8 * user1.age);
	}
	else if(gender =='f'||gender=='F')
	{
		cal_intake = 655 + (9.6* user1.weight) + (1.8*  user1.height*100) - (4.7 * user1.age);

	}
	else
	{
		cout<<"Please enter a valid gender!!!"<<endl;
		exit(0);
	}



	Item arr[] = { { 52,33 ,345,"Soya Chunk",0 }, { 3.4,4.8,61,"Milk",1 }, { 2.7,28,130,"Rice",2 },{ 10.9,70.7,381,"Oats",3 },{ 1.1,23,81,"Banana",4 },{ 10.62,0.69,153,"Omlette",5 }, { 9.02,20.13,130,"Pulses",6 },{ 27,0,165,"Chicken",7 },{ 22,0,84,"Fish",8 },{ 2.5,21,93,"Potato",9 },{ 10,1.2,83,"Tofu",10 }, { 3.1,46,300,"Roti",11 }, { 11.75,3.45,100,"Curd",12 },{ 10.5,50.4,272,"Multi-grain Bread",13 },{ 20,4.5,296,"Paneer",14 }};
	int N = sizeof(arr) / sizeof(arr[0]);

	cout<<"Choose your goal : "<<endl;
	cout<<"1. Gain lean muscle mass"<<endl;
	cout<<"2. Gain weight "<<endl;
	cin>> option ;
	cout<< "Your calorie intake per day should be : "<<cal_intake<<endl;
	switch (option)
	{
	case 1:
		cout <<"Protein obtained : "<< fractionalKnapsack_P(cal_intake, arr, N)<<endl<<endl;
		break;

	case 2 :
		cout <<"Carbs obtained : "<< fractionalKnapsack_C(cal_intake, arr, N)<<endl<<endl;
		break;
	}

// for (int  i = 0; i < item_selected.size(); i++)
// {
// 	cout<<item_selected[i]<<"  ";
// }

	Graph g1(size1);
    final_edge_set(g1);


	// cout << "Coloring of graph 1 \n";
	g1.greedyColoring( arr);

	//-------------------------------------------------------------------------------------------------------
	cout<<"Enter further information for further advice:";
	float sugar,chol;
	cout<<"Enter your sugar-level(mg/dl):"<<endl;
	cin>>sugar;
	cout<<"Enter your cholestrol-level(mg/dl):"<<endl;
	cin>>chol;
	calculate_sugar(sugar);
	calculate_chol(chol);

int V;
    cout<<"Enter the number of places to be visitied in a day : "<<endl;
    cin>>V;

	int **graph=new int*[V];
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
    }
    for (int  i = 0; i < V; i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"Enter the distance between"<<i+1<<"th and"<<j+1<<"th place in meter"<<endl;
            cin>>graph[i][j];
        }
    }

	int s = 0;
	float distance_travelled = travllingSalesmanProblem(graph, s,V);
	cout <<" distance travelled :"<< distance_travelled << endl;
	float calories_burnt = distance_travelled * 0.0621;
	cout<<"You burnt "<<calories_burnt<<"calories in your walk today!!!"<<endl;

	return 0;
}
