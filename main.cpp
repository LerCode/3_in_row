#include <iostream> 
#include <random> 

using namespace std;  

const int width = 20, height = 10; // Размеры поля

char pole[height][width]; // Двумерный массив с полем

int fishka(){
  random_device rd; 
  mt19937 gen(rd()); 
  uniform_int_distribution<> dist(1, 6); 
  return dist(gen);
}

void zapolnenie_polya() { 
    for (int i = 0; i < height; i++) 
        fill(pole[i], pole[i] + width, '0'); 
} 

void draw(){
  cout << " "; 
  for (int i = 0; i < width; i++) cout << "_"; 
  cout << "\n"; 
  for (int i = 0; i < height; i++) { 
      cout << "|"; 
      for (int j = 0; j < width; j++){cout << pole[i][j];} 
      cout << "|\n"; 
  }  
  cout << " ";
  for (int i = 0; i < width; i++) cout << "‾"; 
  cout << "\n"; 
}

int main(){
  cout << "Hello world" << "\n";
  zapolnenie_polya();
  draw();
}
