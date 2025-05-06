#include <iostream>
#include <iomanip>

enum class Chip;
class Field;

enum class Chip // Все цвета фишек
{
	RED = '*',
	ORANGE = '$',
	YELLOW = '&',
	GREEN = '#',
	BLUE = '0',
	VIOLET = '@'
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
	char this_chip = rand() % 6;
	switch (this_chip)
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
		default:
			return Chip::VIOLET;
	}
}

Field::Field(const unsigned short height_in, const unsigned short width_in): height{height_in}, width{width_in}
{
	field = new Chip*[height];
	for (unsigned short y = 0u; y < height; y++)
		field[y] = new Chip[width];
	// Инициализировали поле
    for (unsigned short y = 0u; y < height; y++) 
        for (unsigned short x = 0u; x < width; x++)
			field[y][x] = make_chip();
	// Заполнили поле случайными фишками
}

Field::~Field()
{
	for (unsigned short y = 0u; y < height; y++)
		delete[] field[y];
	delete[] field;
}

void Field::draw() const
{
	std::cout << "   ";
	for (unsigned short i = 0u; i < width; i++) // Верхние границы
		std::cout << "_";
	std::cout << "\n"; 

	for (unsigned short y = 0u; y < height; y++)
	{ 
		std::cout << std::setw(2) << y << '|';
		for (unsigned short x = 0u; x < width; x++)
			std::cout << static_cast<char>(field[y][x]); // Вывод фишек
		std::cout << "|\n"; 
	}

	std::cout << "   ";
	for (unsigned short i = 0u; i < width; i++) // Нижние раницы
		std::cout << "‾"; 
	std::cout << "\n   ";

  	for (unsigned char i = 0u; i < width; i++) // Буковки снизу для столбцов
		std::cout << static_cast<char>(i + 'a'); 
	std::cout << "\n";
}

int main()
{
	unsigned short height, width;
	std::cout << "Input height of field: "; std::cin >> height;
	std::cout << "Input wight of field: "; std::cin >> width;
	Field field{height, width};
	field.draw();
	return 0;
}