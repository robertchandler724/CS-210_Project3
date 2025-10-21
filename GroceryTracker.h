// File: GroceryTracker.h
// Developer: Robert Chandler
// Date: 10/16/2025
// Purpose: Defines the GroceryTracker class for tracking grocery item frequencies.

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <string>
#include <map>

class GroceryTracker {
private:
    // Map container store item names and their frequencies
    std::map<std::string, int> itemFrequencies;

public:
    void LoadData(const std::string& filename);
    void SaveBackup(const std::string& filename);
    int getItemFrequency(const std::string& item);
    void PrintAllFrequencies();
    void PrintHistogram();
    std::string ToLower(const std::string& str); // helpers to convert string to lowercase
};

#endif // GROCERYTRACKER_H