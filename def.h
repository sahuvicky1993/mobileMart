#ifndef DEF_H
#define DEF_H
#include<iostream>
#include<string.h>
#include <fstream>
// Do not change this value or update record accordingly in "inventory_items" file
#define MAX_RECORD 5
enum OP {
    ADD_ITEM=1,
    DELETE_ITEM,
    SHOW_ITEMS,
    SEARCH_ITEM,
    QUIT=6
};

typedef struct Attr
{
    int ID;
    char Brand[10];
    float cost;
    int CamReso;
    int Storage;
    char Os[10];
    Attr *next;
}Attr;
class Inventory
{
    Attr*head;
    Attr*tail;    // Dont need. for Future use
public:
    Inventory() {head=NULL;tail=NULL;}
    ~Inventory(){// do not write fn defination outside
        Attr*temp=head;
        while(temp){
        delete temp;
            temp=temp->next;
        }
    };
    bool Add_item(Attr*);
    void Display_item();
    bool Delete_item(int id);
    bool search_itemByRange(int min,int max);
};
/*
 * get_item() is a helper fn so that we dont need to scan i/p from usr which is tedious
 */
Attr* get_item();
bool isValid(int);
void delete_item(Attr*,Attr*,int);
Attr* scanItem();
int print_op();
void printById(Attr*);
void createDB(Inventory&);
/*
 * When we are shutting down we are supposed to clear the Heap
 */
/*
Inventory::~Inventory(){
    Attr*temp=head;
    while(temp){
    delete temp;
        temp=temp->next;
    }
}
*/
#endif // DEF_H
