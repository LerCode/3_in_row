#include <iostream>
#include <iomanip>
#include <vector>
//#include <chrono>

enum class Chip;
class Field;
struct coordinats;

enum class Chip // Все цвета фишек
{
	RED = '*',
	YELLOW = '&',
	GREEN = '#',
	CYAN = '$',
	BLUE = '0',
	VIOLET = '@',
	VOID = ' ' // Если поле пустое
};

struct coordinats
{
	unsigned char x;
	unsigned char y;
}; /* Серёг, это та самая структура, переменные типа которой ты впихнёшь
 в std::vector<coordinats> в функции поиска три в рядок */

class Field
{
private:
	const unsigned char height, width;
	Chip** field;
	inline Chip make_chip() const; // Создаёт рандомную фишку
public:
	Field(const unsigned char, const unsigned char);
	~Field();
	std::vector<coordinats> serach_4_3(); // Search_for_three. Твой метод для поиска три в ряд фишек
	void print_chip(Chip) const;
	void draw() const; // Выводит поле в консоль
};

inline Chip Field::make_chip() const
{
	switch (std::rand() % 6)
	{
		case 0:
			return Chip::RED;
		case 1:
			return Chip::YELLOW;
		case 2:
			return Chip::GREEN;
		case 3:
			return Chip::CYAN;
		case 4:
			return Chip::BLUE;
		case 5:
			return Chip::VIOLET;
	}
}


Field::Field(const unsigned char height_in, const unsigned char width_in): height {height_in}, width {width_in}, field {new Chip*[height]}
{
	std::srand(std::time(nullptr)); // Для генерации случайных фишек по времени
    for (unsigned char y {0u}; y < height; y++) 
	{
		field[y] = new Chip[width];
        for (unsigned char x {0u}; x < width; x++)
			field[y][x] = make_chip();
	} // Заполнили поле случайными фишками
}

Field::~Field()
{
	for (unsigned char y {0u}; y < height; y++)
		delete[] field[y];
	delete[] field;
}

std::vector<coordinats> Field::serach_4_3()
{
/*
Смотри, это метод класса Field.
Отсюда доступны все поля (переменные) и методы объектов класса Field.
Для примера можешь посмотреть другие методы в функции
*/
}

void Field::print_chip(Chip chip) const
{
	switch (chip)
	{
		case Chip::RED:
			std::cout << "\033[1;31m"; break;
		case Chip::YELLOW:
			std::cout << "\033[1;33m"; break;
		case Chip::GREEN:
			std::cout << "\033[1;32m"; break;
		case Chip::CYAN:
			std::cout << "\033[1;36m"; break;
		case Chip::BLUE:
			std::cout << "\033[1;34m"; break;
		case Chip::VIOLET:
			std::cout << "\033[1;35m"; break;
	}
	std::cout << static_cast<char>(chip) << "\033[0m";
}

void Field::draw() const
{
	unsigned char x, y;
	std::cout << "   ";
	for (y = 0u; y < width; y++) // Верхние границы
		std::cout << "_";
	std::cout << "\n"; 

	for (y = (unsigned char)0u; y < height; y++)
	{ 
		std::cout << std::setw(2) << static_cast<unsigned short>(y) << '|';
		for (x = 0u; x < width; x++)
			print_chip(field[y][x]); // Вывод фишек
		std::cout << "|\n"; 
	}

	std::cout << "   ";
	for (y = 0u; y < width; y++) // Нижние раницы
		std::cout << "‾"; 
	std::cout << "\n   ";

  	for (y = 0u; y < width; y++) // Буковки снизу для столбцов
		std::cout << static_cast<char>(y + 'a'); 
	std::cout << "\n";
}

int main()
{
	unsigned char height, width;
	std::cout << "Input height of field: ";
	scanf("%d", &height);
	std::cout << "Input width of field: ";
	scanf("%d", &width);
	Field field {height, width};
	field.draw();
	return 0;
}