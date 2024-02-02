#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    int color = 1;
    bool flag;
    bool flag2;
    bool flag3;
    flag = false;
    flag2 = false;
    flag3 = false;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 750), "Paint", sf::Style::Default, settings);
    sf::RenderTexture buffer;
    buffer.create(1200, 750);
    sf::RectangleShape rect(sf::Vector2f(1200.f, 750.f));
    rect.setFillColor(sf::Color::White);
    buffer.draw(rect);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            if (!flag) {
                sf::Texture LoadBuffer;
                LoadBuffer.loadFromFile("save.png");
                sf::Sprite loadSpr(LoadBuffer);
                sf::Vector2f TargetSize(1200.0f, 750.0f);
                loadSpr.setScale(
                    TargetSize.x / loadSpr.getLocalBounds().width,
                    TargetSize.y / loadSpr.getLocalBounds().height);
                buffer.draw(loadSpr);
                flag = true;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
            if (!flag3) {
                buffer.clear(sf::Color::White);
                flag3 = true;
            }
        }
        else
            flag3 = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (!flag2) {
                buffer.getTexture().copyToImage().saveToFile("save.png");
                flag2 = true;
            }
        }
        else
            flag2 = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            color = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            color = 2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            color = 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            color = 4;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            color = 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            color = 6;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
            color = 7;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            color = 8;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
            color = 9;
        //Draw here
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::CircleShape shape(10.f);
            switch (color)
            {
            case(1): 
                shape.setFillColor(sf::Color::Black);
                break;
            case(2): 
                shape.setFillColor(sf::Color::Blue);
                break;
            case(3): 
                shape.setFillColor(sf::Color::Red);
                break;
            case(4): 
                shape.setFillColor(sf::Color::Green);
                break;
            case(5): 
                shape.setFillColor(sf::Color::Yellow);
                break;
            case(6): 
                shape.setFillColor(sf::Color::Cyan);
                break;
            
            case(7):
                shape.setFillColor(sf::Color(255, 155, 155));
                break;
            
            case(8):
                shape.setFillColor(sf::Color(0, 57, 7));
                break;
            case(9):
                shape.setFillColor(sf::Color(81, 0, 68));
                break;
            }
            int mouseX, mouseY;
            mouseX = sf::Mouse::getPosition(window).x - 10;
            mouseY = sf::Mouse::getPosition(window).y - 10;
            shape.setPosition(mouseX, mouseY);
            buffer.draw(shape);
            buffer.display();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            sf::CircleShape shape(30.f);
            shape.setFillColor(sf::Color::White);
            int mouseX, mouseY;
            mouseX = sf::Mouse::getPosition(window).x - 30;
            mouseY = sf::Mouse::getPosition(window).y - 30;
            shape.setPosition(mouseX, mouseY);
            buffer.draw(shape);
            buffer.display();
        }
        sf::Sprite bufferSprite(buffer.getTexture());
        window.draw(bufferSprite);
        sf::CircleShape shape(40.f);
        switch (color)
        {
        case(1):
            shape.setFillColor(sf::Color::Black);
            break;
        case(2):
            shape.setFillColor(sf::Color::Blue);
            break;
        case(3):
            shape.setFillColor(sf::Color::Red);
            break;
        case(4):
            shape.setFillColor(sf::Color::Green);
            break;
        case(5):
            shape.setFillColor(sf::Color::Yellow);
            break;
        case(6):
            shape.setFillColor(sf::Color::Cyan);
            break;
        case(7):
            shape.setFillColor(sf::Color(255, 155, 155));
            break;
        case(8):
            shape.setFillColor(sf::Color(0, 57, 7));
            break;
        case(9):
            shape.setFillColor(sf::Color(81, 0, 68));
            break;
        }
        window.draw(shape);
        window.display();
    }

    return 0;
}