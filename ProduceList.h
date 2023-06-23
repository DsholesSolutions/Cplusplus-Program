#ifndef STOREITEM_H
#define PRODUCE_H

#include <string>
#include <map>

using namespace std;

class ProduceList {

	public:

		ProduceList(string name, int quantity);
		ProduceList();
		string getKey();
		void setKey(string inputKey);
		int getQuantity();
		void setQuantity(int inputQuantity);
		void printList(map<string, int> inventory);
		void displayFrequency(map<string, int> inventory);
		void printHistogram(map<string, int> inventory);
		map<string, int> fillMap(map<string, int> inventory);
		map<string, int> itemList;
	

	private:

		string key;
		int quantity;
};

#endif