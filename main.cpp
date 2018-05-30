#include "def.h"
using namespace std;

bool DB_created;// take care of this variable

bool Inventory::Add_item(Attr* item){
    Attr*temp;//=new Attr;
    temp=item;
    //temp->next=NULL;
    if(head==NULL){
    head=temp;
    tail=temp;
    }
    else{
        tail->next=temp;
        tail=tail->next;
    }
}
void Inventory::Display_item(){
    Attr*temp=head;
    if(!temp){
        cout<"No Items...\n";
        return;
    }
    while(temp){
    cout<<temp->ID<<" "<<temp->Brand<<" "<<temp->CamReso<<" "<<temp->Storage<<" "<<temp->cost<<" "<<temp->Os<<"\n";
    temp=temp->next;
    }
}

bool Inventory::Delete_item(int id){
    Attr*temp=head;
    Attr*_prev=NULL;
    if(!isValid(id)) return false;
    while(temp){
        if(temp->ID==id && temp==head){
            // First item delete it and update the header
            head=temp->next;
            delete temp;
            return true;
        }
        else if(temp->ID==id){
            delete_item(temp,_prev,id);
            return true;
        }
        _prev=temp;temp=temp->next;
    }
    return false;
}
bool Inventory::search_itemByRange(int min,int max){
    /* Get the header and check how many items present
    *  between this range
    */
    Attr*temp=head;bool found=false;
    while(temp){
        if(temp->cost >= min && temp->cost<= max ){
            printById(temp);
            found=true;
        }
        temp=temp->next;
    }

    return found;
}

main(){
Inventory I;
Attr*item;
int op=0,id;
int count=MAX_RECORD;
string ans;
bool done=false;
DB_created=false;
while(!done){
    if(!op)
        op=print_op();
    switch (op) {
    case ADD_ITEM:
        if(!(item=scanItem())) cout<<"Error...\n";
        else
            cout<<"U want to add more item\n"; cin>>ans;
        if(ans=="yes"|| ans =="Yes" || ans =="Y" || ans=="y")
            op=1;
        else
            op=0;
        break;
    case DELETE_ITEM:
        cout<<"Enter item id to be deleted\n"; cin>>id;
        if(isValid(id))
        I.Delete_item(id);
        break;
    case SHOW_ITEMS:
        if(!DB_created){
            createDB(I);
            DB_created=true; // we have created the database
            op=0;
        }
        else{
            I.Display_item();done=true;
        }
        break;
    case SEARCH_ITEM:
        int min,max;
        cout<<"Enter min price\n"; cin>>min;
        cout<<"Enter max price\n"; cin>>max;
        if(!DB_created){
            createDB(I);
        }
        if(!I.search_itemByRange(min,max))
            cout<<"Item not found in this range\n";op=0;
        break;
    case QUIT:
        done =true;
        break;
    default:
        cout<<"Invalid Option\n"; op=0;
        break;
    }

}
}
