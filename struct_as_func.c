#include <stdio.h>

struct Personal {
    char name[100];
    char address[200];
    int age;
    float weigh;
};

void printPersonal(
    struct Personal personal
){
    printf("-------------------------------\n");
    printf("Name: %s\n", personal.name);
    printf("Address: %s\n", personal.address);
    printf("Age: %d\n", personal.age);
    printf("Weigh: %.2f\n", personal.weigh);
}

void definePersonal(
    struct Personal personal,
    char name[100],
    char address[200],
    int age,
    float weigh
)
{
    strcpy(personal.name, name);
    strcpy(personal.address, address);
    personal.age = age;
    personal.weigh = weigh;
    printPersonal(personal);
}


int main(){

    struct Personal minhkma;
    struct Personal poisonous;

    definePersonal(minhkma, "Nguyen Van Minh", "Dong Hung, Thai Binh", 22, 59.5);
    definePersonal(poisonous, "Chang Yeu Ai", "Dong Hung, Thai Binh", 17, 44.5);

    printf("-------------------------------\n");
}

//output
//-------------------------------
//Name: Nguyen Van Minh
//Address: Dong Hung, Thai Binh
//Age: 22
//Weigh: 59.50
//-------------------------------
//Name: Chang Yeu Ai
//Address: Dong Hung, Thai Binh
//Age: 17
//Weigh: 44.50
//-------------------------------