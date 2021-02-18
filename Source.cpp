#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "cstdio"
#include "cstring"


int atoi_(char *my_string) {
    int numar = 0;
    for (int i = 0; my_string[i]; ++i)
        numar = numar * 10 + (my_string[i] - '0');
    return numar;
}
void problema_1() {
    //FILE* file_1 = fopen("in.text", "r");
    FILE* file_1;
    fopen_s(&file_1, "in.txt", "r");
    int rezultat = 0;
    char my_string[50]{};
    while (fgets(my_string, 50, file_1)) {
        my_string[strlen(my_string) - 1] = '\0';
        int numar = atoi_(my_string);
        rezultat += numar;
    }
    printf_s("%d\n", rezultat);
}
void problema_2() {
    char propozitie[200];
    scanf_s("%[^'\n']s", &propozitie, 200);
    char vector_de_cuvinte[20][20];
    int lungimea_vectorului = 0;
    char* p = strtok(propozitie, " ?.,;:");
    while (p != NULL) {
        strcpy(vector_de_cuvinte[lungimea_vectorului++], p);
        p = strtok(NULL, " ");
    }
    for(int i=0 ; i< lungimea_vectorului; ++i)
     for(int j=i+1 ; j<lungimea_vectorului; ++j)
         if (strlen(vector_de_cuvinte[i]) < strlen(vector_de_cuvinte[j])) {
             char aux[21];
             strcpy(aux, vector_de_cuvinte[i]);
             strcpy(vector_de_cuvinte[i], vector_de_cuvinte[j]);
             strcpy(vector_de_cuvinte[j], aux);
         }
         else if (strlen(vector_de_cuvinte[i]) == strlen(vector_de_cuvinte[j]) && strcmp(vector_de_cuvinte[i], vector_de_cuvinte[j]) > 0) {
             char aux[21];
             strcpy(aux, vector_de_cuvinte[i]);
             strcpy(vector_de_cuvinte[i], vector_de_cuvinte[j]);
             strcpy(vector_de_cuvinte[j], aux);
         }
    for (int i = 0; i < lungimea_vectorului; ++i)
        printf_s("%s\n", vector_de_cuvinte[i]);
}
bool isPrime(int n){
       for (int tr = 2; tr < n / 2; tr++) // aici am modificat
           if ((n % tr) == 0) // aici am modificat
               return false; // aici am modificat
       return true;
}
#include "iostream"
int __main(){

        int n;
        std::cout << "Enter a number:";
        std::cin >> n; // aici am modifica;
        if (isPrime(n))
            std::cout << n << " is prime !";
        else
            std::cout << n << " is NOT prime !";
        return 0;
}
int main() {
    problema_1();
    problema_2();
    return 0;
}
