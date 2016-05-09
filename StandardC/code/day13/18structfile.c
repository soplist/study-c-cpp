#include <stdio.h>
typedef struct {
    unsigned short age;
    float height;
    float weight;
} Person;

int main() {
    Person persons[3] = {{21, 1.78, 73.6}, {19, 1.65, 49}, {70, 1.67, 80}};
    Person person;
    FILE *pFile = NULL;
    pFile = fopen("d.dat", "wb");
    if (NULL != pFile) {
        fwrite(persons, sizeof(Person), 3, pFile);
        fclose(pFile);
        pFile = NULL;
    }
    else {
        printf("写文件失败\n");
        return 0;
    }
    pFile = fopen("d.dat", "rb");
    if (NULL != pFile) {
        fseek(pFile, sizeof(Person), SEEK_SET);
        fread(&person, sizeof(Person), 1, pFile);
        fclose(pFile);
        pFile = NULL;
        printf("年龄是%hu\n", person.age);
        printf("身高是%f\n", person.height);
        printf("体重是%f\n", person.weight);
    }
    return 0;
}




