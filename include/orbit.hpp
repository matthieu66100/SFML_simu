#include <SFML/Graphics.hpp>
using namespace sf;

class CelestialOrbit {

private:
  CircleShape shape;
  Vector2f position;

public:
  CelestialOrbit(float radius, Vector2f position, Color color) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    position.x = position.x - radius;
    position.y = position.y - radius;
    shape.setPosition(position);
    this->position;
  }

  void draw(RenderWindow window) { window.draw(shape); }
};
