#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <chrono>

#include "utils.hh"

int fuel_from_mass(int mass) {
    return static_cast<int>(std::floor(mass / 3)) - 2;
}

int fuel_from_mass_recursive(int mass, int total_fuel = 0){ 
    auto const fuel = fuel_from_mass(mass);
    if (fuel > 0) return fuel_from_mass_recursive(fuel, total_fuel + fuel);
    return total_fuel;
};

int part_one() {
    auto const masses = read_file_lines_int("./inputs/day1.txt");

    int sum = 0;
    for (auto mass : masses) {
        auto const fuel = fuel_from_mass(mass);
        sum += fuel;
    }

    return sum;
}

int part_two() {
    auto const masses = read_file_lines_int("./inputs/day1.txt");
    
    int sum = 0;
    for (auto mass : masses) {
        auto const fuel = fuel_from_mass_recursive(mass);
        sum += fuel;
    }

    return sum;
}

int main() {
    auto const p1_start = std::chrono::steady_clock::now();
    auto const p1_ans = part_one();
    auto const p1_end = std::chrono::steady_clock::now();

    auto const p2_start = std::chrono::steady_clock::now();
    auto const p2_ans = part_two();
    auto const p2_end = std::chrono::steady_clock::now();

    auto const p1_time_ms = std::chrono::duration <double, std::milli>(p1_end - p1_start).count();
    auto const p2_time_ms = std::chrono::duration <double, std::milli>(p2_end - p2_start).count();

    std::cout << "Part 1: " << p1_ans << "\tExecuted in ( with -O3 ): " << p1_time_ms <<  " ms" << std::endl;
    std::cout << "Part 2: " << p2_ans << "\tExecuted in ( with -O3 ): " << p2_time_ms << " ms" << std::endl;
}