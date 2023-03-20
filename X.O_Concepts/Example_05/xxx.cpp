#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    int width, height, channels;
    unsigned char* img = stbi_load("image.jpg", &width, &height, &channels, 1);
    if (img == nullptr) {
        std::cerr << "Error loading image!" << std::endl;
        return 1;
    }

    // create a 1D array to store the image data
    unsigned char* img1D = new unsigned char[width * height];

    // copy the image data from the 2D array to the 1D array
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            img1D[y * width + x] = img[y * width + x];
        }
    }

    // write the 1D image data to a PNG file
    stbi_write_png("image_1d.png", width, height, 1, img1D, width);

    // free memory
    stbi_image_free(img);
    delete[] img1D;

    return 0;
}
