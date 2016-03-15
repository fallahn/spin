/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

SpIn - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#include <Machine.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

Machine::Machine()
{
    if (m_font.loadFromFile("assets/fonts/VeraMono.ttf"))
    {
        m_infoText.setFont(m_font);
        m_infoText.setPosition(15.f, 15.f);
        m_infoText.setCharacterSize(12u);
    }

    m_display.setPosition(400.f, 300.f);
}

//public
void Machine::run()
{
    m_processor.loadROM("assets/roms/invaders.h", 0);
    m_processor.loadROM("assets/roms/invaders.g", 0x0800, false);
    m_processor.loadROM("assets/roms/invaders.f", 0x1000, false);
    m_processor.loadROM("assets/roms/invaders.e", 0x1800, false);

    m_renderWindow.create({ 800, 600 }, "SpIn");
    m_renderWindow.setFramerateLimit(120);

    sf::Clock frameClock;

    while (m_renderWindow.isOpen())
    {
        sf::Event evt;
        while (m_renderWindow.pollEvent(evt))
        {
            if (evt.type == sf::Event::Closed)
            {
                m_renderWindow.close();
            }
            handleEvent(evt);
        }

        static const float timestep = 1.f / 60.f;
        static float accumulator = 0.f;
        accumulator += frameClock.restart().asSeconds();
        while (accumulator >= timestep)
        {
            update(timestep);
            accumulator -= timestep;
        }

        draw();
    }
}


//private
void Machine::update(float dt)
{
    //34000 * 60 = 2,040,000
    //as close as we get to 2MHz
    m_processor.update(17000);
    m_processor.raiseInterrupt(1);
    m_processor.update(17000);
    m_processor.raiseInterrupt(2);

    m_display.updateBuffer(m_processor.getVRAM());
    m_infoText.setString(m_processor.getInfo());
}

void Machine::handleEvent(const sf::Event& evt)
{
    if (evt.type == sf::Event::KeyPressed)
    {
        switch (evt.key.code)
        {
        default: break;
        case sf::Keyboard::Num0:
            //coin insert
            m_processor.setFlag(1, 0);
            break;
        case sf::Keyboard::Num1:
            //player 2 start
            m_processor.setFlag(1, 2);
            break;
        case sf::Keyboard::Num2:
            //player 1 start
            m_processor.setFlag(1, 1);
            break;
        case sf::Keyboard::Space:
            //player 1 shoot
            m_processor.setFlag(1, 4);
            break;
        case sf::Keyboard::A:
            //player 1 left
            m_processor.setFlag(1, 5);
            break;
        case sf::Keyboard::D:
            //player 1 right
            m_processor.setFlag(1, 6);
            break;
        case sf::Keyboard::LControl:
            //player 2 shoot
            m_processor.setFlag(2, 4);
            break;
        case sf::Keyboard::Left:
            //player 2 left
            m_processor.setFlag(2, 5);
            break;
        case sf::Keyboard::Right:
            //player 2 right
            m_processor.setFlag(2, 6);
            break;
        }
    }
    else if (evt.type == sf::Event::KeyReleased)
    {
        switch (evt.key.code)
        {
        default:break;
        case sf::Keyboard::Escape:
            m_renderWindow.close();
            break;
            /*case sf::Keyboard::Space:
            m_processor.update(1);
            break;
            case sf::Keyboard::Z:
            m_processor.update(500);
            break;
            case sf::Keyboard::X:
            m_processor.update(1000);
            break;
            case sf::Keyboard::C:
            m_processor.update(5000);
            break;*/
        case sf::Keyboard::Num0:
            m_processor.unsetFlag(1, 0);
            break;
        case sf::Keyboard::Num1:
            m_processor.unsetFlag(1, 2);
            break;
        case sf::Keyboard::Num2:
            m_processor.unsetFlag(1, 1);
            break;
        case sf::Keyboard::Space:
            //player 1 shoot
            m_processor.unsetFlag(1, 4);
            break;
        case sf::Keyboard::A:
            //player 1 left
            m_processor.unsetFlag(1, 5);
            break;
        case sf::Keyboard::D:
            //player 1 right
            m_processor.unsetFlag(1, 6);
            break;
        case sf::Keyboard::LControl:
            //player 2 shoot
            m_processor.unsetFlag(2, 4);
            break;
        case sf::Keyboard::Left:
            //player 2 left
            m_processor.unsetFlag(2, 5);
            break;
        case sf::Keyboard::Right:
            //player 2 right
            m_processor.unsetFlag(2, 6);
            break;
        }
    }
}

void Machine::draw()
{
    m_renderWindow.clear(sf::Color::Blue);
    m_renderWindow.draw(m_display);
    m_renderWindow.draw(m_infoText);
    m_renderWindow.display();
}