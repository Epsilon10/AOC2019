#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include "utils.hh"

char constexpr delim = ',';

using Point = std::pair<int,int>;
using PointWithSteps = std::pair<Point, int>;

std::vector<PointWithSteps> get_wire_points(std::vector<std::string> const& data) {
    std::vector<PointWithSteps> points;
    int x = 0;
    int y =0;
    int steps=0;
    for (std::size_t i = 0; i < data.size(); i++) {
        auto const instruction = data[i];
        auto const opcode = instruction.at(0);
        auto const amt = std::stoi(instruction.substr(1));
        for (std::size_t n = 0; n < amt; n++) {
            if (opcode == 'R') x++;
            else if (opcode == 'L') x--;
            else if (opcode == 'U') y++;
            else y--;
            steps++;
            points.emplace_back(Point(x,y), steps);
        }

    }

    return points;
} 

std::pair<int,int> calculate(std::vector<std::string> const& wire_1_data, std::vector<std::string> const& wire_2_data) {
    auto wire_1_points = get_wire_points(wire_1_data);
    auto wire_2_points = get_wire_points(wire_2_data);

    std::uint32_t min_dist = std::numeric_limits<std::uint32_t>::max();
    std::uint32_t min_steps = std::numeric_limits<std::uint32_t>::max();

    for (auto const& p1 : wire_1_points) {
        for (auto const& p2 : wire_2_points) {
            if (p1.first == p2.first) {
                auto const dist = std::abs(p1.first.first) + std::abs(p1.first.second);
                if (dist < min_dist) min_dist = dist;

                auto const steps = p1.second + p2.second;
                if (steps < min_steps) min_steps = steps;
            }
        }
    }

    return std::make_pair(min_dist, min_steps);
}


int main() {
    auto const wire_data = read_file_lines("./inputs/day3.txt");

    auto const wire_1_data = split_string(wire_data[0], delim);
    auto const wire_2_data = split_string(wire_data[1], delim);

    auto const res = calculate(wire_1_data, wire_2_data);
    auto const p1_ans = res.first;
    auto const p2_ans = res.second;
    std::cout << "Part 1: " << p1_ans << std::endl;
    std::cout << "Part 2: " << p2_ans << std::endl;
}