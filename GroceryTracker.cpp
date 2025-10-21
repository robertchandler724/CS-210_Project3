// File: GroceryTracker.cpp
// Developer: Robert Chandler
// Date: 10/16/2025
// Purpose: Implements the GroceryTracker class for tracking grocery item frequencies.

#include "GroceryTracker.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

// ToLower: converts a string to lowercase.
std::string GroceryTracker::ToLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// LoadData: Reads grocery items from a file.
void GroceryTracker::LoadData(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string itemName;

    if (!inputFile) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        std::cerr << "Make sure the file exists in the correct directory." << std::endl;
        exit(1);
    }

    // Read each item and update the map
    while (inputFile >> itemName) {
        itemName = ToLower(itemName); // convert to lowercase
        // increment the frequency count for the item
        itemFrequencies[itemName]++;
    }

    inputFile.close();

    if (itemFrequencies.empty()) {
        std::cerr << "Warning: No data found in the file: " << filename << ".\n";
    }

    SaveBackup("frequency.dat");
}

//SaveBackup: writes the item frequencies to a backup file.
void GroceryTracker::SaveBackup(const std::string& filename) {
    std::ofstream outputFile(filename); // open file for writing

    if (!outputFile) {
        std::cerr << "Error: Unable to create backup file: " << filename << std::endl;
        return;
    }

    // Write each item and its frequency to the file
    for (const auto& pair : itemFrequencies) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close(); //close when done
}

//GetItemFrequency: gets the frequency of a specific item.
int GroceryTracker::getItemFrequency(const std::string& itemName) {
    std::string item = ToLower(itemName); // convert to lowercase
    //check if item exists in the map
    if (itemFrequencies.find(item) != itemFrequencies.end()) {
        return itemFrequencies[item]; // return frequency if found
    } else {
        return 0; // return 0 if item not found
    }
}

// PrintAllFrequencies: prints all item frequencies.
void GroceryTracker::PrintAllFrequencies() {
    std::cout << "\n=== Item Frequency List: ===\n";
    std::cout << std::left << std::setw(15) << "Item" << "Frequency\n";
    std::cout << "-------------------------\n";

    // Iterate through the map and print each item and its frequency
    for (const auto& pair : itemFrequencies) {
        std::cout << std::left << std::setw(15) << pair.first << pair.second << std::endl;
    }

    if (itemFrequencies.empty()) {
        std::cout << "No items available to display.\n";
    }
}

//PrintHistogram: prints a histogram of item frequencies.
void GroceryTracker::PrintHistogram() {
    std::cout << "\n=== Item Frequency Histogram: ===\n";
    std::cout << "-------------------------\n";

    if(itemFrequencies.empty()) {
        std::cout << "No items available to display.\n";
        return;
    }

    // Iterate through the map and print one line per item
    for (const auto& pair : itemFrequencies) {
        std::cout << std::left << std::setw(15) << pair.first;
        // Print one "*" for each occurrence of the item
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*"; // print an asterisk for each occurrence
        }
        std::cout << std::endl;
    }
}