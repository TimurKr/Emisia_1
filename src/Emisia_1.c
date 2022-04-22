//
// Created by Timur Kramar on 17/04/2022.
//

#include "stdio.h"

unsigned int uholnik_roztaty_priamkou_pocet_komponent(
        const float *x, const float *y, unsigned int l, float a, float b, float c) {

    #define ALMOST_ZERO 0.0000000001

    int prienik_counter = 0;            // počítadlo, koľko krát prenikne priamka cez okraj uholnika
    unsigned short int last_pos;        // -1 => pod priemkou, 1 => nad priamkov, 0 => na priamke
    unsigned short int new_pos;

            // Zisti polohu posledného bodu ku priamke
    float diff = y[l-1] - (float) - (a*x[l-1] + c) / (float) b;
    if (diff > ALMOST_ZERO) {
        last_pos = 1;
    } else if (diff < - ALMOST_ZERO) {
        last_pos = -1;
    }

    for (int i = 0; i < l; i++) {
                // Zisti polohu i-teho bodu ku priamke
        diff = y[i] - (float) - (a*x[i] + c) / (float) b;
        if (diff > ALMOST_ZERO) {
            new_pos = 1;
        } else if (diff < - ALMOST_ZERO) {
            new_pos = -1;
        }

                // Zisti, či sa zmenila poloha, ak hej, musel byť prienik
        if (new_pos != last_pos && new_pos != 0 && last_pos != 0) {
            prienik_counter++;
        }

        last_pos = new_pos;
    }

    // Ak náhodou prvý aj posledný leží na priamke, nájdeme o jeden prienik menej, preto + 1,
    // to nezmení výsledok celočíselného delenia, následne + 1, lebo jedna časť je už na začiatku a
    // každé 2 prieseky vytvoria novú
    return (prienik_counter+1)/2 + 1;
}

int main(void) {
    float x[5] = {3.4,4.75,4,3,1};
    float y[5] = {1,2.14,3.7,2.1,0.7};
    float a, b, c;
    a = -0.7;
    b = 1;
    c = 0;
    unsigned int n = uholnik_roztaty_priamkou_pocet_komponent(x,y,5,a,b,c);
    printf("\n\nUholnik bol rozdelený na %d častí.\n\n", n);
}
