// Frankenstein Code Solution in C++
// SUBSCRIBE OUR CHANNEL "EDUTECH BARSHA"

#include <bits/stdc++.h>
using namespace std;

// Global variables for the recipe book and memoization
map<string, vector<vector<string>>> recipeBook;
map<string, int> memo;

int minOrbsToBrew(string potion);

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        size_t eqPos = line.find('=');
        string potion = line.substr(0, eqPos);
        string ingredients = line.substr(eqPos + 1);

        vector<string> parts;
        stringstream ss(ingredients);
        string item;
        while (getline(ss, item, '+')) {
            parts.push_back(item);
        }
        recipeBook[potion].push_back(parts);
    }

    string targetPotion;
    getline(cin, targetPotion);

    int result = minOrbsToBrew(targetPotion);
    cout << result << endl;

    return 0;
}

int minOrbsToBrew(string potion) {
    if (recipeBook.find(potion) == recipeBook.end()) {
        return 0;
    }

    if (memo.find(potion) != memo.end()) {
        return memo[potion];
    }

    int subscribe = INT_MAX;
    for (const auto &recipe : recipeBook[potion]) {
        int orbsRequired = recipe.size() - 1;
        for (const auto &ingredient : recipe) {
            orbsRequired += minOrbsToBrew(ingredient);
        }
        subscribe = min(subscribe, orbsRequired);
    }

    memo[potion] = subscribe;
    return subscribe;
}
