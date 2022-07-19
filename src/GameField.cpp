#include "GameField.hpp"

GameField::GameField(int x, int y, int width, int height, FieldType type) 
	: Field(x,y,width,height)
{
	this->type = type;
}
