#include<SFML/Graphics.hpp>
int main(int argc, char const *argv[])
{
   sf::RenderWindow window(sf::VideoMode(640,800),"TEST");
   sf::CircleShape shape;

   shape.setRadius(40.f);
   shape.setPosition(100.f, 100.f);
   shape.setFillColor(sf::Color::Cyan);

   while(window.isOpen())
   {
      sf::Event event;
      while(window.pollEvent(event))
      {
         if(event.type==sf::Event::Closed)
            window.close();
      }
      window.clear();
      window.draw(shape);
      window.display();
   }


   return 0;
}