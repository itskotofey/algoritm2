#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

FILE* file;

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, long int left, long int right) //вызов функции: qs(items, 0, count-1);
{
    long int i, j;
    long int x, y;

    i = left; j = right;

    /* выбор компаранда */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

int compare(const void* x1, const void* x2)
{
    return (*(int*)x1 - *(int*)x2);
}

void Program(int n) {

    int* arr11 = (int*)malloc(n * sizeof(int));
    int* arr12 = (int*)malloc(n * sizeof(int));
    int* arr13 = (int*)malloc(n * sizeof(int));
    int* arr21 = (int*)malloc(n * sizeof(int));
    int* arr22 = (int*)malloc(n * sizeof(int));
    int* arr23 = (int*)malloc(n * sizeof(int));
    int* arr31 = (int*)malloc(n * sizeof(int));
    int* arr32 = (int*)malloc(n * sizeof(int));
    int* arr33 = (int*)malloc(n * sizeof(int));
    int* arr41 = (int*)malloc(n * sizeof(int));
    int* arr42 = (int*)malloc(n * sizeof(int));
    int* arr43 = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        arr11[i] = 10 + rand() % 90;
        arr12[i] = 10 + rand() % 90;
        arr13[i] = 10 + rand() % 90;
    }

    for (int i = 0; i < n; i++)
    {
        arr21[i] = i + 1;
        arr22[i] = i + 1;
        arr23[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr31[i] = n - i;
        arr32[i] = n - i;
        arr33[i] = n - i;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2) {
            arr41[i] = i + 1;
            arr42[i] = i + 1;
            arr43[i] = i + 1;
        }
        else {
            arr41[i] = n - i;
            arr42[i] = n - i;
            arr43[i] = n - i;
        }


    }

    fprintf(file, "Кол-во элементов: %d", n);


    ///////////////////////////////////
    fprintf(file, "\n\nЗаполение массива 1 сопособом: рандом\n");
    double time1 = clock();
    shell(arr11, n);
    double time2 = clock();
    fprintf(file, "\nСортировка Shell: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qs(arr12, 0, n - 1);
    time2 = clock();
    fprintf(file, "\nСортировка qs: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qsort(arr13, n, sizeof(int), compare);
    time2 = clock();
    fprintf(file, "\nСортировка qsors: %lf", (time2 - time1) / CLOCKS_PER_SEC);
    //////////////////////////////////////
    fprintf(file, "\n\nЗаполение массива 2 сопособом: по возрастанию\n");
    time1 = clock();
    shell(arr21, n);
    time2 = clock();
    fprintf(file, "\nСортировка Shell: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qs(arr22, 0, n - 1);
    time2 = clock();
    fprintf(file, "\nСортировка qs: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qsort(arr23, n, sizeof(int), compare);
    time2 = clock();
    fprintf(file, "\nСортировка qsors: %lf", (time2 - time1) / CLOCKS_PER_SEC);
    ////////////////////////////////////// 
    fprintf(file, "\n\nЗаполение массива 3 сопособом: по убыванию\n");
    time1 = clock();
    shell(arr31, n);
    time2 = clock();
    fprintf(file, "\nСортировка Shell: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qs(arr32, 0, n - 1);
    time2 = clock();
    fprintf(file, "\nСортировка qs: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qsort(arr33, n, sizeof(int), compare);
    time2 = clock();
    fprintf(file, "\nСортировка qsors: %lf", (time2 - time1) / CLOCKS_PER_SEC);
    //////////////////////////////////////
    fprintf(file, "\n\nЗаполение массива 4 сопособом: возрастие/убывание\n");
    time1 = clock();
    shell(arr41, n);
    time2 = clock();
    fprintf(file, "\nСортировка Shell: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qs(arr42, 0, n - 1);
    time2 = clock();
    fprintf(file, "\nСортировка qs: %lf", (time2 - time1) / CLOCKS_PER_SEC);

    time1 = clock();
    qsort(arr43, n, sizeof(int), compare);
    time2 = clock();
    fprintf(file, "\nСортировка qsors: %lf", (time2 - time1) / CLOCKS_PER_SEC);
    ////////////////////////////////////// 
    fprintf(file, "\n\n\n");
    free(arr11); free(arr12); free(arr13);
    free(arr21); free(arr22); free(arr23);
    free(arr31); free(arr32); free(arr33);
    free(arr41); free(arr42); free(arr43);

}

int main(void)
{
    fopen_s(&file, "txt.txt", "w");
    setlocale(0, "");

    Program(100);
    Program(200);
    Program(400);
    Program(1000);
    Program(2000);
    Program(4000);

    printf("Результат записан в файл\n");

    fclose(file);
    system("pause");
    return 0;
}