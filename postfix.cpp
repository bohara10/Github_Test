#include<iostream>
#include<cstring>
using namespace std;

class datain{
  public :
  int count,sount;
  char input[20],scan[20],opcode[20];
  
  datain(){
    this->count=-1;
    this->sount=-1;
  }
  int checkalphabet(char z){
    if((z>='a'&&z<='z')||(z>='A'&&z<='Z')) return 1;
    else return 0;
}

 void pop(){
    ++count;
    scan[count]=opcode[sount-1];
    opcode[sount-1]=opcode[sount];
    --sount;
  }
    void evaluate(){
    if(opcode[sount-1]=='&'){
      if(opcode[sount]=='-'||opcode[sount]=='+'||opcode[sount]=='*'||opcode[sount]=='/'){
        pop();
      }
    }
    else if(opcode[sount-1]=='/'||opcode[sount-1]=='*'){
      if(opcode[sount]=='+'||opcode[sount]=='-'){
        pop();
      }
    }
  }



  void push(){
    ++count;
    scan[count]=opcode[sount];
    --sount;
  }

  void getinput(){
    cout<<"Enter the given operation below : ";
    cin>>input;
  }

  void getdifferentdata(){
    for(int i=0;i<strlen(input);++i){
      if(checkalphabet(input[i])){
        ++count;
        scan[count]=input[i];
      }
      else{
        ++sount;
        opcode[sount]=input[i];
        if(sount>0){
          evaluate();
        }
        if(opcode[sount]==')'){
          sount--;
          while(opcode[sount]!='('){
            push();
          }
          --sount;
        }
      }
    }
   while(sount>-1){
      push();
      }}

  void seeopcode(){
    cout<<"The opcodes are :"<<endl;
    for(int i=0;i<=sount;++i){
      cout<<opcode[i]<<endl;
    }}

  void seescaned(){
    cout<<"The Scanned characters are :"<<endl;
    for(int i=0;i<=count;++i){
      cout<<scan[i];
    }cout<<endl;
  }
};

int main(){
  datain d1;
  d1.getinput();
  d1.getdifferentdata();
  d1.seescaned();
  return 0;
}