#include "Sim.h"
#include "Noise.h"
Sim::Sim() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Particles", sf::Style::Default, settings);
}

void Sim::run() {
    window->setFramerateLimit(60);
    Noise noise{};


    float dt = 1.0f / 60.0f;
    dt = 0.12f;
    sf::Clock clock;
    while (window->isOpen())
    {
        sf::Time elapsed = clock.restart();

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

        }
        noise.updatePerlin(elapsed.asMilliseconds());

        window->clear();
        window->draw(noise.vA);
        window->display();
    }
}