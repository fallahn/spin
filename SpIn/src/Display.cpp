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
#include <functional>
#include <iostream>

namespace
{
    const sf::Uint32 width = 256u;
    const sf::Uint32 height = 224u;

    const std::string shader =
        "#version 120\n"
        "uniform sampler2D u_baseTexture;\n"
        "uniform sampler2D u_overlayTexture;\n"
        "uniform sampler2D u_backgroundTexture;\n"
        "void main()\n"
        "{\n"
        "  vec4 baseColour = texture2D(u_baseTexture, gl_TexCoord[0].xy);\n"
        "  baseColour.a = 0.5;\n"
        "  vec4 overlayColour = texture2D(u_overlayTexture, gl_TexCoord[0].xy);\n"
        "  vec4 backgroundColour = texture2D(u_backgroundTexture, gl_TexCoord[0].xy);\n"
        "  gl_FragColor = (baseColour * overlayColour) + (backgroundColour * 2.0);\n"
        "}\n";
}

Display::Display()
{
    sf::Image img;
    img.create(width, height, sf::Color::White);
    m_baseTexture.loadFromImage(img);

    setOrigin(width / 2.f, height / 2.f);
    setScale(2.f, 2.f);
    setRotation(-90.f);

    std::memset(m_buffer.data(), 255, m_buffer.size());

    m_vertexArray[1].position = { static_cast<float>(width), 0.f };
    m_vertexArray[1].texCoords = m_vertexArray[1].position;
    m_vertexArray[2].position = { static_cast<float>(width), static_cast<float>(height) };
    m_vertexArray[2].texCoords = m_vertexArray[2].position;
    m_vertexArray[3].position = { 0.f, static_cast<float>(height) };
    m_vertexArray[3].texCoords = m_vertexArray[3].position;

    //ok so SFML forces us to use RGBA textures (ideally we'd want GL_LUMINENCE or so)
    //but because we're emulating we'll "emulate" the original overlay with a custom
    //texture and then multiply it (with a shader for performance)
    img.create(width, height, sf::Color::White);

    std::function<void(std::uint16_t, std::uint16_t, std::uint16_t, std::uint16_t, sf::Color)> updateColour =
        [&img](std::uint16_t x , std::uint16_t y, std::uint16_t w, std::uint16_t h, sf::Color c)
    {
        for (auto j = y; j < y + h; ++j)
        {
            for (auto i = x; i < x + w; ++i)
            {
                img.setPixel(i, j, c);
            }
        }
    };

    updateColour(222, 0, 34, 224, sf::Color::Yellow);
    updateColour(208, 0, 12, 224, sf::Color::Red);
    updateColour(18, 0, 56, 224, sf::Color::Green);
    updateColour(0, 0, 16, 136, sf::Color::Green);

    m_overlayTexture.loadFromImage(img);

    m_shader.loadFromMemory(shader, sf::Shader::Fragment);
    m_shader.setParameter("u_baseTexture", m_baseTexture);
    m_shader.setParameter("u_overlayTexture", m_overlayTexture);

    m_backgroundTexture.loadFromFile("assets/images/background.png");
    m_shader.setParameter("u_backgroundTexture", m_backgroundTexture);
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


    sf::Texture::bind(&m_baseTexture);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer.data());
    sf::Texture::bind(nullptr);
}


//private
void Display::draw(sf::RenderTarget& rt, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_baseTexture;
    states.shader = &m_shader;
    rt.draw(m_vertexArray.data(), m_vertexArray.size(), sf::Quads, states);
}