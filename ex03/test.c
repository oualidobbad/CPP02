#include "Point.hpp"

void test(const Point &a, const Point &b, const Point &c, const Point &p, const std::string &name)
{
    std::cout << name << ": ";
    if (bsp(a, b, c, p))
        std::cout << "inside ✅" << std::endl;
    else
        std::cout << "outside ❌" << std::endl;
}

int main()
{
    Point a(2.0f, 2.0f);
    Point b(1.0f, 0.0f);
    Point c(1.0f, 4.0f);

    std::cout << "Triangle vertices: A(2,2), B(1,0), C(1,4)\n\n";

    // --- TEST CASES ---

    // ✅ Clearly inside (should return true)
    test(a, b, c, Point(1.5f, 2.0f), "Test 1 (inside)");

    // ❌ On an edge (should return false)
    test(a, b, c, Point(1.5f, 1.0f), "Test 2 (on edge)");

    // ❌ On a vertex (should return false)
    test(a, b, c, Point(1.0f, 0.0f), "Test 3 (on vertex)");

    // ❌ Outside to the left (should return false)
    test(a, b, c, Point(0.5f, 2.0f), "Test 4 (outside left)");

    // ❌ Outside to the right (should return false)
    test(a, b, c, Point(2.5f, 2.0f), "Test 5 (outside right)");

    // ❌ Far away (should return false)
    test(a, b, c, Point(10.0f, 10.0f), "Test 6 (far outside)");

    // ✅ Very close to edge, but still inside (depending on precision)
    test(a, b, c, Point(1.1001f, 2.0f), "Test 7 (border precision - should be inside)");

    // ❌ Very close to edge, but exactly on it (should be outside)
    test(a, b, c, Point(1.0f, 2.0f), "Test 8 (exactly on edge - outside)");

    // ✅ Another inside example (in middle area)
    test(a, b, c, Point(1.4f, 2.1f), "Test 9 (inside)");

    // ❌ On line between A and C (edge case)
    test(a, b, c, Point(1.5f, 3.0f), "Test 10 (on edge AC - outside)");
}

// #include <iostream>

// // Assuming you have Point and Fixed classes defined

// int main()
// {
//     // Triangle vertices
//     Point a(0, 0);
//     Point b(10, 0);
//     Point c(5, 10);
    
//     // Test points
//     Point inside(5, 3);
//     Point outside(15, 5);
//     Point on_edge(5, 0);      // On edge AB
//     Point on_vertex(0, 0);    // On vertex A
    
//     std::cout << "Point (5,3): " << (bsp(a, b, c, inside) ? "Inside" : "Outside") << std::endl;
//     std::cout << "Point (15,5): " << (bsp(a, b, c, outside) ? "Inside" : "Outside") << std::endl;
//     std::cout << "Point (5,0): " << (bsp(a, b, c, on_edge) ? "Inside" : "Outside") << std::endl;
//     std::cout << "Point (0,0): " << (bsp(a, b, c, on_vertex) ? "Inside" : "Outside") << std::endl;
    
//     return 0;
// }

