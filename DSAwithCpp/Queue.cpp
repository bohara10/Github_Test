#include<iostream>
using namespace std;

#define max 10


class Queue{
  private:
  int rear;
  int front;
  int data[max];

  public:
  Queue(){
    this->front=0;
    this->rear=-1;
  }


  protected:
  int getdata(){
    cout<<"enter data : ";
    int k;
    cin>>k;
    return k;
  }


  void makeempty(){
    front=0;
    rear=-1;
  }

  bool checkEmpty(){
    return front==0&&rear==-1;
  }

  bool checkFull(){
    return rear==max-1;
  }

  void Enqueue(int val){
    if(!checkFull()){
      ++rear;
      data[rear]=val;
    }
  }


  int dequeue(){
    int toret = 0;
    if(!checkEmpty()){
      toret=data[front];
      ++front;
    }
    return toret;
  }


  void traverse(){
    for(int i = front ; i <=rear;++i){
      cout<<data[i]<<" ";
    }
    cout<<endl;
  }

      public:
    void menu(){
      int n;
        cout<<"Menu"<<endl;
        cout<<"Press 1 to Make the Stack empty"<<endl;
        cout<<"Press 2 to check the Stack is empty"<<endl;
        cout<<"Press 3 to check the Stack if full "<<endl;
        cout<<"Press 4 to insert data in the Stack"<<endl;
        cout<<"Press 5 to delete a certain data"<<endl;
        cout<<"Press 6 to see the data "<<endl;
        cout<<"Press 7 to exit the menu"<<endl;

        do{
        cout<<"Enter operation : ";
        cin>>n;
        switch (n)
        {
        case 1:
          makeempty();
          break;


          case 2:
          if(checkEmpty()){
            cout<<"The Stack is empty"<<endl;
          }else{
            cout<<"The Stack is not empty"<<endl;
          }


          break;

          case 3:
          if(checkFull()){
            cout<<"The stack is full"<<endl;
          }else{
            cout<<"The stack is not full"<<endl;
          }
          break;


          case 4:
      int k;
      Enqueue(getdata());
      break;

      case 5:
      cout<<dequeue()<<" was deleted"<<endl;
      break;
      break;

      case 6:
      traverse();
      break;
      
      
        
        default:
        n=7;
          break;
        }
      }while(n!=7);

    }
  };
  
int main(){
   Queue integerstack;
  integerstack.menu();
  return 0;
}
