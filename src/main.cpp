#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
//#include "Field.hpp"
#include <vector>
#include "GameField.hpp"


//Entity Functions
void render(sf::RenderWindow& window);
void update(long dT);


//Global variables
std::vector<Entity*> entitys;
//Map* map = new Map(10, 10, 10, 10, sf::Vector2i(0,0));

std::string mapString =
    "GGGGGGGGGG"
    "WWWWWWWWWW"
    "GGGGGGGGGG"
    "GGGGGGGGGG";

std::vector<FieldType> mapString = {
    4
}

//main Function
int main()
{
	GameField* gf = new GameField(10,10,10,10,FieldType::Grass);
       
    //Field* f = new Field(10,10,100,100);
    //Field* aa = new Field(90,20, 100,100);
    //aa->setColor(sf::Color::Red);
    
    //entitys.push_back(f);
    //entitys.push_back(aa);
 //   entitys.push_back(map);

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {

               
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				std::cout << "Exiting" << std::endl;
				window.close();
			}
        }

        //long dT = 1;

        sf::Time time = clock.getElapsedTime(); 
        clock.restart(); 
        update(time.asMicroseconds());
    
        render(window);
        
    }

    return 0;
}

void render(sf::RenderWindow& window)
{
        window.clear(sf::Color::Blue);  //clear window
        //render here all stuff
       

        //paint all objects from Game
        for(Entity* e : entitys)
        {
            e->render(window);
        }
        
        window.display();
}

void update(long dT)
{
    for(Entity* e: entitys)
    {
        e->update(dT);

    } 
    
    //    std::cout << dT << std::endl;

}



