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
}

//public
void Machine::run()
{
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
            else if (evt.type == sf::Event::KeyReleased)
            {
                switch (evt.key.code)
                {
                default:break;
                case sf::Keyboard::Escape:
                    m_renderWindow.close();
                    break;
                }
            }
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
    m_processor.update(34000);

    //TODO split updates and raise display interrupts

    m_infoText.setString(m_processor.getInfo());
}

void Machine::draw()
{
    m_renderWindow.clear(sf::Color::Blue);
    m_renderWindow.draw(m_infoText);
    m_renderWindow.display();
}