#include <bits\stdc++.h>
using namespace std;
class Hotel
{
    private:
      {
        int id,date;
       string name,roomtype;
       Node* next;
      };
      public:
         Node* head = NULL;
         void insert();
         void menu();
         void update();
         void search();
         void delete();
         void sort();
         void show();
         void list();
};
void library::menu()
{
    int choice;
    cout<<"\n";
    cout<<"\t Welome To Hotel Management System"<<endl;
    cout<<"\n\t____Hotel Management System____";
    cout<<"\n\ns.No    Function   Descriptioon"<<endl;
    cout<<"\n1\tAllocate Room\t\t\tInset New Room";
    cout<<"\n2\tSearch Room\t\t\tSearch room using RoomID ";
    cout<<"\n3\tUpdate\t\t\tupdate Record";
    cout<<"\n4\tDelete Room\t\t\t Delete Room with RoomID";
    cout<<"\n5\tShow Room records\t\t\tshow the room records (that we addded)";
    cout<<"\n6\tExits"<<endl;
    
    cout<<"Enter Your Choice"<<endl;
    cn>>choice;
    switch(choice)
      {
        case 1:
           insert();
            menu();
        case 2:
           search();
             menu();
        case 3:
           Update();
           menu();
        case 4:
           delete();
           menu();
        case 5:
           show();
           menu();
        case 6:
           Exits();
             default:
             cout<<"Invalid";
      }
}
void Hotel::insert()
{
    cout<<"\n\t____Hotel Management System____";
    Node *new_Node= new Node;
    cout<<"\nEnter Room ID"<<endl;
    cin>>new_node->id;
    cout<<"\nEnter customer Name"<<endl;
    cin>>new_node->name;
    cout<<"\nEnter alloacate date"<<endl;
    cin>>new_node->date;
    cout<<"\nEnter Room Type(single/double/twin)"<<endl;
    cin>>new_node->roomtype;
     
     if(head!=NULL)
     {
        head *new_node;
     }
     else
     {
        Node* ptr = head;
        while(ptr->next != NULL)
        {
            ptr* ptr->next;
        }
        ptr->next = new_node;
     }
     cout<<"\n\n\t\t New Room Inserted";

}

void Hotel::search()
{
    cout<<"\n\t____Hotel Management System____";
     int t_id;
     if(head!=NULL)
     {
        cout<<"\n\nLinkedList is Empty";
     }
    else
     {  cout<<"\n\nRoom ID";
     cin>>t_id;
      Node* ptr = head;
      while(ptr!=NULL)
        {
            if(t_id == ptr->id)
            {
                cout<<"\n\nRoom ID"<<ptr->id;
                cout<<"\n\nCustomer Name"<<ptr->name;
                cout<<"\n\nRoom Alloaction Date"<<ptr->date;
                cout<<"\n\nRoom Type"<<ptr->roomtype;
            }
        }
      }    
}
void Hotel::update()
{
    cout<<"\n\t____Hotel Management System____";
     int t_id;
     if(head!=NULL)
     {
        cout<<"\n\nLinkedList is Empty";
     }
     else
     {
        cout<<"\n\nRoom ID";
        cin>>t_id;
        Node *ptr = head;
        while(ptr!= NULL)
        {
           if(t_id==ptr->id) 
             {
                cout<<"\n\nRoomID";
                cin>>ptr->id;

                cout<<"\n\ncustomer Name";
                cin>>ptr->name;

                cout<<"\n\nAllocated Date";
                cin>>ptr->date;

                cout<<"\n\nRoom Type";
                cin>>ptr->roomtype;

                cout<<"\n\n\t\t Update Record Successfully";
             }
             ptr = ptr->next;
        }
     }
}
void Hotel::delete()
{
    cout<<"\n\t____Hotel Management System____";
     int t_id;
     if(head!=NULL)
     {
        cout<<"\n\nLinkedList is Empty";
     }
     else
     {
        cout<<"\n\nRoom ID";
        cin>>t_id;
        if(t_id = head->id)
          {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout<<"Delete the room Record Successfully";
          }
          else
          {
            Node* pre = head;
            Node* ptr = head;

            while(ptr!= NULL)
            {
               if(t_id == ptr->id) 
                 {
                    pre->next = ptr->next;
                    delete ptr;
                    cout<<"Delete the room Record Successfully";
                    break;
                 }
                 pre = ptr;
                 ptr=ptr->next;
            }

          }
 }
}
 void Hotel::show()
 {
    Node* ptr = head;
    while(ptr!= NULL)
       {
        cout<<"\n\nRoomID"<<ptr->id;
        cout<<"\n\nCustomer Name"<<ptr->name;
        cout<<"\n\nAllocation"<<ptr->date;
        cout<<"\n\nRoom Type"<<ptr->roomtype;
       }
 }

 void Hotel::sort()
 {
    if(head!=NULL)
     {
        cout<<"\n\nLinkedList is Empty";
        menu();
     }
     int count =0, t_date,t_id;
     string t_name, t_roomtype;
     Node* ptr = head;
     while(ptr!= NULL)
     {
        count++;
        ptr = ptr->next;
     }
     for(int i=1; i<=count; i++)
     {
        Node *ptr = head;
        for(int j=1; i<=count; j++)
         {
            if(ptr->id>ptr->next->id)
             {
                t_id = ptr->id;
                t_name = ptr->name;
                t_date = ptr->date;
                t_roomtype = ptr->roomtype;
                 //save date into current node
                 ptr->id=ptr->next->id;
                 ptr->name = ptr->next->name;
                 ptr->date = ptr->next->date;
                 ptr->roomtype= ptr->next->roomtype;
                 // save data into next node
                 ptr->next->id = t_id;
                 ptr->next->name = t_name;
                 ptr->next->date = t_date;
                 ptr->next->roomtype = t_roomtype;
             }

         }
     }
 }
int main()
{
      Hotel h;
      h.menu();

    return 0;
}