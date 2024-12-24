#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    // Handle case where a is 0
    if (a == 0) {
        if (b == 0) {
            std::cout << "NO SOLUTION" << std::endl;
        } else {
            double x0 = static_cast<double>(-c) / b;
            std::cout << std::fixed << std::setprecision(2) << x0 << std::endl;
        }
        return 0;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        std::cout << "NO SOLUTION" << std::endl;
    } else if (discriminant == 0) {
        double x0 = static_cast<double>(-b) / (2 * a);
        std::cout << std::fixed << std::setprecision(2) << x0 << std::endl;
    } else {
        double sqrtD = std::sqrt(discriminant);
        double x1 = (-b - sqrtD) / (2 * a);
        double x2 = (-b + sqrtD) / (2 * a);
        
        // Ensure x1 is the smaller and x2 is the larger
        if (x1 > x2) {
            std::swap(x1, x2);
        }
        
        std::cout << std::fixed << std::setprecision(2) << x1 << " " << x2 << std::endl;
    }

    return 0;
}
