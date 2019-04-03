#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <time.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int chances;

class Word {
	public:
		Word(string w, int l, string h) {
			word = w;
			_word = w;
			length = l;
			hint = h;
		}
		string word, hint, _word;
		int length;
};

void gameOver(Word word) {
	system("cls");
	cout << "Przykro mi, ale nie zdolales znalezc hasla :(\n";
	cout << "Chodzilo o " << word.word;
	cout << "\nSproboj kiedys indziej, moze sie Ci poszczesci";
	Sleep(5000);
		
	system("cls");
	cout << "Zakonczyles gre! Kliknij dowolny przycisk, by wyjsc :)\n";
}

void endGame(Word word) {
	system("cls");
	cout << "Zgadles cale slowo!\nDokladnie chodzilo o " << word.word;
	cout << "\nBrawo!";
	Sleep(5000);
		
	system("cls");
	cout << "Zakonczyles gre! Kliknij dowolny przycisk, by wyjsc :)\n";
}

void draw(Word &word) {
	bool game = true;
	int moves = 0;
	int catchedChars = 0;
	while (game) {
		if (catchedChars == word.length) {
			endGame(word);
			break;
		}
		int x = getch();
		for (int i = 0; i < word.length; i++) {
			if (x == (int)word._word[i]) {
				word._word[i] = 0;
				cout << "\nZgadles litere! - " << word.word[i];
				moves--;
				catchedChars++;
			}	
		}
		
		if (moves % word.length == 0 && moves > 1) {
			system("cls");
			cout << "Widze, ze nie dajesz rady!\nMasz wskazowke: " << word.hint << "\n";
		}
		moves++;
		
		if (moves == word.length * 3) {
			gameOver(word);
			break;
		}
	}
}

void initialGame() {
	system("cls");
	int i = time(NULL) % 5;
	cout << "Twoje slowo zostalo wylosowane! \nTeraz wprowadzaj znaki - male litery bez cyferek! Pamietaj, masz ograniczona liczbe znakow!";
	chances = 10;
	if (i == 0) {
		Word word("dzban", 5, "Slowo uznane za najbardziej mlodziezowe w 2018 roku!");
		draw(word);
	} else if (i == 1) {
		Word word("arachnofobia", 12, "Lek przed pajakami");
		draw(word);
	} else if (i == 2) {
		Word word("owczarek", 8, "Tak naprawde nie pochodzi z Niemiec ;)");
		draw(word);
	} else if (i == 3) {
		Word word("informatyka", 11, "Przedmiot, z ktorego pisze rozszerzenie");
		draw(word);
	} else if (i == 4) {
		Word word("error", 5, "To nie powinno sie wydarzyc!");
		draw(word);
	}
}

void start() {
	system("cls");
	cout << "Czesc! Twoim zadaniem jest odgadniecie hasla do nastepnego poziomu!\n";
	cout << "Kliknij \"a\", by rozpoczac: ";
	while (true) {
		char x = getch();
		if ((int)x == 97) {
			break;
		}
		cout << "\nTo nie jest a! Nie oszukasz mnie :)";
	}
	initialGame();
}

int main(int argc, char** argv) {
	start();

	system("pause");
	return 0;
}
