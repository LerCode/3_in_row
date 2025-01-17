#include <iostream> 
#include <random> 

using namespace std;  

enum chip // здесь лежат все варианты фишек
{
	RED,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET
};

const char width = 20, height = 10; // Размеры поля

char field[height][width]; // Двумерный массив с полем

chip fishka(){
	chip this_chip = random(0, 4);
	return this_chip;
}

void field_filling(){ 
    for (char i = 0; i < height; i++) 
        fill(field[i], field[i] + width, '0'); 
} 

void draw(){
	cout << " "; 
  	for (char i = 0; i < width; i++)
		cout << "_"; 
	cout << "\n"; 
	for (char i = 0; i < height; i++) { 
		cout << "|"; 
		for (char j = 0; j < width; j++)
			cout << field[i][j];
		cout << "|\n"; 
	}  
	cout << " ";
	for (char i = 0; i < width; i++)
		cout << "‾"; 
	cout << "\n"; 
}

int main(){
	cout << "Hello world\n";
	field_filling();
	draw();
}