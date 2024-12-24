#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void initialize(string a[50][50]) {
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            a[i][j] = "0";
        }
    }
}

int find(string a[50][50], const string& temp) {
    for (int i = 0; i < 50; i++) {
        if (a[i][0] == temp) {
            return i;
        }
    }
    return -1;
}

void addChild(string a[50][50], const string& child, int x) {
    int j = 1; // Start from 1 to skip the parent name
    while (a[x][j] != "0") {
        j++;
    }
    a[x][j] = child; // Add child to the parent's list
}

void addParent(string a[50][50], const string& parent, int x) {
    a[x][0] = parent; // Set the parent's name
}

int countDescendants(string a[50][50], int posOfFindParent) {
    int j = 1, count = 0;
    int i = posOfFindParent;
    while (a[i][j] != "0") {
        int childIndex = find(a, a[i][j]);
        count += 1 + countDescendants(a, childIndex); 
        j++;
    }
    return count;
}
int countGeneration(string a[50][50], int posOfFindParent) {
    int maxGenerations = -1; 
    int j = 1;
    int i = posOfFindParent;
    while (a[i][j] != "0") {
        int childIndex = find(a, a[i][j]);
        if (childIndex != -1) {
            int childGenerations = countGeneration(a, childIndex);
            maxGenerations = max(maxGenerations, childGenerations);
        }
        j++;
    }
    return maxGenerations + 1; 
}

int main() {
    string s;
    string a[50][50];
    initialize(a);
    int x = 0;

    // Read child-parent relations
    while (true) {
        getline(cin, s);
        istringstream iss(s);
        string child, parent;
        iss >> child;
        if (child == "***") break;
        iss >> parent;

        if (find(a, child) == -1 && find(a, parent) == -1) {
            addParent(a, parent, x);
            addChild(a, child, x);
            x++;
            addParent(a, child, x);
            x++;
        } else if (find(a, child) == -1 && find(a, parent) != -1) {
            addChild(a, child, find(a, parent));
            addParent(a, child, x);
            x++;
        } else if (find(a, child) != -1 && find(a, parent) != -1) {
            addChild(a, child, find(a, parent));
        }
    }

    string s1;
    while (true) {
        getline(cin, s1);
        istringstream iss(s1);
        string order, name;
        iss >> order;
        if (order == "***") break;
        else if (order == "descendants") {
            iss >> name;
            cout << countDescendants(a, find(a, name)) << endl;
        } else if (order == "generation") {
            iss >> name;
            cout << countGeneration(a, find(a, name)) << endl;
        }
    }

    return 0;
}
