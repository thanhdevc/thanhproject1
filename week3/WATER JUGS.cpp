#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <numeric>

using namespace std;

int min_steps_to_measure(int a, int b, int c) {
    // If c is greater than both jugs, it's impossible
    if (c > max(a, b)) {
        return -1;
    }

    // If c is not a multiple of gcd(a, b), it's impossible
    if (c % gcd(a, b) != 0) {
        return -1;
    }

    // BFS queue
    queue<tuple<int, int, int>> q; // (amount in jug a, amount in jug b, steps)
    set<pair<int, int>> visited; // To track visited states
    
    // Start with both jugs empty
    q.push(make_tuple(0, 0, 0)); // (0, 0, 0)
    
    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        // Check if we've reached the goal
        if (x == c || y == c) {
            return steps;
        }

        // Possible next states using arrays
        tuple<int, int> next_states[6] = {
            {a, y},    // Fill jug a
            {x, b},    // Fill jug b
            {0, y},    // Empty jug a
            {x, 0},    // Empty jug b
            {max(0, x - (b - y)), min(b, y + x)},  // Pour from a to b
            {min(a, x + y), max(0, y - (a - x))}   // Pour from b to a
        };

        for (int i = 0; i < 6; ++i) {
            int new_x = get<0>(next_states[i]);
            int new_y = get<1>(next_states[i]);
            if (visited.find({new_x, new_y}) == visited.end()) {
                visited.insert({new_x, new_y});
                q.push(make_tuple(new_x, new_y, steps + 1));
            }
        }
    }

    return -1; // If no solution is found
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int result = min_steps_to_measure(a, b, c);
    cout << result << endl;
    return 0;
}
