#include "linked_list.h"
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;


//project data struture
int main() {
    linked_list l;
    string  first_name, last_name, n, letter;
    char num[11];
    char ch;

    do {
       
        cout << "\n\n\n\t Main Menu";
        cout << "\n\n\t1) Insert Contant on Phone_Book";
        cout << "\n\n\t2) Search With First_Name";
        cout << "\n\n\t3) Search With last_Name";
        cout << "\n\n\t4) Diplay contact";
        cout << "\n\n\t5) Remove With Last_Name";
        cout << "\n\n\t6) Exit\n\n";
        cin >> ch;
        system("cls");
        switch (ch) {
        case'1':
            cout << "\n1)insert_first";
            cout << "\n2)insert_front\n";
            char c;
            cin >> c;
            switch (c) {
            case'1':
                cout << "\nenter first and last name and phone : ";
                cin >> first_name >> last_name >> n;
                l.insert_first(first_name, last_name, n);
                system("cls");
                break;
            case'2':
                cout << "\nenter first and last name and phone : ";
                cin >> first_name >> last_name >> n;
                l.insert_front(first_name, last_name, n);
                system("cls");
                break;
            default:
                cout << "\a";
            }
            break;

        case'2':
            cout << "enter first_name : ";
            cin >> first_name;
            l.display_sp(first_name);
            break;
            case'3':
                cout << "\nenter last name : ";
                cin >> last_name;
                l.search_with_last(last_name);
                break;
            case'4':
                l.display();
                break;
            case'5':
                cout << "\nenter last name : ";
                cin >> last_name;
                l. remove(last_name);
            case'6':
                cout << "\n\n\tThanks for using our Phone_Book";
                break;
        default:
            cout << "\a";
        }
       
    }
    while (ch != '6');
   

}








































/*for (int i = 1; i <= 2; i++) {
        cout << "Enter first_name of content : ";
        cin >> first_name;


        cout << "\nEnter last_name of content : ";
        cin >> last_name;

        cout << "\nEnter number of content : ";
        cin >> num;
        cout << "\n";

        l.insert_front(first_name ,last_name, num);

    }
    l.insert_front("mahmoud", "magdy", "0525445");
    l.insert_front("ahmed", "sayed", "4885115");
    l.insert_front("ali", "hassan", "894132");


    l.display();
     cout << "\nEnter last_name to search : ";
     cin >> n;
     if (l.search_with_last(n))
         cout << "\nfound it!!!!!!!!!!!!\n";
     else
         cout << "\nNot found!!!!!!!!!!!!!!!\n";

         cout << "\nEnter letter to search for it in yout contact : ";
         cin >> letter;
         l.display_sp(letter);

          cout << "\nenter last name of content to delete them : ";
          cin >> letter;
          l.remove(letter);

    l.insert_At("amr", "mohamed", "15663541", "sayed");

    cout << "\n\t\t\t\tlist after insert_At\n";
    l.display();*/