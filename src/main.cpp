#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
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
        position.x = position.x/2 - radius;
        position.y = position.y/2 - radius;
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

class SolarSystemSim
    {
    private:
        RenderWindow window;
        int windowWidth;
        int windowHeight;

        vector<CelestialBody> celestialBodies; // Liste des corps celestes
    public:
        // Creator
        SolarSystemSim(int width, int height){
            windowWidth = width;
            windowHeight = height;
            window.create(VideoMode(windowWidth, windowHeight), "Solar System Simulator");
        }

        // Permet d'ajouter au vecteur les corps celestes qui sont appelés
        void addCelestialBody(CelestialBody body){
            celestialBodies.push_back(body);
        }
        
        void runSimulation() {
            Clock clock;
    
            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed)
                        window.close();
                }
    
                float deltaTime = clock.restart().asSeconds();
    
                window.clear();
    
                for (auto& body : celestialBodies) {
                    body.update(deltaTime);
                    body.draw(window);
                }
    
                window.display();
            }
        }

};

int main(){


    SolarSystemSim simulator(1500, 1000);

    CelestialBody sun(100.f, Vector2f(1500,1000), Vector2f(0,0), Color::Yellow);
    CelestialBody earth(10.f, Vector2f(400,300), Vector2f(0,0), Color::Blue);
    CelestialBody mars(5.f, Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody venus(5.f, Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody uranus(5.f, Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody jupiter(5.f, Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody mercure(5.f, Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody saturne(5.f, Vector2f(800,300), Vector2f(0,0), Color::Red);
    CelestialBody neptune(5.f, Vector2f(800,300), Vector2f(0,0), Color::Red);

    simulator.addCelestialBody(sun);
    simulator.addCelestialBody(earth);
    simulator.addCelestialBody(mars);

    simulator.runSimulation();

    return 0;
}
