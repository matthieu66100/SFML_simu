#include <SFML/Graphics.hpp>
using namespace sf;

class CelestialBody
{
    private:
        CircleShape shape;
        Vector2f position;
        Vector2f velocity;

    public:
        CelestialBody(float radius, Vector2f position, Vector2f velocity, Color color)
        {
            shape.setRadius(radius);
            shape.setFillColor(color);
            position.x = position.x - radius;
            position.y = position.y - radius;
            shape.setPosition(position);
            this->position;
            this->velocity;
        }
        void update(float deltaTime){
            position += velocity * deltaTime;
        }
        void draw(RenderWindow& window){
            window.draw(shape);
        }
};