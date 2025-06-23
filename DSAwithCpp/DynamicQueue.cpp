#include<iostream>
using namespace std;

class Queue{

private:
class node{
  public:
    int data;
    node *next;

    node (int value){
      this->data=value;
      this->next=NULL;
    }
};

node *head;
node *tail;


public:
Queue(){
  this->head=NULL;
  this->tail= NULL;
}

private:
int getdata(){
int d;
cout<<"Enter data : ";
cin>>d;
return d;
}

public:
bool checknull(){
  return head==NULL;
}
bool checkone(){
  return head==head->next;
}


public:
void Enqueue(){
  node *newnode = new node(getdata());
  if(checknull()){
    head=tail=newnode;
  }else{
    tail->next = newnode;
    tail = newnode;
  }
  tail->next = head;
}

int Dequeue(){
  if(checknull()){
    throw std::underflow_error("Queue is empty. Pop operation cannot be performed.");
  }else{
      node *todel = head;
       int toret = head->data;
    if(checkone()){
      head=tail=NULL;
    }else{
      head=head->next;
      tail->next=head;
    }
    delete todel;
  return toret;
  }
  return 1;
}


void display(){
  if(!checknull()){
    node *temp = head;
    do{
      cout<<temp->data<<" ";
      temp=temp->next;
    }while(temp!=head);
    cout<<endl;
  }
}
};
int main(){
  Queue stack;

  cout<<"Menu"<<endl;
  cout<<"Press 1 to check empty"<<endl;
  cout<<"Press 2 to Enqueue data"<<endl;
  cout<<"Press 3 to dequeue"<<endl;
  cout<<"Press 4 to display the queue"<<endl;
  cout<<"Press any other key to exit"<<endl;
    int n=0;

  do{
    cout<<"Enter operation : ";
    cin>>n;
    switch ((n))
    {
    case 1:
    if(stack.checknull()){
      cout<<"Queue is empty"<<endl;
    }else{
      cout<<"The Queue isnot empty"<<endl;
    }
      break;

      case 2:
      stack.Enqueue();
      break;

case 3:
  try {
    cout << stack.Dequeue() << " was removed." << endl;
  } catch (const std::underflow_error& e) {
    cout << e.what() << endl;
  }
  break;



      case 4:
      stack.display();
      break;

    
    default:
    n=5;
      break;
    }

  }while(n!=5);
return 0;
}