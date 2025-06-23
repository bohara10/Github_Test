#include<iostream>
using namespace std;

template<typename t>
 class Stack{
  private :
  class node {
    public:
    t data ;
    node *next;
    

    node(){
    }

    node(t d){
      this->data=d;
    }
  };

  node *head;


public:
Stack(){
  this->head=NULL;
}

bool Isempty(){
  return head==NULL;
}


void push(){
  node *newnode = new node(getdata());
  if(!Isempty()){
    newnode->next=head;
  }
  head=newnode;
}

t pop(){
  if(Isempty()){
    throw std::underflow_error("Stack is empty. Pop operation cannot be performed.");
  }else{
    node *todel=head;
    head=head->next;
    t ret=todel->data;
    delete todel;
    return ret;
  }
}

void makeempty(){
  while(head!=NULL){
    node *del = head;
    head=head->next;
    delete del;
  }
}

t getdata(){
  t d;
  cout<<"Enter data : ";
  cin>>d;
  return d;

}

void display(){
  if(!Isempty()){
    node *temp = head;
    while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
  }
}
};

int main(){
  Stack<char> stack;

  cout<<"Menu"<<endl;
  cout<<"Press 1 to check empty"<<endl;
  cout<<"Press 2 to push data"<<endl;
  cout<<"Press 3 to pop data"<<endl;
  cout<<"Press 4 to make the stack empty"<<endl;
  cout<<"Press 5 to display the stack"<<endl;
  cout<<"Press any other key to exit"<<endl;
    int n=0;

  do{
    cout<<"Enter operation : ";
    cin>>n;
    switch ((n))
    {
    case 1:
    if(stack.Isempty()){
      cout<<"Stack is empty"<<endl;
    }else{
      cout<<"The stack isnot empty"<<endl;
    }
      break;

      case 2:
      stack.push();
      break;

case 3:
  try {
    cout << stack.pop() << " was removed." << endl;
  } catch (const std::underflow_error& e) {
    cout << e.what() << endl;
  }
  break;


      case 4:
      stack.makeempty();
      break;

      case 5:
      stack.display();
      break;

    
    default:
    n=6;
      break;
    }

  }while(n!=6);
return 0;
}