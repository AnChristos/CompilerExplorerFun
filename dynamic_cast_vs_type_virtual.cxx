/*
* Compare dynamic_cast vs 
* virtual call "switch"
*/

#include <iostream>
namespace Types{
enum type{
  derived1=1,
  derived2=2,
  derived3=3,
  derived4=4
};
}
class base{
public:
  base()=default;
  virtual ~base()=default;
  virtual int type()=0;
};

class derived1 :public base{
public:
  derived1()=default;
  virtual ~derived1()=default;
  virtual int type() {return Types::derived1;}
};
class derived2 :public base{
public:
  derived2()=default;
  virtual ~derived2()=default;
  virtual int type() {return Types::derived2;}
};

class derived3 :public base{
public:
  derived3()=default;
  virtual ~derived3()=default;
  virtual int type() {return Types::derived4;}
};

class derived4 :public base{
public:
  derived4()=default;
  virtual ~derived4()=default;
  virtual int type() {return Types::derived4;}
};




void test(base* b){

  derived1 *d1=dynamic_cast<derived1*> (b);
  if(d1){
    std::cout<<"d1 \n";
  }
  derived2 *d2=dynamic_cast<derived2*> (b);
  if(d2){
    std::cout<<"d2 \n";
  }
  derived3 *d3=dynamic_cast<derived3*> (b);
  if(d3){
    std::cout<<"d3 \n";
  }
  derived4 *d4=dynamic_cast<derived4*> (b);
  if(d4){
    std::cout<<"d4 \n";
  }
}


void test1(base* b){
  if(b->type()==Types::derived1){
    std::cout<<"d1 \n";
  }
  if(b->type()==Types::derived2){
    std::cout<<"d2 \n";
  }
  if(b->type()==Types::derived3){
    std::cout<<"d3 \n";
  }
  if(b->type()==Types::derived4){
    std::cout<<"d4 \n";
  }
}

int main(){

}
