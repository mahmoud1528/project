#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;

class node {
public:
	string  first_name, last_name, number;


	node* next, * prev;
	node* start, * end;

	node() {
		first_name = "";
		last_name = "";
		number = "";
		next = prev = NULL;
		start = end = NULL;
	}

};

class linked_list {
public:
	node n;
	void insert_front(string fir, string las, string num);
	void insert_first(string fir, string las, string num);
	void insert_At(string fir, string las, string num, string pos);
	bool isempty();
	void display();
	void display_sp(string n);
	void search_with_last(string la);
	void remove_first(string key);
	void remove_last(string key);
	void remove(string key);

};