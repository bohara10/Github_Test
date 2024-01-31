#include<iostream>
#include<cstring>
using namespace std;

class datain{
  public :
  int count,sount;
  char input[20],scan[20],opcode[20],revinp[20],revopcode[20];
  
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
    }else if(opcode[sount-1]=='/'){
      if(opcode[sount]=='+'||opcode[sount]=='-'||opcode[sount-1]=='*'){
        pop();
      }
    } else if(opcode[sount-1]=='*'){
      if(opcode[sount]=='+'||opcode[sount]=='-'){
        pop();
      }
    }else if(opcode[sount-1]=='+'){
        if(opcode[sount]=='-'){
          pop();
        }
      }
    }

  void push(){
    ++count;
    scan[count]=opcode[sount];
    --sount;
  }

   void getinput() {
        cout << "Enter the given operation below: ";
        cin>>revinp;
      for(int i=0;i<strlen(revinp);++i){
          input[strlen(revinp)-i-1]=revinp[i];
      }
      for(int i=0;i<strlen(input);++i){
        if(input[i]=='('){
          input[i]=')';
        }else if(input[i]==')'){
          input[i]='(';
        }
      }
    }

    void seeoutput(){
      cout<<"The data is "<<input<<endl;
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
      }
  }

  void seeopcode(){
    cout<<"The opcodes are :"<<endl;
    cout<<opcode<<endl;
  }

  void seescaned(){
    cout<<"The prefix of the given operation is :";
    for(int i=0;i<=count;++i){
      revopcode[count-i]=scan[i];
    }
    for(int i=0;i<=count;++i){
    cout<<revopcode[i];
  }
    cout<<endl;
  }
};

int main(){
  datain d1;
  d1.getinput();
  d1.seeoutput();
  d1.getdifferentdata();
  d1.seescaned();
  return 0;
}