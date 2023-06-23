// CornerGrocer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <fstream>
#include "ProduceList.h"

using namespace std;




void displayMenu(ProduceList proList, map<string, int> inventory) {

    // Show menu and take user selection with input validation

    int menuChoice = 0;


        while (menuChoice != 4) {
            cout << "1. Frequency of a Given Item" << endl;
            cout << "2. Frequency of all Purchased Items" << endl;
            cout << "3. Display Histogram" << endl;
            cout << "4. Exit Program" << endl;

            cin >> menuChoice;

            if (menuChoice == 1)
            {
                proList.displayFrequency(inventory);
            }
            else if (menuChoice == 2)
            {
                proList.printList(inventory);

            }
            else if (menuChoice == 3)
            {
                proList.printHistogram(inventory);
            }
            else if (menuChoice == 4)
            {
                exit(0);
            }
            else
            {
                cout << "Invalid entry, please try again..." << endl;
                menuChoice = 0;

                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

                displayMenu(proList, inventory);

            }
        }
    }



void backupData(map<string, int> dataMap)
{
    ofstream outFS;
    // Open File
    outFS.open("frequency.dat");


    for (auto it = dataMap.begin(); it != dataMap.end(); ++it)
    {
        outFS << it->first << " " << it->second << endl;
    }

    // Close file
    outFS.close();
}


int main()
{
    map<string, int> inventoryMap;

    ProduceList inventoryList;

    map<string, int> inventory = inventoryList.fillMap(inventoryMap);

    backupData(inventory);

    displayMenu(inventoryList, inventory);

    return 0;
}