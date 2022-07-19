#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP

#include "SFML/Graphics.hpp"
#include "Field.hpp"

enum FieldType {
	Grass = 0,
	Water = 1
};

class GameField :public Field 
{
	private:
		FieldType type;

	public:
		GameField(int x, int y, int width, int height, FieldType type);



};

#endif
