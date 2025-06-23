#include<iostream>
using namespace std;
#define max 4

class list{
  int count;
  int data[max];

  public:
  list(){
    this->count=-1;
  }

  bool checkfull(){
    if(count==max-1){
    cout<<"The data is full"<<endl;
    return true;
  }else return false;
}

bool checkmep(){
  if(count==-1){
    cout<<"The data is empty"<<endl;
    return true;
  }else return false;
}


void makeempty(){
  count=-1;
}

  void insert(){
    if(!checkfull()){
    ++count;
    cout<<"Enter data : ";
    cin>>data[count];
  }
  }

  void deletedata(){
    int pos;
    cout<<"Insert the data postion ."<<endl;
    cin>>pos;
    if(checkmep()||pos>=max){
      cout<<"Error"<<endl;
    }else{
      --count;
      for(int i=(pos-1);i<max-1;++i){
        data[i]=data[i+1];
      }
    }
  }

  void display(){
    if(!checkmep()){
      for(int i=0;i<=count;++i){
        cout<<data[i]<<" ";
      }
    }
    cout<<endl;
  }

};

int main(){
  cout<<"Menu"<<endl;
  cout<<"Press 1 to checkempty data"<<endl;
  cout<<"Press 2 to checkfull "<<endl;
  cout<<"Press 3 to checkfull"<<endl;
  cout<<"Press 4 to insert data"<<endl;
  cout<<"Press 5 to delete data"<<endl;
  cout<<"Press 6 to show data"<<endl;
  int n;
  list l;
  do{
    cin>>n;
    switch (n)
    {
    case 1:
      l.checkmep();
      break;

      case 2:
      l.checkfull();
      break;

      case 3:
      l.makeempty();
      break;

      case 4:
      l.insert();
      break;

      case 5:
      l.deletedata();
      break;

      case 6:
      l.display();
      break;

      default :
      n=7;
      break;
    }
  }while(n!=7);
  return 0;
}