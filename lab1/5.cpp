#include <iostream>
#include <stdio.h>
#include <math.h>

class B
{
  public:
    virtual int prva() = 0;
    virtual int druga() = 0;
};

class D : public B
{
  public:
    virtual int prva() { return 0; }
    virtual int druga() { return 42; }
};

typedef int (*funptr)();

void ispis(B *obj){
    funptr* vtable =  *(funptr**)obj;
    printf("prva = %d\ndruga = %d\n", ((funptr)(vtable[0]))(), ((funptr)(vtable[1]))() );
}

int main(){
    B *pb = new D;
    ispis(pb);
}