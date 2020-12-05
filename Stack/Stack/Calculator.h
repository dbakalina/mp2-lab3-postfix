#pragma once
#include <string>
#include "Stack.h"
using namespace std;

class TCalculator
{
	string formula;
	Stack <char> st_c;                   // Стек для символов (скобок)
	Stack <double> st_d;                 // Стек для чисел
	string infix;                        // Инфиксная форма
	string postfix;                      // Постфиксная форма

	int Priority(char elem);             // Приоритеты операций
public:
	TCalculator() : st_c(100), st_d(200) //Конструктор
	{
		infix = " ";
		postfix = " ";
	};
	TCalculator(const TCalculator& calc) //Конструктор копирования
	{
		infix = calc.infix;
		postfix = calc.postfix;
		st_c = calc.st_c;
		st_d = calc.st_d;
	}
	~TCalculator() {};                     //Деструктор
	void SetFormula(string str);
	bool CheckBrackets();                 // Проверка скобок 
	string GetInfix();                    // Получить инфиксное выражение
	void SetExpression(string expr);
	string GetPostfix();                  // Получить постфиксное выражение 
	void ToPostfix();                     // Перевод в постфиксную форму
	double CalcPostfix();                 // Вычисление выражения по постфиксной форме
	double Calc();                        // Вычисление за 1 проход по инфиксной форме
};