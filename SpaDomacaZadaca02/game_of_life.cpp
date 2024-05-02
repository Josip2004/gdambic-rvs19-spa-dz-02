#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	return rand() % 4 == 0;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return i >= 0 && i < REDAKA && j >= 0 && j < STUPACA && _generacija[i][j];
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++){
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija()
{

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int susjediZivi = 0;

            for (int x = -1; x < 2; x++) {
                for (int y = -1; y < 2; y++) {
                   if (celija_zauzeta(i + x, j + y)) {
                        susjediZivi++;
                    }
                    else {
                        continue;
                    }
                }
            }

            
            if (!_generacija[i][j]) {
                if (susjediZivi == 3) {
                    _sljedeca_generacija[i][j] = true; 
                }
                else {
                    _sljedeca_generacija[i][j] = false;                
                }
            }
            else {
                if (susjediZivi == 2 || susjediZivi == 3) {
                    _sljedeca_generacija[i][j] = true; 
                }
                else {
                    _sljedeca_generacija[i][j] = false; 
                }
            }
        }
    }

 
    for (int i = 0; i < REDAKA; i++) {
        for (int j = 0; j < STUPACA; j++) {
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}


void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++){
		for (int j = 0; j < STUPACA; j++) {
			if (_generacija[i][j] == true) {
				cout << "*";
			}
            else {
                cout << "_";
            }
			
		}
		cout << endl;
	}
}
