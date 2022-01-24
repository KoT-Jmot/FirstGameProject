#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
#include<fstream>
#include <conio.h>
#include <stdio.h>
using namespace std;

char Mass[100][100];
int border;
enum mainDerection{MAIN_STOP=0,MAIN_LEFT,MAIN_RIGHT,MAIN_ENTER};
mainDerection menu;
enum eDirection {STOP=0,UP,LEFT,RIGHT,DOWN, M_UP, M_LEFT, M_RIGHT,M_DOWN};
eDirection dir;
enum eComplexity {COMP_STOP = 0,COMP_LEFT,COMP_RIGHT,COMP_ENTER};
eComplexity cmpl;
int quantity_of_enemy;
int X, Y;
int X1, Y1;
int enemy_near;
int score;
string COMENNT;
char C;
int mins;
int X2;
int Y2;
ofstream  we;
string comw;
string A;
string B;
int complexity_cheker;
bool Namer;
bool Game_comment;
char Xa;
int Main_cheker;
int sum;
int A1, B1;
bool Ending;
bool EXID;
bool play;
fstream f, com;
bool complex;
int steep;
bool win;
string Name;
string Menu;
void SetUp() {
	f.open("stats.txt", ios::app);
	f << "";
	f.close();
	f.open("comments.txt", ios::app);
	f << "";
	f.close();
	sum = 1;
	enemy_near = 0;	
	dir = STOP;
	menu = MAIN_STOP;
	cmpl = COMP_STOP;
	mins = 0;
	EXID = false;
	A1 = 0;
	B1 = 0;
	X2-0;
	Y2=0;
	Game_comment = false;
	win = false;
	play = false;
	Namer = false;
	complex = false;
	steep = 0;
	score = 0;
	Ending = false;
	Main_cheker=0;
	complexity_cheker = 0;
	X = 0, Y = 0;
	
}
void choice_comp();
bool Seter(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void make_cart() {
	for (int i = 0; i < border; i++)
		for (int j = 0; j < border; j++)
			Mass[i][j] = '-';
	for (int i = 0; i < quantity_of_enemy; i++) {
		while (true) {
			A1 = rand() % border;
			B1 = rand() % border;
			if (A1 != 0 || B1 != 0) {
				Mass[A1][B1] = '@';
				break;
			}
		}
	}
	for (int i = 0; i < border; i++)
		for (int j = 0; j < border; j++)
			if (Mass[i][j] == '-')
				mins++;
	Mass[0][0] = '*';
}
void Enter_Name() {

	while (!Namer) {
		system("cls");
		cout << "\t\t\t\t\t\t\t\t\tMade by Ivan Leshchenko";
		cout << "\n\tЗдравствуйте! Вас приветствует игра \"Выжить во Тьме\".\n";
		cout << "\t\tУдачной Вам игры и успехов!\n";
		cout << "Введите ваше имя:\n";
		cout << Name;
		while (true) {
			if (_kbhit()) {
				Xa = _getch();
				switch (Xa)
				{
				case 32:
					Namer = true;
					break;
				case 13:
					Namer = true;
					break;
				case 8:
					break;
				default:
					Name = Name + Xa;
					break;
				}
				if (Name.size() >= 7)
					Namer = true;
				break;
				
			}
		}
	}
}
void status();
void Comment();
void How_to_play();
void choice() {
	switch (Main_cheker)
	{
	case 0:
		play = true;
		break;
	case 1:
		status();
		break;
	case 2:
		Comment();
		break;
	case 3:
		How_to_play();
		break;
	case 4:
		EXID = true;
		play = true;
		break;
	}
}
void status() {

	system("cls");
	fstream tw;
	tw.open("stats.txt", ios::in);
	string a;
	while (!tw.eof())
	{
		getline(tw, a);
		cout << a << endl;

	}
	tw.close();
	while (true) {
		if (_kbhit()) {
			B = _getch();
			break;
		}
	}
}

void Stats() {
	we.open("stats.txt", ios::app);
	if (win)
		comw = "Победа   ";
	else
		comw = "Поражение";
	switch (complexity_cheker)
	{
	case 0:
		A = "baby";
		break;
	case 1:
		A = "easy";
		break;
	case 2:
		A = "norm";
		break;
	case 3:
		A = "hard";
		break;
	default:
		A = "ERROR";
		break;
	}
	we << Name << "\t  " << A << "\t" << comw << "    Очки - " << score << endl;
	we.close();
}
void Comment() {
	system("cls");
	com.open("comments.txt", ios::in);
	string a;
	while (!com.eof())
	{
		getline(com, a);
		cout << a << endl;

	}
	com.close();
	while (true) {
		if (_kbhit()) {
			B = _getch();
			break;
		}
	}
}
void color(int a, int b) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((a << 4) | b));
}
void Main_Menu() {
	while (!play) {
		system("cls");
		menu = MAIN_STOP;
		switch (Main_cheker) {
		case 0:
			cout << "\t ----";
			cout << "\n\t|play|\tstats\tcomment\t  help\t  exit\n";
			cout << "\t ----";
			break;
		case 1:
			cout << "\t\t -----";
			cout << "\n\tplay\t|stats|\tcomment\t  help\t  exit\n";
			cout << "\t\t -----";
			break;
		case 2:
			cout << "\t\t\t -------";
			cout << "\n\tplay\tstats\t|comment|   help   exit\n";
			cout << "\t\t\t -------";
			break;
		case 3:
			cout << "\t\t\t\t ----";
			cout << "\n\tplay\tstats\tcomment\t|help|\texit\n";
			cout << "\t\t\t\t ----";
			break;
		case 4:
			cout << "\t\t\t\t\t ----";
			cout << "\n\tplay\tstats\tcomment\t  help\t|exit|\n";
			cout << "\t\t\t\t\t ----";
			break;
		}
		while (true) {
			if (_kbhit()) {
				switch (_getch()) {
				case 'd':
					if (Main_cheker < 4)
						menu = MAIN_RIGHT;
					break;
				case 'в':
					if (Main_cheker < 4)
						menu = MAIN_RIGHT;
					break;
				case 'a':
					
					if (Main_cheker > 0)
						menu = MAIN_LEFT;
					break;
				case 'ф':

					if (Main_cheker > 0)
						menu = MAIN_LEFT;
					break;
				case 32:
					menu = MAIN_ENTER;
					break;
				}

				switch (menu) {
				case MAIN_LEFT:
					Main_cheker--;
					break;
				case MAIN_RIGHT:
					Main_cheker++;
					break;
				case MAIN_ENTER:
					choice();
					break;
				}
				if (menu == MAIN_ENTER || menu == MAIN_RIGHT || menu == MAIN_LEFT)
					break;
			}
		}
	}

}

