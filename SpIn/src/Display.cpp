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

#include <Display.hpp>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/OpenGL.hpp>

#include <cstring>

Display::Display()
{
    sf::Image img;
    img.create(256, 224, sf::Color::White);
    m_texture.loadFromImage(img);
    m_sprite.setTexture(m_texture);

    setOrigin(128.f, 112.f);
    setScale(2.f, 2.f);
    setRotation(-90.f);

    std::memset(m_buffer.data(), 255, m_buffer.size());
}

//public 
void Display::updateBuffer(const std::uint8_t* buffer)
{
    //pixels are packed 8 per byte so need to be translated to local buffer
    for (auto i = 0, b = 0; i < 7168; ++i)
    {
        for (auto j = 0; j < 8; ++j)
        {
            std::uint8_t val = (buffer[i] & (1 << j)) ? 0xFF : 0;
            m_buffer[b++] = val;
            m_buffer[b++] = val;
            m_buffer[b++] = val;
            m_buffer[b++] = 0xFF;
        }
    }


    sf::Texture::bind(&m_texture);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 256, 224, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer.data());
    sf::Texture::bind(nullptr);
}


//private
void Display::draw(sf::RenderTarget& rt, sf::RenderStates states) const
{
    states.transform *= getTransform();
    rt.draw(m_sprite, states);
}