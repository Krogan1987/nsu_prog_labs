#include <stdio.h>                        //    *|     NSU FIT     |*
#include <string.h>                       //    *|      LAB_0      |*
#include <math.h>                         //    *| by Mateyuk_Ilya |*
#include <stdlib.h>                       //    *|     _18212_     |*
#include <ctype.h>

typedef unsigned long long ULL;
static const char SSS[] = "0123456789ABCDEF";

void test(int point, int lenght, int a, int b, char *str) {
    int exit0, exit1, exit2, exit3, exit4;
    for (int i = 0; i < lenght; ++i) {
        str[i] = (char) (toupper(str[i]));
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

double aTo10(int point, int lenght, int a, const char *str) {
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
    char symb[2]={0};
    if (dec == 0) str_b_int[0] = '0';
    while (dec > 0) {
        symb[0] = SSS[dec % b];
        dec = dec / b;
        strcat(str_b_int, symb);
    }
    int k = strlen(str_b_int);
    for (int i = 0; i < k / 2; ++i) {
        symb[0] = str_b_int[i];
        str_b_int[i] = str_b_int[k - i - 1];
        str_b_int[k - i - 1] = symb[0];
    }
}

void dec2b_frac(double dec, int b, char *s) {                       // Перевод дробной части в b-ричную
    char symb;
    double p = 0;
    for (int i = 0; i < 12; ++i) {                                  // Находим 12 символов после точки
        p = dec * b;
        symb = SSS[(ULL) p];
        dec = p - (ULL) p;
        *s = symb;
        ++s;
    }
}

void cls_0(char *str_b_frac) {
    for (int i = 12; (i >= 2) && (str_b_frac[i] == '0'); --i) {
        str_b_frac[i] = '\0';                                       // Убирает лишние нули
    }
}

int main() {
    int a, b;
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
        dec2b_frac(result_10, b, str_b_frac + 1);                       // Дробная часть в b-ричной
        cls_0(str_b_frac);                                          // Убираем лишние нолики
        strcat(str_b_int, str_b_frac);
    }
    printf("%s\n\nPress ENTER for exit...", str_b_int);
    getchar();
    getchar();
}