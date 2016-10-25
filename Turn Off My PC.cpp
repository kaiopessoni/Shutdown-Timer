/***************************************************|
|	Name: Turn Off My PC							|
|	Function: Timer to turn off your PC				|
|	Created on: 10/25/2016							|
|	Author: Kaio Pessoni | kaiopessoni.com			|
|	Platform: Windows only							|
|	Languages: English and Portuguese				|
|	Programming Language: C++						|
|													|
|***************************************************/

#include "stdafx.h"
#include <iostream>
#include <locale.h>
#include <string>
#include <Windows.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "portuguese");
	system("title Turn Off My PC");
	system("mode con: cols=54 lines=20");
	system("color f");

	int language;
	int hours, minutes, seconds, milliseconds = 10;
	int initH, initM, initS;
	string labelQuestion, labelInitialTime, labelHours, labelMinutes, labelSeconds, labelLeft, labelCredits, labelWarning;

	// Setup Language
	cout << "\n Choose a language | Escolha um idioma \n";
	cout << "\n 1. English \n 2. Português \n";

	do {
		cout << "\n Choice | Escolha: ";
		cin >> language;
	} while (language < 1 || language > 2);

	system("cls");

	switch (language) {
	case 1: // English
		labelQuestion = "\n On how long you want your PC turn off?\n\n";
		labelInitialTime = "\n Setted time: ";
		labelHours = " Hours";
		labelMinutes = " Minutes";
		labelSeconds = " Seconds";
		labelLeft = " left. ";
		labelCredits = "Created by Kaio Pessoni.";
		labelWarning = " WARNING: if you click on the screen, right click to\n get back.";
		break;
	case 2: // Português
		system("title Desligue Meu PC");
		labelQuestion = "\n Em quanto tempo deseja que o seu PC desligue?\n\n";
		labelInitialTime = "\n Tempo configurado: ";
		labelHours = " Horas";
		labelMinutes = " Minutos";
		labelSeconds = " Segundos";
		labelLeft = " faltando. ";
		labelCredits = "Criado por Kaio Pessoni.";
		labelWarning = " AVISO: se você clicar na tela, clique com o botão\n direito para voltar.";
		break;
	}

	cout << labelQuestion;

	do {
		cout << labelHours << ": ";
		cin >> hours;
	} while (hours < 0 || hours > 72);

	do {
		cout << labelMinutes << ": ";
		cin >> minutes;
	} while (minutes < 0 || minutes > 59);

	do {
		cout << labelSeconds << ": ";
		cin >> seconds;
	} while (seconds < 0 || seconds > 59);

	initH = hours;
	initM = minutes;
	initS = seconds;

	for (;;) {

		if (milliseconds == 0) {
			if (seconds > 0)
				--seconds;
			milliseconds = 10;
		}

		if (seconds == 0) {
			if (hours > 0) {
				--minutes;
				if (minutes < 0) {
					minutes = 59;
					--hours;
				}
			}
			else {
				--minutes;
				if (minutes < 0)
					break;
			}
			seconds = 59;
		}

		cout << "\n" << labelWarning << "\n\n";
		cout << labelInitialTime << initH << labelHours << " " << initM << labelMinutes << " " << initS << labelSeconds << "\n";
		cout << "\n " << hours << labelHours << " " << minutes << labelMinutes << " " << seconds << labelSeconds << labelLeft;
		cout << "\n\n\n\n\n\n\n              " << labelCredits << "\n                         ";

		--milliseconds;
		Sleep(75);

		system("cls");
	}

	system("shutdown /s");

	return 0;
}