void choice_comp() {
	switch (complexity_cheker)
	{
	case 0:
		border = 7;
		quantity_of_enemy = 10;
		break;
	case 1:
		border = 10;
		quantity_of_enemy = 15;
		break;
	case 2:
		border = 11;
		quantity_of_enemy = 20;
		break;
	case 3:
		border = 15;
		quantity_of_enemy = 25;
		break;
	}
	complex = true;
}
void complexity() {
	while (!complex) {
		cmpl = COMP_STOP;
		system("cls");
		switch (complexity_cheker)
		{
		case 0:
			cout << "\t ----";
			cout << "\n\t|baby| easy normal hard\n";
			cout << "\t ----";
			break;
		case 1:
			cout << "\t      ----";
			cout << "\n\tbaby |easy| normal hard\n";
			cout << "\t      ----";
			break;
		case 2:
			cout << "\t           ------";
			cout << "\n\tbaby easy |normal| hard\n";
			cout << "\t           ------";
			break;
		case 3:
			cout << "\t                  ----";
			cout << "\n\tbaby easy normal |hard|\n";
			cout << "\t                  ----";
		}
		while (true) {
			if (_kbhit()) {
				switch (_getch()) {
				case 'd':
					if(complexity_cheker < 3)
						cmpl = COMP_RIGHT;
					break;
				case 'a':
					if(complexity_cheker > 0)
						cmpl = COMP_LEFT;
					break;
				case 32:
					cmpl = COMP_ENTER;
					choice_comp();
					break;
				}

				switch (cmpl)
				{
				case COMP_RIGHT:
					complexity_cheker++;
					break;
				case COMP_LEFT:
					complexity_cheker--;
					break;
				case COMP_ENTER:
					break;
				}
				if (complexity_cheker > 3)
					complexity_cheker = 3;
				if (complexity_cheker < 0)
					complexity_cheker = 0;
				if (cmpl==COMP_RIGHT || cmpl==COMP_ENTER || cmpl==COMP_LEFT)
					break;
			}
		}
	}
}


