#include <iostream>
#include <iomanip>
//#include <chrono>

enum class Chip;
class Field;

enum class Chip // Все цвета фишек
{
	RED = '*',
	ORANGE = '$',
	YELLOW = '&',
	GREEN = '#',
	BLUE = '0',
	VIOLET = '@',
	VOID = ' ' // Если поле пустое
};

class Field
{
private:
	const unsigned short height, width;
	Chip** field;
	Chip make_chip() const; // Создаёт рандомную фишку
public:
	Field(const unsigned short, const unsigned short);
	~Field();
	void draw() const; // Выводит поле в консоль
};

Chip Field::make_chip() const
{
	switch (std::rand() % 6)
	{
		case 0:
			return Chip::RED;
		case 1:
			return Chip::ORANGE;
		case 2:
			return Chip::YELLOW;
		case 3:
			return Chip::GREEN;
		case 4:
			return Chip::BLUE;
		case 5:
			return Chip::VIOLET;
	}
}

Field::Field(const unsigned short height_in, const unsigned short width_in): height{height_in}, width{width_in}
{
	field = new Chip*[height];
	std::srand(std::time(nullptr)); // Для генерации случайных фишек по времени
    for (unsigned short y = 0u; y < height; y++) 
	{
		field[y] = new Chip[width];
        for (unsigned short x = 0u; x < width; x++)
			field[y][x] = make_chip();
	} // Заполнили поле случайными фишками
}

Field::~Field()
{
	for (unsigned short y = 0u; y < height; y++)
		delete[] field[y];
	delete[] field;
}

void Field::draw() const
{
	unsigned short x, y;
	std::cout << "   ";
	for (y = 0u; y < width; y++) // Верхние границы
		std::cout << "_";
	std::cout << "\n"; 

	for (y = 0u; y < height; y++)
	{ 
		std::cout << std::setw(2) << y << '|';
		for (x = 0u; x < width; x++)
			std::cout << static_cast<char>(field[y][x]); // Вывод фишек
		std::cout << "|\n"; 
	}

	std::cout << "   ";
	for (y = 0u; y < width; y++) // Нижние раницы
		std::cout << "‾"; 
	std::cout << "\n   ";

  	for (y = 0u; y < width; y++) // Буковки снизу для столбцов
		std::cout << static_cast<char> (y + 'a'); 
	std::cout << "\n";
}

int main()
{
	unsigned short height, width;
	std::cout << "Input height of field: "; std::cin >> height;
	std::cout << "Input wight of field: "; std::cin >> width;
	Field field {height, width};
	field.draw();
	return 0;
}