#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zapiszDoPliku(int *tablica, int rozmiar, char *nazwaPliku) {
    FILE *plik = fopen(nazwaPliku, "w");
    if (plik == NULL) {
        printf("Nie można otworzyć pliku do zapisu.\n");
        return;
    }

    for (int i = 0; i < rozmiar; i++) {
        fprintf(plik, "%d ", tablica[i]);
    }

    fclose(plik);
}

int main() {
    int i, aSize = 10;
    int *randomNums;
    time_t t;
    double total = 0;
    int biggest, smallest;
    float average;
    srand(time(&t));
    char wybor;

    do {
        printf("Ile liczb losowych chcesz zapisac w tablicy? ");
        scanf("%d", &aSize);

        // Sprawdzenie czy rozmiar tablicy jest dodatni
        if (aSize <= 0) {
            printf("Rozmiar tablicy musi byc dodatni.\n");
            continue;
        }

        // Alokacja tablicy na odpowiednią liczbę liczb całkowitych
        randomNums = (int *) malloc(aSize * sizeof(int));
        if (!randomNums) {
            printf("Nie udało się alokować tablicy!\n");
            exit(1);
        }

        // Generowanie losowych liczb i przypisanie ich do tablicy
        for (i = 0; i < aSize; i++) {
            randomNums[i] = (rand() % 500) + 1;
        }

        // Wyświetlanie zawartości tablicy
        printf("Tablica %d-elementowa:\n", aSize);
        for (i = 0; i < aSize; i++) {
            printf("%d ", randomNums[i]);
        }
        printf("\n");

        // Modyfikacja pojedynczego elementu tablicy
        int index, newValue;
        printf("Podaj indeks elementu, ktory chcesz zmodyfikowac (od 0 do %d): ", aSize - 1);
        scanf("%d", &index);
        if (index < 0 || index >= aSize) {
            printf("Podano nieprawidłowy indeks.\n");
            free(randomNums);
            continue;
        }
        printf("Podaj nowa wartosc dla indeksu %d: ", index);
        scanf("%d", &newValue);
        randomNums[index] = newValue;

        // Wyświetlanie zawartości tablicy po zmianie
        printf("Tablica %d-elementowa:\n", aSize);
        for (i = 0; i < aSize; i++) {
            printf("%d ", randomNums[i]);
        }
        printf("\n");

        // Znajdowanie największej i najmniejszej liczby oraz obliczanie sumy
        biggest = randomNums[0];
        smallest = randomNums[0];
        for (i = 0; i < aSize; i++) {
            total += randomNums[i];
            if (randomNums[i] > biggest) {
                biggest = randomNums[i];
            }
            if (randomNums[i] < smallest) {
                smallest = randomNums[i];
            }
        }

        // Obliczanie średniej
        average = ((float) total) / ((float) aSize);

        // Wyświetlanie wyników
        printf("Najwieksza liczba: %d.\n", biggest);
        printf("Najmniejsza liczba: %d.\n", smallest);
        printf("Srednia: %.2f.\n", average);

        // Zwolnienie pamięci
        free(randomNums);

        printf("Czy chcesz kontynuowac (T/N)? ");
        scanf(" %c", &wybor);
    } while (wybor == 'T' || wybor == 't');

    return 0;
}
