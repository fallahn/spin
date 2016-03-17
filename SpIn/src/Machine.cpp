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

#include <assert.h>

Machine::Machine()
    : m_shiftValue  (0),
    m_shiftOffset   (0)
{
    if (m_font.loadFromFile("assets/fonts/VeraMono.ttf"))
    {
        m_infoText.setFont(m_font);
        m_infoText.setPosition(15.f, 15.f);
        m_infoText.setCharacterSize(12u);
    }

    m_display.setPosition(400.f, 300.f);

    I8080::CPU::InputHandler ih = [this](Byte port)
    {
        switch (port)
        {
        default: break;
        case 1:
            return m_ports[1];
            break;
        case 2:
            return m_ports[2];
            break;
        case 3:
            return static_cast<Byte>(((m_shiftValue << m_shiftOffset) & 0xFF));
            break;
        }
    };
    m_processor.setInputHandler(ih);

    I8080::CPU::OutputHandler oh = [this](Byte port, Byte value)
    {
        switch (port)
        {
        default: break;
        case 2:
            m_shiftOffset = value;
            break;
        case 3:
            //sound
            //bit 1 = spaceship sound (looped)
            //bit 2 = Shot
            //bit 3 = Your ship hit
            //bit 4 = Invader hit
            //bit 5 = Extended play sound
            break;
        case 4:
            m_shiftValue = (m_shiftValue << 8) | value;
            break;
        case 5:
            //bit 0 = invaders sound 1
            //bit 1 = invaders sound 2
            //bit 2 = invaders sound 3
            //bit 3 = invaders sound 4
            //bit 4 = spaceship hit
            //bit 5 = amplifier enabled/disabled
            break;
        }
    };
    m_processor.setOutputHandler(oh);
    std::memset(m_ports.data(), 0, I8080::PORT_COUNT);
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
    //33,333 * 60 = 1,999,980
    //as close as we get to 2MHz
    m_processor.update(17000);
    m_processor.raiseInterrupt(1);
    m_processor.update(16333);
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
            setFlag(1, 0);
            break;
        case sf::Keyboard::Num1:
            //player 2 start
            setFlag(1, 2);
            break;
        case sf::Keyboard::Num2:
            //player 1 start
            setFlag(1, 1);
            break;
        case sf::Keyboard::Space:
            //player 1 shoot
            setFlag(1, 4);
            break;
        case sf::Keyboard::A:
            //player 1 left
            setFlag(1, 5);
            break;
        case sf::Keyboard::D:
            //player 1 right
            setFlag(1, 6);
            break;
        case sf::Keyboard::LControl:
            //player 2 shoot
            setFlag(2, 4);
            break;
        case sf::Keyboard::Left:
            //player 2 left
            setFlag(2, 5);
            break;
        case sf::Keyboard::Right:
            //player 2 right
            setFlag(2, 6);
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
            unsetFlag(1, 0);
            break;
        case sf::Keyboard::Num1:
            unsetFlag(1, 2);
            break;
        case sf::Keyboard::Num2:
            unsetFlag(1, 1);
            break;
        case sf::Keyboard::Space:
            //player 1 shoot
            unsetFlag(1, 4);
            break;
        case sf::Keyboard::A:
            //player 1 left
            unsetFlag(1, 5);
            break;
        case sf::Keyboard::D:
            //player 1 right
            unsetFlag(1, 6);
            break;
        case sf::Keyboard::LControl:
            //player 2 shoot
            unsetFlag(2, 4);
            break;
        case sf::Keyboard::Left:
            //player 2 left
            unsetFlag(2, 5);
            break;
        case sf::Keyboard::Right:
            //player 2 right
            unsetFlag(2, 6);
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

void Machine::setFlag(std::size_t port, Byte flag)
{
    assert(flag < 8);
    m_ports[port] |= (1 << flag);
}

void Machine::unsetFlag(std::size_t port, Byte flag)
{
    assert(flag < 8);
    m_ports[port] &= ~(1 << flag);
}