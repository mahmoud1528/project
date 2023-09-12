#include "linked_list.h"
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

void linked_list::insert_first(string fir, string las, string num) {
	node* newnode = new node();
	newnode->first_name = fir;
	newnode->last_name = las;
	newnode->number = num;

	if (isempty()) {

		n.start = n.end = newnode;
		newnode->prev = newnode->next = NULL;

	}
	else {
		newnode->next = n.start;
		newnode->prev = NULL;
		n.start->prev = newnode;
		n.start = newnode;


	}



}


void linked_list::insert_front(string fir, string las, string num)
{

	node* newnode = new node();
	newnode->first_name = fir;
	newnode->last_name = las;
	newnode->number = num;

	if (isempty()) {

		n.start = n.end = newnode;
		newnode->prev = newnode->next = NULL;

	}
	else {
		newnode->prev = n.start;
		newnode->next = NULL;
		n.end->next = newnode;
		n.end = newnode;


	}

}

void linked_list::insert_At(string fir, string las, string num, string pos)
{
	node* newnode = new node();
	newnode->first_name = fir;
	newnode->last_name = las;
	newnode->number = num;
	node* ptr = n.start;
	node* ptr2 = n.end;

	if (isempty())
		insert_first(fir, las, num);

	else if (pos == ptr->last_name) {

		insert_front(fir, las, num);

	}
	else if (pos == ptr2->last_name)
		insert_front(fir, las, num);

	else {
		ptr = ptr->next;
		while (ptr->next->next != NULL) {
			if (pos == ptr->last_name)
				break;

			ptr = ptr->next;
		}
		newnode->next = ptr->next;
		newnode->prev = ptr;
		ptr->next = newnode;
		ptr->next->prev = newnode;
	}

}





bool linked_list::isempty()
{
	if (n.start == NULL)
		return true;

	return false;
}

void linked_list::display() {
	node* ptr = n.start;

	if (isempty())
		cout << "\nlist is empty\n";
	else {
		while (ptr != NULL) {
			cout << "\n" << ptr->first_name << " " << ptr->last_name << " : " << ptr->number << "\n";
			ptr = ptr->next;
		}
	}


}

void linked_list::display_sp(string letter)
{
	node* ptr = n.start;


	if (isempty())
		cout << "\nlist is empty\n";

	else {
		if (letter != ptr->first_name)
			cout << "\nnot found any thing!!!!!!\n";

		while (ptr != NULL) {

			if (letter == ptr->first_name)
				cout << "\n" << ptr->first_name << " " << ptr->last_name << " : " << ptr->number << "\n";

			ptr = ptr->next;
		}

	}


}

void linked_list::search_with_last(string la) {

	node* ptr = n.start;


	if (isempty())
		cout << "\nlist is empty\n";

	else {
		if (la != ptr->last_name)
			cout << "\nnot found any thing!!!!!!\n";

		while (ptr != NULL) {

			if (la == ptr->last_name)
				cout << "\n" << ptr->first_name << " " << ptr->last_name << " : " << ptr->number << "\n";

			ptr = ptr->next;
		}

	}
}

void linked_list::remove_first(string key) {
	string lost1, lost2, lost3;
	node* ptr = n.start;

	if (isempty())
		cout << "\nlist is empty\n";

	else if (key == ptr->last_name) {


		if (ptr->next == NULL && ptr->prev == NULL) {                   // 1) lonely element in list
			lost1 = ptr->first_name;
			lost2 = ptr->last_name;
			lost3 = ptr->number;
			delete ptr, n.start, n.end;

			ptr = n.start = n.end = NULL;
			cout << "\nelement is deleted is alone\n";
		}
		//2)first element in list
		else
		{
			lost1 = ptr->first_name;
			lost2 = ptr->last_name;
			lost3 = ptr->number;
			n.start = n.start->next;
			n.start->prev = NULL;
			delete ptr;

			ptr = NULL;
			cout << "\nelement is deleted in first\n";
		}
		cout << lost1 << " " << lost2 << " : " << lost3 << "\n";
	}
}



void linked_list::remove_last(string key) {
	string lost1, lost2, lost3;
	node* ptr = n.end;

	if (isempty())
		cout << "\nlist is empty\n";



	else if (key == ptr->last_name) {

		if (ptr->next == NULL && ptr->prev == NULL) {                   //lonely element
			lost1 = ptr->first_name;
			lost2 = ptr->last_name;
			lost3 = ptr->number;
			delete ptr, n.start, n.end;

			ptr = n.start = n.end = NULL;
			cout << "\nelement is deleted is alone\n";
		}
		else {                                                         //last element
			lost1 = ptr->first_name;
			lost2 = ptr->last_name;
			lost3 = ptr->number;
			n.end = n.end->prev;
			n.end->next = NULL;
			delete ptr;
			cout << "\nelement is deleted in last\n";
		}
		cout << lost1 << " " << lost2 << " : " << lost3 << "\n";
	}
}


void linked_list::remove(string key) {
	string lost1, lost2, lost3;
	node* ptr = n.start;

	if (isempty())
		cout << "\nlist is empty\n";

	if (ptr->last_name == key)
		remove_first(key);

	else {

		ptr = ptr->next;
		while (ptr != NULL) {
			if (ptr->last_name == key)
				break;

			ptr = ptr->next;
		}

		if (ptr == NULL)
			cout << "\nelement not found\n";

		else if (ptr->next == NULL)
			remove_last(key);

		else {
			lost1 = ptr->first_name;
			lost2 = ptr->last_name;
			lost3 = ptr->number;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			delete ptr;
			ptr = NULL;
			cout << "\nelement is delete in middle\n";
			cout << lost1 << " " << lost2 << " : " << lost3 << "\n";
		}
	}

}