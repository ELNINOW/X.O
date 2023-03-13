


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    
    int width, height, channels;
    unsigned char* image = stbi_load("image.jpg", &width, &height, &channels, STBI_rgb);

    unsigned char* grayscale = new unsigned char[width * height];
    for (int i = 0; i < width * height; i++) {
        grayscale[i] = (unsigned char)(0.2989 * image[i * 3] + 0.5870 * image[i * 3 + 1] + 0.1140 * image[i * 3 + 2]);
    }

    stbi_write_jpg("grayscale.jpg", width, height, 1, grayscale, 100);

  
    stbi_image_free(image);
    delete[] grayscale;

    return 0;
}

