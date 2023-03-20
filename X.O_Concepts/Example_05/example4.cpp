#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    int width, height, channels;
    unsigned char* img = stbi_load("grayscale.jpg", &width, &height, &channels, 1);
    if (img == nullptr) {
        std::cerr << "Error loading image!" << std::endl;
        return 1;
    }

    // create a new image buffer that's 10 times larger
    unsigned char* scaledImg = new unsigned char[width * 10 * height * 10];

    // scale the image by a factor of 10 using nearest neighbor interpolation
    for (int y = 0; y < height * 10; y++) {
        for (int x = 0; x < width * 10; x++) {
            int srcX = x / 10;
            int srcY = y / 10;
            scaledImg[y * width * 10 + x] = img[srcY * width + srcX];
        }
    }

    // write the scaled image to disk
    stbi_write_jpg("scaled_image.jpg", width * 10, height * 10, 1, scaledImg, 100);

    // free memory
    stbi_image_free(img);
    delete[] scaledImg;

    return 0;
}