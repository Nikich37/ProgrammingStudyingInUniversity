#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class FileReader {
public:
    std::vector<std::string> ReadLines(const std::string& file_path);
    std::vector<std::string> ReadWords(const std::string& file_path);
};

std::vector<std::string> FileReader::ReadLines(const std::string& file_path) {
    std::vector<std::string> result;
    std::ifstream in(file_path);
    std::string str;
    if (!in.is_open()) {
        std::cout << "failed to open " << file_path << '\n';
    }
    while (std::getline(in, str)) {
        result.push_back(str);
    }
    return result;
}

std::vector<std::string> FileReader::ReadWords(const std::string& file_path) {
    std::vector<std::string> source = ReadLines(file_path);
    std::vector<std::string> result;
    for (auto str : source) {
        str += ' ';
        std::string word;
        for (auto ch : str) {
            if (ch != ' ') {
                word += ch;
            }
            else {
                result.push_back(word);
                word.clear();
            }
        }
    }
    return result;
}