void Drow() {
	for (int i = 0; i < border; i++) {
		for (int j = 0; j < border; j++) {
			color(3, 0);
			if (Mass[i][j] == Mass[0][0]) {
				color(3, 14);
				cout << 'X' << "       ";
				color(3, 0);
			}
			else {
				if (Mass[i][j] == '@')
					cout << '-' << "       ";
				else
					cout << Mass[i][j] << "       ";
			}
		}
		for (int we = 0; we < 2;we++) {
			cout << endl;
			for (int wqe = 1; wqe <= border;wqe++) {
				cout << "        ";
			}
		}
		cout << endl;
	}
	color(7, 0);
	if (Mass[X - 1][Y] == '@')
		enemy_near++;
	if (Mass[X + 1][Y] == '@')
		enemy_near++;
	if (Mass[X][Y - 1] == '@')
		enemy_near++;
	if (Mass[X][Y + 1] == '@')
		enemy_near++;
	cout << "Рядом Враг(ов): ";
	color(14, 0);
	cout << enemy_near;
	color(7, 0);
	cout << "\t\t\tВсего ходов: ";
	color(14, 0);
	cout << steep;
	color(7, 0);
}
void Imput() {
	if (_kbhit()) {
		switch (_getch()) {
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 72:
			dir = M_UP;
			break;
		case 75:
			dir = M_LEFT;
			break;
		case 77:
			dir = M_RIGHT;
			break;
		case 80:
			dir = M_DOWN;
			break;

		}

	}
}
void Logic() {
	X1 = X;
	Y1 = Y;
	X2 = X;
	Y2 = Y;
	switch (dir)
	{
	case UP:
		X--;
		steep++;
		break;
	case LEFT:
		Y--;
		steep++;
		break;
	case RIGHT:
		Y++;
		steep++;
		break;
	case DOWN:
		X++;
		steep++;
		break;
	case M_UP:
		X2--;
		Seter(Y2 * 8, X2 * 3);
		color(12, 0);
		cout << "?";
		color(14, 0);
		break;
	case M_DOWN:
		X2++;
		Seter(Y2 * 8, X2 * 3);
		color(12, 0);
		cout << "?";
		color(14, 0);
		break;
	case M_LEFT:
		Y2--;
		Seter(Y2 * 8, X2 * 3);
		color(12, 0);
		cout << "?";
		color(14, 0);
		break;
	case M_RIGHT:
		Y2++;
		Seter(Y2 * 8, X2 * 3);
		color(12, 0);
		cout << "?";
		color(14, 0);
		break;

	}
	enemy_near = 0;
	if (X >= border || Y >= border || Y < 0 || X < 0 || Mass[X][Y] == '@' )
		Ending = true;
	else {
		if (dir != STOP) {
			//if (Mass[X][Y] != '*') {
			Seter(Y1 * 8, X1 * 3);
			color(3, 15);
			cout << "*";
			color(7, 0);
			Seter(Y * 8, X * 3);
			color(3, 14);
			cout << "X";
			color(7, 0);
			if (Mass[X][Y] == '-') {
				Mass[X][Y] = '*';
				sum++;
			}
			if (Mass[X - 1][Y] == '@')
				enemy_near++;
			if (Mass[X + 1][Y] == '@')
				enemy_near++;
			if (Mass[X][Y - 1] == '@')
				enemy_near++;
			if (Mass[X][Y + 1] == '@')
				enemy_near++;
			Seter(16, border * 3);
			color(14, 0);
			cout << enemy_near;
			color(7, 0);
			color(14, 0);
			Seter(53, border * 3);
			cout << steep;
			color(7, 0);
			//	}
		}
	}
	dir = STOP;
	if (sum == mins) {
		win = true;
		Ending = true;
	}

	
}
int main(){
	system("chcp 1251");
	srand(time(NULL));
	color(7,0);
	Enter_Name();
	while (!EXID) {
		color(7, 0);
		system("cls");
		SetUp();
		Main_Menu();
		if (!EXID) {
			complexity();
			make_cart();
			system("cls");
			Drow();
			while (!Ending){
				Imput();
				Logic();
				if (Ending) {

						system("cls");
						for (int i = 0; i < border; i++) {
							for (int j = 0; j < border; j++) {
								color(3, 0);
								if (i == X & j == Y & Mass[i][j] != '@') {
									color(3, 14);
									cout << 'X' << "       ";
									color(3, 0);
								}
								else
									if (Mass[i][j] == '@') {
										color(3, 12);
										cout << '@' << "       ";
										color(3, 0);
									}
									else

										if (Mass[i][j] == '*') {
											color(3, 15);
											cout << '*' << "       ";
											color(3, 0);
										}
										else
											cout << Mass[i][j] << "       ";
							}
							for (int we = 0; we < 2; we++) {
								cout << endl;
								for (int wqe = 1; wqe <= border; wqe++) {
									cout << "        ";
								}
							}
							cout << endl;
						}
						color(14, 0);
						if (win == true)
							cout << "\nВы Победили!";
						else 
							cout << "\nВы Проиграли!";
						score = round((complexity_cheker + 1) + sum*10 - (steep / 3));
						if (win == true)
							score *= 2;
						cout << "\nОчки: " << score;
						cout << "\nЕсли хотите дать комментарий игре,нажмите \"y\"\n";
						while (true)
						if (_kbhit()) {
							
							B = _getch();
							if (B == "y") {
								color(7, 0);
								com.open("comments.txt", ios::app);
								while (!Game_comment) {
									system("cls");
									color(14, 0);
									cout << "Введите комментарий: ";
									color(3, 0);
									getline(cin, COMENNT);
									color(7, 0);
									Game_comment = true;
									com << Name << "\t- " << COMENNT << endl;
									com.close();
								}
							}
								Stats();
								break;
						}
					
				}
			}
		}
	
	}
	return 0;
}


