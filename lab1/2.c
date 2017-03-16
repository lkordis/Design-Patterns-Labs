#include <stdio.h>
#include <stdlib.h>

/*
    Razred Unary_Function
*/

typedef void (*dflt_ptr)(void);

typedef struct
{
    dflt_ptr *vtable;
    int lower_bound;
    int upper_bound;
} Unary_Function;


typedef double (*funptr)(Unary_Function*, double);

double Unary_FunctionGetLb(Unary_Function* obj){
    return obj->lower_bound;
}

double Unary_FunctionGetUb(Unary_Function* obj){
    return obj->upper_bound;
}

int Unary_Function_same_functions_for_inits(Unary_Function *f1, Unary_Function *f2, double tolerance)
{
    if (Unary_FunctionGetLb(f1) != Unary_FunctionGetLb(f2))
        return 0;
    if (Unary_FunctionGetUb(f1) != Unary_FunctionGetUb(f2))
        return 0;

    for (int x = Unary_FunctionGetLb(f1); x <= Unary_FunctionGetUb(f1); x++)
    {
        double delta = ((funptr)f1->vtable[0])(f1,x) - ((funptr)f2->vtable[0])(f2,x);
        if (delta < 0)
            delta = -delta;
        if (delta > tolerance)
            return 0;
    }
    return 1;
}

double negative_value_at(Unary_Function* obj, double x){
    return -((funptr)obj->vtable[0])(obj,x);
}

void Unary_FunctionTabulate(Unary_Function *obj) {
    int x = obj->lower_bound;
    funptr pfun = (funptr)obj->vtable[0];
    for(x; x <= obj->upper_bound; x++){
        printf("f(%d)=%lf\n", x, pfun(obj, x));
    }
}

dflt_ptr Unary_FunctionVTable[2] = {
    NULL,
    (dflt_ptr) negative_value_at
};

void Unary_FunctionInit(Unary_Function* obj, int lb, int ub){
    obj->vtable = Unary_FunctionVTable;
    obj->upper_bound = ub;
    obj->lower_bound = lb;
}

/*
    Razred Square
*/

typedef struct
{
    dflt_ptr *vtable;
} Square;

double SquareValue_at(Square* obj,double x) {
    return x*x;
}

dflt_ptr SquareVTable[2] = {
    (dflt_ptr)SquareValue_at,
    (dflt_ptr)negative_value_at
};

void SquareInit(Square* obj, int lb, int ub){
    Unary_FunctionInit((Unary_Function*)obj,lb,ub);
    obj->vtable = SquareVTable;
}

Unary_Function* newSquare(int lb, int ub){
    Unary_Function* obj = (Unary_Function*) malloc(sizeof(Square));
    SquareInit((Square*)obj,lb,ub);

    return obj;
}

/*
    Razred Linear
*/

typedef struct
{
    dflt_ptr *vtable;
    int lower_bound;
	int upper_bound;
	double a;
	double b;
} Linear;

double LinearValue_at(Linear* obj,double x) {
    return obj->a * x + obj->b;
}

dflt_ptr LinearVTable[2] = {
    (dflt_ptr)LinearValue_at,
    (dflt_ptr)negative_value_at
};

void LinearInit(Linear* obj, int lb, int ub, double a_coeff, double b_coeff){
    Unary_FunctionInit((Unary_Function*)obj,lb,ub);
    obj->vtable = LinearVTable;
    obj->a = a_coeff;
    obj->b = b_coeff;
}

Unary_Function* newLinear(int lb, int ub, double a_coeff, double b_coeff){
    Unary_Function* obj = (Unary_Function*) malloc(sizeof(Linear));
    LinearInit((Linear*)obj,lb,ub,a_coeff,b_coeff);

    return obj;
}

int main(){
    Unary_Function* f1 = newSquare(-2,2);
    Unary_FunctionTabulate(f1);

    Unary_Function* f2 = newLinear(-2,2,5,-2);
    Unary_FunctionTabulate(f2);

    printf("f1==f2: %s\n", Unary_Function_same_functions_for_inits(f1,f2,1E-6) ? "DA" : "NE");
    printf("neg_val f2(1) = %lf\n", ((funptr)f2->vtable[1])(f2,1.0));

    free(f1); free(f2);
    return 0;
}