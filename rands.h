#pragma once
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void plot_gisto(double(*f)());  //гістограма для 1-5 методів
void plot_gisto3(double(*f)());  // гістограма для 6-8 методів
void plot_gisto100(double(*f)()); // гістограма для 9, 10 методів
double rand_1();  //Лінійний конгруентний метод
double rand_2();  //Квадратичний конгруентний метод
double rand_3();  //Числа Фібоначчі
double rand_4();  //Обернена конгруентна послідовність
double rand_5();  //Метод об’єднання
double rand_6();  //Правило “3 сігма”
double rand_7();  //Метод полярних координат
double rand_8();  //Метод співвідношень
double rand_9();  //Метод логарифму для генерування показового розподілу
double rand_10(); //Метод Аренса для генерування гамма-розподілу порядку a > 1
