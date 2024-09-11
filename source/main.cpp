#include "catmull_rom.h"
#include "tgp.h"
#include <iostream>

const unsigned int WINDOW_WIDTH  = 1920u;
const unsigned int WINDOW_HEIGHT = 1080u;

int main() {
    std::vector<vec2<float>> points = {{000.0f, 000.0f},
                                       {100.0f, 200.0f},
                                       {200.0f, 300.0f},
                                       {300.0f, 400.0f},
                                       {400.0f, 800.0f},
                                       {500.0f, 900.0f},
                                       {600.0f, 700.0f},
                                       {700.0f, 300.0f},
                                       {800.0f, 200.0f},
                                       {900.0f, 900.0f},
                                       {500.0f, 200.0f},
                                       {200.0f, 400.0f},
                                       {300.0f, 500.0f},
                                       {800.0f, 700.0f},
                                       {100.0f, 200.0f},
                                       {200.0f, 400.0f},
                                       {400.0f, 100.0f}};
    CatmullRom cr(points);

    TGP::Window window{WINDOW_WIDTH, WINDOW_HEIGHT, "Catmull Rom"};
    window.CreatePixelArea(0u, 0u, WINDOW_WIDTH, WINDOW_HEIGHT);

    std::vector<vec3<uint8_t>> pixels(WINDOW_HEIGHT * WINDOW_WIDTH);

    float t = 0.f;
    while (window.IsWindowOpen()) {
        window.UpdatePixelArea(0ull, pixels.data());

        vec2<float> result = cr[t];
        pixels[(unsigned int)std::round(result.x) + (unsigned int)std::round(result.y) * WINDOW_WIDTH] = {255.f, 255.f, 255.f};

        sf::sleep(sf::microseconds(1));

        window.Update();
        t += 0.01f;

        if (t > float(points.size() - 3))
            return 0;
    }
}
