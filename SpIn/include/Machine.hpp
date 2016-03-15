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

#ifndef SP_MACHIINE_HPP_
#define SP_MACHINE_HPP_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include <I8080/I8080.hpp>
#include <Display.hpp>

class Machine final
{
public:
    Machine();
    ~Machine() = default;
    Machine(const Machine&) = delete;
    Machine& operator = (const Machine&) = delete;

    void run();

private:
    sf::RenderWindow m_renderWindow;

    I8080::CPU m_processor;

    sf::Text m_infoText;
    sf::Font m_font;

    Display m_display;

    void update(float dt);
    void handleEvent(const sf::Event&);
    void draw();
};

#endif //SP_MACHINE_HPP_