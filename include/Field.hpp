#ifndef FIELD_HPP
#define FIELD_HPP

#include "Entity.hpp"
#include "SFML/Graphics.hpp"

class Field : public Entity
{
    private:
        int posX;
        int posY;

        int width;
        int height;

        sf::RectangleShape field;
        sf::Color rCol;

    public :

        Field(int x,int y, int width, int height);
        
        void update(long dT);
        void render(sf::RenderWindow& window); 
       
        void setColor(sf::Color color);
		
		int getX();
		int getY();
		


};

#endif