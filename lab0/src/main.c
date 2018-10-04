#include <stdio.h>                        //    *|     NSU FIT     |*
#include <string.h>                       //    *|      LAB_0      |*
#include <math.h>                         //    *| by Mateyuk_Ilya |*
#include <stdlib.h>                       //    *|     _18212_     |*

#define ULL unsigned long long
static char SSS[16] = "0123456789ABCDEF";

void test(int point, int lenght, int a, int b, char *str) {
    int exit0, exit1, exit2, exit3, exit4 = 0;
    for (int i = 0; i < lenght; ++i) {
        if ((int) str[i] >= 97) str[i] -= 32;                           // Поднимаем буквы в в. регистр
        exit0 = ((a < 2) || (b < 2) || (a > 16) || (b > 16));
        exit1 = (str[0] == '.') || (str[lenght - 1] == '.');
        exit2 = (strchr(SSS, str[i]) == NULL) && (i != point);          // Недопустимый символ
        exit3 = (int) (strchr(SSS, str[i]) - SSS) >= a;                 // Если цифра >= основанию
        exit4 = (str[0] == '0') && (str[1] != '.') && (lenght > 1);     // Есть лишний ноль в начале
        if (exit0 || exit1 || exit2 || exit3 || exit4) {
            printf("bad input");
            exit(EXIT_SUCCESS);
        }
    }
}

double aTo10(int point, int lenght, int a, char *str) {             // Перевод из a-той в 10 систему счисления
    double res = 0;
    int z;
    if (point == 0)
        point = lenght;
    for (int i = 0; i < point; ++i) {                               // Считаем целую часть
        z = (int) (strchr(SSS, str[i]) - SSS);                      // Берем очередное число из строки
        res += z * pow(a, point - i - 1);
    }
    for (int i = point + 1; i < lenght; ++i) {                      // Считаем дробную часть, если есть точка
        z = (int) (strchr(SSS, str[i]) - SSS);
        res += z * pow(a, -(i - point));
    }
    return res;
}

void dec2b_int(ULL dec, int b, char *str_b_int) {                   // Целая часть из 10 в b-ричную
    char symb[48] = {0};
    if (dec == 0) str_b_int[0] = '0';
    while (dec > 0) {
        symb[0] = *(SSS + (dec % b));
        dec = dec / b;
        strcat(symb, str_b_int);                                    // Берем символ и приписываем к нему строку
        strcpy(str_b_int, symb);                                    // справа, свапаем строки, нулим строку
        memset(symb, 0, sizeof(symb));                              // с символом
    }
}

void dec2b_frac(double dec, int b, char *s) {                       // Перевод дробной части в b-ричную

    char symb;
    s = s + 1;
    double p = 0;
    for (int i = 0; i < 12; ++i) {                                  // Находим 12 символов после точки
        p = dec * b;
        symb = *((ULL) p + SSS);
        dec = p - (ULL) p;
        *s = symb;
        ++s;
    }
}

void cls_0(char *str_b_frac) {
    for (int i = 12; i >= 2; --i) {
        if (str_b_frac[i] == '0') str_b_frac[i] = '\0';             // Убирает лишние нули
        else break;
    }
}


int main() {
    int a, b;                                                       // Из а-тичной в b-ричную
    double result_10;
    char str_in[14] = {0}, str_b_int[50] = {0}, str_b_frac[14] = {'.', 0};
    scanf("%d%d", &a, &b);
    scanf("%s", str_in);
    int lenght = strlen(str_in);
    int point = (int) (strchr(str_in, '.') - str_in);               // Номер точки в строке
    if (strchr(str_in, '.') == NULL)
        point = 0;
    test(point, lenght, a, b, str_in);
    result_10 = aTo10(point, lenght, a, str_in);                    // Число в 10
    dec2b_int((ULL) result_10, b, str_b_int);                       // Целое в b-ричной

    if (point != 0) {
        result_10 = result_10 - (ULL) result_10;
        dec2b_frac(result_10, b, str_b_frac);                       // Дробная часть в b-ричной
        cls_0(str_b_frac);                                          // Убираем лишние нолики
        strcat(str_b_int, str_b_frac);
    }
    printf("%s\n\nPress ENTER for exit...", str_b_int);
    getchar(); getchar();
}