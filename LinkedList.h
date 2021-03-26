#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <time.h>
#include <iomanip>
using namespace std;

class node {

public:
	int info;
	node* link;
	node* first;
};

node *buildListForwardOneMillion() {//Code from Udemy modified
	node* first, * last, * newNode;
	int num = 0, listSize = 1000000;
	
	first = last = nullptr;
	node* current = first;	
	for (int i = 0; i < listSize; i++) {
		num = (rand() % 1000000);//Creates the random numbers into the nodes

		newNode = new node;
		newNode->info = num;
		newNode->link = nullptr;

		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			last->link = newNode;
			last = newNode;
		}
	}
	 
	
	return first;
}
node* buildListForwardTenMillion() {
	node* first, * last, * newNode;
	int num = 0, listSize = 10000000;

	first = last = nullptr;

	for (int i = 0; i < listSize; i++) {
		num = (rand() % 1000000);//Creates the random numbers into the nodes

		newNode = new node;
		newNode->info = num;
		newNode->link = nullptr;

		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			last->link = newNode;
			last = newNode;
		}
	}
	return first;
}
bool LLsearch(const int searchItem) { //Code from udemy
	node* first = nullptr;
	node* current = first;
	bool found = true;
	current = first;
	while (current != nullptr) {
		if (current->info == searchItem) {
			return true;
		}
		else {
			current = current->link;
		}
	}

}