//lets code the node 

#include<iostream>
using namespace std;


class linkedlist{
  public :
  class node{
    public:
      int data;
      node *next;


      public:
      node(int value){
        //making the  constructor to intitialize the data
        this->data=value;
        this->next=nullptr;
      }

      void seenode(){
        cout<<data<<"   ";
      }
  };
  int datacount;
  node *head;

  linkedlist(){
    this->datacount=0;
    this->head=nullptr;
  }

    void makeempty(){
      cout<<"The destructor was called to destry"<<endl;
      while(head!=nullptr){
        node *temp=head;
        head=head->next;
        delete temp;
      }
  }

  int getdata(){
    int datum;
    cout<<"Enter data : ";
    cin>>datum;
    return datum;
  }

void Insertdatafrombegining(){
  node *newnode=new node(getdata());
  if(head==nullptr){
    head=newnode;
  }else{
    node *pointer=head;
    head=newnode;
    head->next=pointer;
  }
}

void Insertdataatlast(){
  node *thisnode=new node(getdata());
  if(head==nullptr){
    head=thisnode;
  }else{
  node *point=head;
  while(point->next!=nullptr){
    point=point->next;
  }
  point->next=thisnode;
  }
}

void enteratmiddle() {
    node *newnode = new node(getdata());
    cout << "Enter the position to enter the data: ";
    int position;
    cin >> position;
    if (position < 1) {
        cout << "Invalid position!" << endl;
        delete newnode; // Cleanup to avoid memory leak
        return;
    }
    node *temp = head;
    if (position == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        for (int i = 1; i < position - 1; ++i) { // Corrected loop to stop at the node before the desired position
            if (temp == nullptr || temp->next == nullptr) {
                cout << "The position does not exist" << endl;
                delete newnode; // Cleanup to avoid memory leak
                return;
            }
            temp = temp->next;
        }
        // Insert the new node after temp
        newnode->next = temp->next;
        temp->next = newnode;
    }
}


void deletefromtop(){
  node *del;
  if(head==nullptr){
    cout<<"no data to delete"<<endl;
  }else{
    del=head;
    head=head->next;
    delete del;
  }
}

void deletefromend(){
  if(head==nullptr){
    cout<<"No data to delete"<<endl;
  }else if(head->next==nullptr){
    head=nullptr;
  } else{

    node *letsgo=head;
    while(letsgo->next->next!=nullptr){
      letsgo=letsgo->next;
    }
    delete letsgo->next;
    letsgo->next=nullptr;
  }
}

void positiondel(){
  cout<<"Enter the position that you want to delete : "<<endl;
  int postion;
  cin>>postion;
  node *temp=head;
  if(postion<1){
    cout<<"Cannot delete the data"<<endl;
    return;
  }else if(postion==1){
    deletefromtop();
  }else{
    for(int i=1;i<(postion-1);++i){
      if(temp->next==nullptr){
        cout<<"Cannot delete the data";
        return;
      }else{
        temp=temp->next;
      }
    }
      node *todel=temp->next;
      temp->next=temp->next->next;
      cout<<todel->data<<" was deleted"<<endl;
      delete todel;
  
  }
}

void display(){
  if(head==nullptr){
    cout<<"no data to display"<<endl;
  }else{
  node *dis=head;
  while(dis!=nullptr){
    dis->seenode();
    dis=dis->next;
  }
}
}

};


int main(){
  linkedlist l;
  l.Insertdatafrombegining();
  l.Insertdatafrombegining();
  l.Insertdatafrombegining();
  l.Insertdataatlast();
  l.Insertdataatlast();
  l.display();
  l.enteratmiddle();
  l.display();
  l.positiondel();
  l.display();
  return 0;
}