#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

// Constructors
FileHandler::FileHandler() {
    filePath = "";
}

FileHandler::FileHandler(string path) {
    filePath = path;
}

// Read all lines from file
// Returns empty vector if file doesn't exist
vector<string> FileHandler::readAllLines() {
    vector<string> lines;
    ifstream file(filePath);

    if (!file.is_open()) {
        return lines; // return empty if file not found
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

// Append one line to end of file
void FileHandler::appendLine(string line) {
    ofstream file(filePath, ios::app);

    if (!file.is_open()) {
        cout << "Error: Could not open file: " << filePath << endl;
        return;
    }

    file << line << endl;
    file.close();
}

// Overwrite entire file with new set of lines
// Used for update and delete operations
void FileHandler::writeAllLines(vector<string> lines) {
    ofstream file(filePath, ios::trunc);

    if (!file.is_open()) {
        cout << "Error: Could not open file: " << filePath << endl;
        return;
    }

    for (int i = 0; i < lines.size(); i++) {
        file << lines[i] << "\n";
    }
    file.close();
}

// Delete the line whose first field matches given ID
// Fields are separated by '|'
// Returns true if deleted, false if not found
bool FileHandler::deleteByID(string id) {
    vector<string> lines = readAllLines();
    vector<string> updated;
    bool found = false;

    for (int i = 0; i < lines.size(); i++) {
        // get first field before '|'
        string firstField = lines[i].substr(0, lines[i].find('|'));
        if (firstField == id) {
            found = true; // skip this line = delete it
        }
        else {
            updated.push_back(lines[i]);
        }
    }

    if (found) {
        writeAllLines(updated);
    }
    return found;
}

// Check if record with given ID exists
bool FileHandler::exists(string id) {
    vector<string> lines = readAllLines();

    for (int i = 0; i < lines.size(); i++) {
        string firstField = lines[i].substr(0, lines[i].find('|'));
        if (firstField == id) {
            return true;
        }
    }
    return false;
}

// Get the full line whose first field matches given ID
// Returns empty string if not found
string FileHandler::getLineByID(string id) {
    vector<string> lines = readAllLines();

    for (int i = 0; i < lines.size(); i++) {
        string firstField = lines[i].substr(0, lines[i].find('|'));
        if (firstField == id) {
            return lines[i];
        }
    }
    return "";
}

// Getters / Setters
void FileHandler::setFilePath(string path) {
    filePath = path;
}

string FileHandler::getFilePath() {
    return filePath;
}