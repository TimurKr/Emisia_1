//
// Created by Timur Kramar on 17/04/2022.
//

#include "stdio.h"

unsigned int uholnik_roztaty_priamkou_pocet_komponent(
        const float *x, const float *y, unsigned int l, float a, float b, float c) {

    int prienik_counter = 0;                // počítadlo, koľko krát prenikne priamka cez okraj uholnika
    unsigned short int last_pos = 0;        // -1 => pod priemkou, 1 => nad priamkov, 0 => na priamke
    unsigned short int new_pos = 0;

            // Zisti polohu posledného bodu ku priamke
    float diff = y[l-1] - (float) - (a*x[l-1] + c) / (float) b;
    if (diff > 0) {
        last_pos = 1;
        printf("Poloha -1-veho je nad priamkou\n");
    } else if (diff < 0) {
        last_pos = -1;
        printf("Poloha -1-veho je pod priamkou\n");
    } else {
        last_pos = 0;
        printf("Poloha -1-veho je na priamke\n");
    }

    for (int i = 0; i < l; i++) {
                // Zisti polohu i-teho bodu ku priamke
        diff = y[i] - (float) - (a*x[i] + c) / (float) b;
        if (diff > 0) {
            new_pos = 1;
            printf("Poloha %d-teho je nad priamkou\n", i);
        } else if (diff < 0) {
            new_pos = -1;
            printf("Poloha %d-teho je pod priamkou\n", i);
        } else {
            new_pos = 0;
            printf("Poloha %d-teho je na priamke\n", i);
        }

                // Zisti, či sa zmenila poloha, ak hej, musel byť prienik
        if (new_pos != 0 && last_pos != 0 && new_pos != last_pos) {
            printf("Medzi bodom %d a %d je prienik\n", i-1, i);
            prienik_counter++;
        }
        last_pos = new_pos;
    }
    return prienik_counter;
}

int main(void) {
    float x[5] = {1,3.4,4.75,4,3};
    float y[5] = {0.7,1,2.14,3.7,1.7};
    float a, b, c;
    a = -0.7;
    b = 1;
    c = 0;
    unsigned int n = uholnik_roztaty_priamkou_pocet_komponent(x,y,5,a,b,c);
    printf("\n\nNašli sme %d prienikov, to znamená, že uholnik bol rozdelený na %d častí.\n\n", n, n/2+1);
}
