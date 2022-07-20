#ifndef FIELD_HPP
#define FIELD_HPP

#include "Entity.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "FieldTypes.hpp"

class Field : public Entity
{
    private:
        int posX;
        int posY;

        int width;
        int height;

        sf::RectangleShape field;
        sf::Color rCol;
       
        FieldType type;

    public :

        Field(int x, int y, int width, int height);
        Field(int x, int y, int width, int height, FieldType type);

        void update(long dT);
        void render(sf::RenderWindow& window); 
       
        void setColor(sf::Color color);
		
		int getX();
		int getY();
		
        void toConsole();

};

#endif