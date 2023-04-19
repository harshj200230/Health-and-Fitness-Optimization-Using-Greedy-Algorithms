#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to store information about a food item
struct Food {
    string name;
    string type;
    int calories;
    // Add any other relevant information here
};

int main() {
    // Create a vector to store a list of food items
    vector<Food> foodList;

    // Populate the foodList vector with some sample food items
    foodList.push_back({"apple", "fruit", 95});
    foodList.push_back({"chicken breast", "protein", 165});
    foodList.push_back({"broccoli", "vegetable", 55});

    // Prompt the user to enter a time interval
    cout << "Enter a time interval (in hours) for which you want to find food: ";
    int timeInterval;
    cin >> timeInterval;

    // Loop through the foodList vector and print out any items that fit within the time interval
    for (const auto& food : foodList) {
        if (food.calories <= timeInterval * 100) {
            cout << "You can eat " << food.name << " (" << food.type << ") within the next " << timeInterval << " hours.\n";
        }
    }

    return 0;
}