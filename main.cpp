#include <iostream> 

enum class Chip;
class Field;

enum class Chip // Здесь лежат все варианты фишек
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
	const unsigned char width, height;
	Chip field[][];
	Chip make_chip();
public:
	Field(unsigned char, unsigned char);
	void draw() const;
};

Chip Field::make_chip()
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

Field::Field(const unsigned char width_in, const unsigned char height_in): width{width_in}, height{height_in}
{
	field[height][width]
    for (char y = 0; y < height; y++) 
        for (char x = 0; x < width; x++)
			field[y][x] = make_chip();
} 

void Field::draw() const
{
	std::cout << "  ";
	for (char i = 0; i < width; i++)
		std::cout << "_";
	std::cout << "\n"; 

	for (char i = 0; i < height; i++)
	{ 
		printf("%d%c", i, '|');
		for (char j = 0; j < width; j++)
			std::cout << static_cast<char>(field[i][j]);
		std::cout << "|\n"; 
	}

	std::cout << "  ";
	for (char i = 0; i < width; i++)
		std::cout << "‾"; 
	std::cout << "\n  ";

  	for (char i = 0; i < width; i++)
		std::cout << static_cast<char>(i + 'a'); 
	std::cout << "\n"; 
}

int main()
{
	unsigned char height, weight;
	std::cin >> height >> weight;
	Field field{height, weight};
	return 0;
}