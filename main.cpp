#include <iostream> 

using namespace std;  

enum chip // здесь лежат все варианты фишек
{
	RED = '*',
	ORANGE = '$',
	YELLOW = '&',
	GREEN = '#',
	BLUE = '0',
	VIOLET = '@'
};

const char width = 20, height = 10;
chip field[height][width];

chip make_chip(){
	char this_chip = rand() % 6;
	switch (this_chip)
	{
		case 0:
			return RED;
		case 1:
			return ORANGE;
		case 2:
			return YELLOW;
		case 3:
			return GREEN;
		case 4:
			return BLUE;
	}
	return VIOLET;
}

void field_filling(){ 
    for (char y = 0; y < height; y++) 
        for (char x = 0; x < width; x++)
			field[y][x] = make_chip();
} 

void draw(){
	cout << ' ';
	for (char i = 0; i < width; i++)
		cout << "_";
	cout << "\n"; 
	for (char i = 0; i < height; i++) { 
		printf("%d%c", i, '|');
		for (char j = 0; j < width; j++)
			cout << static_cast<char>(field[i][j]);
		cout << "|\n"; 
	}  
	cout << "  ";
	for (char i = 0; i < width; i++)
		cout << "‾"; 
	cout << "\n  "; 
  	for (char i = 0; i < width; i++)
		cout << static_cast<char>(i + 'a'); 
	cout << "\n"; 
}

int main(){
	cout << "Hello world\n";
	field_filling();
	draw();
}
