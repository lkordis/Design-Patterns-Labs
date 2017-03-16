#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef char const *(*PTRFUN)();

/*
    Razred Animal
*/

struct Animal
{
    PTRFUN *vtable;
    char const *ime;
};

PTRFUN AnimalVTable[2] = {
    NULL,
    NULL};

void animalPrintGreeting(struct Animal *a)
{
    printf("%s pozdravlja: %s\n", a->ime, ((PTRFUN)a->vtable[0])());
}

void animalPrintMenu(struct Animal *a)
{
    printf("%s voli: %s\n", a->ime, ((PTRFUN)a->vtable[1])());
}

void AnimalInit(struct Animal *obj, char const *c)
{
    obj->vtable = AnimalVTable;
    obj->ime = c;
}

/*
    Razred Dog
*/

typedef struct
{
    PTRFUN *vtable;
    char const *ime;
} Dog;

char const *dogGreet(void)
{
    return "vau!";
}
char const *dogMenu(void)
{
    return "kuhanu govedinu";
}

PTRFUN DogVTable[2] = {
    dogGreet,
    dogMenu};

struct Animal *constructDog(Dog *obj, char const *c)
{
    AnimalInit((struct Animal *)obj, c);
    obj->vtable = DogVTable;
    obj->ime = c;

    return (struct Animal *)obj;
}

struct Animal *createDog(char const *ime)
{
    struct Animal *animal = (struct Animal *)malloc(
        sizeof(Dog));

    return constructDog(animal, ime);
}

struct Animal **createSleigh(int n)
{
    struct Animal **a = (struct Animal **)malloc(sizeof(struct Animal *) * n);

    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = createDog("Saonica");
    }

    return a;
}

/*
    Razred Cat
*/

typedef struct
{
    PTRFUN *vtable;
    char const *ime;
} Cat;

char const *catGreet(void)
{
    return "mijau!";
}
char const *catMenu(void)
{
    return "konzerviranu tunjevinu";
}

PTRFUN CatVTable[2] = {
    catGreet,
    catMenu};

struct Animal *constructCat(Cat *obj, char const *c)
{
    AnimalInit((struct Animal *)obj, c);
    obj->vtable = CatVTable;
    obj->ime = c;

    return (struct Animal *)obj;
}

struct Animal *createCat(char const *ime)
{
    struct Animal *animal = (struct Animal *)malloc(
        sizeof(Cat));

    return constructCat(animal, ime);
}

void testAnimals(void)
{
    struct Animal *p1 = createDog("Hamlet");
    struct Animal *p2 = createCat("Ofelija");
    struct Animal *p3 = createDog("Polonije");

    struct Animal **p4 = createSleigh(4);

    animalPrintGreeting(p1);
    animalPrintGreeting(p2);
    animalPrintGreeting(p3);

    animalPrintMenu(p1);
    animalPrintMenu(p2);
    animalPrintMenu(p3);

    int i;
    for (i = 0; i < 4; i++)
    {
        animalPrintGreeting(p4[i]);
    }

    free(p1);
    free(p2);
    free(p3);

    for (i = 0; i < 4; i++)
    {
        free(p4[i]);
    }
    free(p4);
}

int main()
{
    testAnimals();

    return 0;
}