#pragma once
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void plot_gisto(double(*f)());  //��������� ��� 1-5 ������
void plot_gisto3(double(*f)());  // ��������� ��� 6-8 ������
void plot_gisto100(double(*f)()); // ��������� ��� 9, 10 ������
double rand_1();  //˳����� ������������ �����
double rand_2();  //������������ ������������ �����
double rand_3();  //����� Գ�������
double rand_4();  //�������� ����������� �����������
double rand_5();  //����� �ᒺ������
double rand_6();  //������� �3 �����
double rand_7();  //����� �������� ���������
double rand_8();  //����� �����������
double rand_9();  //����� ��������� ��� ����������� ���������� ��������
double rand_10(); //����� ������ ��� ����������� �����-�������� ������� a > 1
