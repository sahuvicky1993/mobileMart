#include "def.h"
/*
 * write all helper fn not-part of class here
 */
using namespace std;

std::ifstream _fd("/home/ee209143/cpp_practice/inventory_items");

Attr* get_item( ){
    Attr*temp=new Attr;
    std::string line;
    if(!_fd)
        return NULL;
    // file descriptor is ready to use
    _fd>>temp->ID>>temp->Brand>>temp->cost>>temp->CamReso>>temp->Storage>>temp->Os;
    temp->next=NULL;
    getline(_fd,line);

    return temp;
}

bool isValid(int id){
    if(id>MAX_RECORD)
        return false;

return true;
}
void delete_item(Attr*temp,Attr*_prev,int id ){
    while(temp){
        if(temp->ID==id){
            _prev->next=temp->next;
            delete temp;
            return;
        }
        temp=temp->next;
    }
}
int print_op(){
    int op;
    std::cout<<"What'd you like to do\n\t1)Add Item\n\t2)Delete Item\n\t3)Show items\n\t";
    std::cout<<"4)Search Item\n\t"<<"6)Quit\n\t"<<"\n";
    std::cin>>op;
    return op;
}

Attr* scanItem(){
Attr*item=new Attr;
cout<<"ID:";
cin>>item->ID;cout<<"\n";

cout<<"Brand:";
cin>>item->Brand;cout<<"\n";

cout<<"cost:";
cin>>item->cost;cout<<"\n";

cout<<"CamReso:";
cin>>item->CamReso;cout<<"\n";

cout<<"Storage";
cin>>item->Storage;cout<<"\n";

cout<<"OS:";
cin>>item->Os;cout<<"\n";
item->next=NULL;
return item;
}
void printById(Attr*temp){
    cout<<"Item found\n";
    cout<<temp->ID<<" "<<temp->Brand<<" "<<temp->CamReso<<" "<<temp->Storage<<" "<<temp->cost<<" "<<temp->Os<<"\n";
}
void createDB(Inventory&I){
    int count=MAX_RECORD;
    Attr*item;
    while(count--){
        if(!(item=get_item())) break; // if get_item fails come out immediately
            I.Add_item(item);
}
}

