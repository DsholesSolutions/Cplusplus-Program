#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "ProduceList.h"

ProduceList::ProduceList()
{
    //Default constructor
}

ProduceList::ProduceList(string name, int inputQuantity)
{
    // Constructor
	key = name;
	quantity = inputQuantity;
}

string ProduceList::getKey() 
{
    // Find Key
	return key;
}

void ProduceList::setKey(string inputKey) {
	// Set the key
    key = inputKey;
}

int ProduceList::getQuantity() 
{
    // Find quantity
	return quantity;
}

void ProduceList::setQuantity(int inputQuantity) {
	// Set the quantity
    quantity = inputQuantity;
}

map<string, int> fillMap(map<string, int> inventory) 
{
    string produceName;

    // Open file for input:
    ifstream inFS;
    inFS.open("CS210_Project_Three_Input_File.txt");
    while (!inFS.eof())
    {
        // Read from file
        inFS >> produceName;

        // Fill map with data from file
        if (inventory.count(produceName) == 0)
        {
            inventory.emplace(produceName, 1);
        }
        else if (inventory.count(produceName) == 1)
        {
            inventory.at(produceName) = inventory.at(produceName)++;

        }

    }
    // Close file
    inFS.close();
    return inventory;
}

void ProduceList::printList(map<string, int> inventory)
{
    // Print entire list of items
    for (auto it = inventory.begin(); it != inventory.end(); it++)
    {
        cout << it->first << "  " << it->second << endl;
    }
}

void ProduceList::printHistogram(map<string, int> inventory)
{
    // Print text histogram
    for (auto it = inventory.begin(); it != inventory.end(); it++)
    {
        cout << it->first << "  ";
        for (int i = 0; i < it->second; i++)
        {
            cout << "*";
        }
        cout << endl;
    }

}

void ProduceList::displayFrequency(map<string, int> inventory)
{
    // Find the frequency of a given item name
    string item;
    cout << "Enter the name of a product: " << endl;
    cin >> item;

    if (inventory.count(item))
    {
        cout << inventory.at(item) << endl << endl;
    }
    else
    {
        cout << "Item not found, please try again." << endl << endl;
        displayFrequency(inventory);
    }
}

map<string, int> ProduceList::fillMap(map<string, int> inventory)
{
    // Populate map with inventory data
    string produceName;

    ifstream inFS;
    inFS.open("CS210ProjectThreeInputFile.txt");
    while (!inFS.eof())
    {
        inFS >> produceName;

        if (inventory.count(produceName) == 0)
        {
            inventory.emplace(produceName, 1);
        }
        else if (inventory.count(produceName) == 1)
        {
            inventory.at(produceName) = inventory.at(produceName)++;

        }
            
    }
    // Close file
    inFS.close();
    return inventory;


}

