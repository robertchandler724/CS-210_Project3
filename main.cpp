// File: main.cpp
// Developer: Robert Chandler
// Date: 10/16/2025
// Purpose: Serves as the entry point for the Grocery Tracker application.

#include <iostream>
#include <string>
#include "GroceryTracker.h"
#include <limits>

using namespace std;

int main() {
    GroceryTracker tracker; // create an instance of GroceryTracker

    // Load grocery items from a file
    tracker.LoadData("CS210_Project_Three_Input_File.txt");

    int choice = 0; // stores user menu choice

    // Main loop
    while (true) {
        while (true) {
            // Display menu options
            cout << "\n=== Corner Grocery Item Tracker ===\n";
            cout << "1. Search for an item frequency\n";
            cout << "2. Print list of all item frequencies\n";
            cout << "3. Print histogram of item frequencies\n";
            cout << "4. Exit program\n";
            cout << "Enter your choice (1-4): ";
    
            // Handle invalid input
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number between 1 and 4.\n";
                continue;
            }
    
            if (choice < 1 || choice > 4) {
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                continue;
            }
            break; // valid input, exit inner loop
        }

        // Menu option 1
        if (choice == 1) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline from input buffer
            string item;
            cout << "Enter item name: ";
            getline(cin, item); //get full line input

            //trim leading/trailing whitespace
            item.erase(0, item.find_first_not_of(" \t\n\r\f\v"));
            item.erase(item.find_last_not_of(" \t\n\r\f\v") + 1);

            // validation ensures non-empty input and alphabetic
            if (item.empty()) {
                cout << "Error: You must enter a valid item name.\n";
                cout << "Press Enter to return to the menu...";
                cin.get();
                continue;
            }

            bool valid = true;
            for (char c : item) {
                if (!isalpha(c)) {
                    cout << "Error: Item name must contain only letters.\n";
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                cout << "Press Enter to return to the menu...";
                cin.get();
                continue;
            }

            // Lookup frequency
            int frequency = tracker.getItemFrequency(item);
            if (frequency > 0)
                cout << item << " was purchased " << frequency << " times.\n";
            else
                cout << item << " not found in the list.\n";

            // Pause before returning to menu
            cout << "Press Enter to return to the menu...";
            cin.get();
        }

        // Menu option 2
        else if (choice == 2) {
            tracker.PrintAllFrequencies();

            // Pause before returning to menu
            cout << "Press Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }

        // Menu option 3
        else if (choice == 3) {
            tracker.PrintHistogram();

            // Pause before returning to menu
            cout << "Press Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }

        // Menu option 4
        else if (choice == 4) {
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        // Handle out-of-range input
        else {
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

return 0;
}