void How_to_play() {
	while (true) {
		system("cls");
		cout << "Вашей задачей является выжить, спасаясь от врагов, и не уйти за зону.\n";
		cout << "Зона окружает поле, размеры которого зависят от сложности.\n";
		cout << "Это выглядит вот так : \n\n";
		cout << "---------------------------------------------\n";
		cout << "\t*\t?\t@\t-\n\n\n\t*\t-\t-\t-\n\n\n\t*\t@\t-\t-\n\n\n\tX\t@\t-\t@\n";
		cout << "\nРядом Враг(ов): 1\t\t\tВсего ходов : 4\n";
		cout << "---------------------------------------------\n";
		cout << "\t\t\tГде \"-\" - это неопознанное место;   \"*\"- место, где Вы прошли \n\t\t\t\"X\"- Ваш персонаж;   \"?\"- метка, а \"@\"- враг\n\n";
		cout << "\tОднако врагов Вы не будете видеть, они будут спрятаны среди \"-\"\n";
		cout << "\tНо если рядом с Вами будет находиться один из врагов, то Вам об этом напишут!\n\n";
		cout << "-------------------------------------------------------------------------------------\n";
		cout << "\tПередвижение : \"w\"-вверх, \"s\"-вниз, \"a\"-влево, \"d\"-вправо \n";
		cout << "\tМетки : \"Up\"-вверх, \"Down\"- вниз, \"Left\"- влево, \"Right\"- вправо (стрелочки!)\n";
		cout << "-------------------------------------------------------------------------------------\n\n";
		cout << "Вам нужно собрать все \"-\", не наткнувшись на \"@\" и не выйти за зону!\n";
		cout << "Если Вы наткнётесь на врага или выйдете за зону, то проиграете!\n\n";
		while (true) {
			if (_kbhit()) {
				B = _getch();
				break;
			}
		}
		break;

	}
}