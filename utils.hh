#pragma once

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::string> read_file_lines(std::string&& filename) {
    std::ifstream file{filename};
    std::vector<std::string> lines;
    std::string line;

    while(std::getline(file, line)) 
        lines.push_back(line);
    return lines;
}

std::vector<int> read_file_lines_int(std::string&& filename) {
    std::ifstream file{filename};
    std::vector<int> lines;
    std::string line;

    while(std::getline(file, line)) 
        lines.push_back(std::stoi(line));
    return lines;
}

std::vector<std::string> split_string(std::string const& str, char delim) {
    std::stringstream ss(str);
    std::vector<std::string> result;

    while(ss.good()) {
        std::string substr;
        std::getline(ss, substr, delim);
        result.push_back(substr);
    }

    return result;
}