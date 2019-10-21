#include <stdio.h>

struct personal {
    char name[100];
    char address[200];
    int age;
    float weigh;
};

int main() {
    struct personal minhkma;

    strcpy(minhkma.name, "Nguyen Van Minh");
    strcpy(minhkma.address, "Dong Hung, Thai Binh");
    minhkma.age = 22;
    minhkma.weigh = 59.58;

    printf("-------------------------------\n");
    printf("Name: %s\n", minhkma.name);
    printf("Address: %s\n", minhkma.address);
    printf("Age: %d\n", minhkma.age);
    printf("Weigh: %.2f\n", minhkma.weigh);

    struct personal poisonous;

    strcpy(poisonous.name, "Chang Yeu Ai");
    strcpy(poisonous.address, "Dong Hung, Thai Binh");
    poisonous.age = 17;
    poisonous.weigh = 45.5;

    printf("-------------------------------\n");
    printf("Name: %s\n", poisonous.name);
    printf("Address: %s\n", poisonous.address);
    printf("Age: %d\n", poisonous.age);
    printf("Weigh: %.2f\n", poisonous.weigh);

    printf("-------------------------------\n");
}


//output
//-------------------------------
//Name: Nguyen Van Minh
//Address: Dong Hung, Thai Binh
//Age: 22
//Weigh: 59.58
//-------------------------------
//Name: Chang Yeu Ai
//Address: Dong Hung, Thai Binh
//Age: 17
//Weigh: 45.50
//-------------------------------
