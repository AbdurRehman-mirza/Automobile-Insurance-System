#pragma once
#include <string>
#include <vector>
using namespace std;
class FileHandler
{
private:
    string filePath;

public:
    FileHandler();
    FileHandler(string path);

    // Read all lines from file → returns vector of strings
    vector<string> readAllLines();

    // Write a brand new line at end of file
    void appendLine(string line);

    // Overwrite entire file with new data
    void writeAllLines(vector<string> lines);

    // Delete a line that starts with given ID
    bool deleteByID(string id);

    // Check if a record with given ID already exists
    bool exists(string id);

    // Get a single line that starts with given ID
    string getLineByID(string id);

    // Set file path
    void setFilePath(string path);
    string getFilePath();
};

