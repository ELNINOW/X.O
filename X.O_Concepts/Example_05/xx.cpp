#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;

int main() {

    const char* filename = "grayscale.jpg";
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    cout << width <<  endl;
    cout << height <<  endl;
    cout << channels <<  endl;

    if (image == NULL) {
        std::cout << "Failed to load image" << std::endl;
        return 1;
    }

    int output_height = 1; 
    int output_width = width; 

    unsigned char* output_image = new unsigned char[output_width];

        int sum = 0;
        for (int y = 0; y < width; y++) {
            sum += image[(y * width )];
            output_image[y] = sum / width;
        }
        
    

    const char* output_filename = "output.jpg";
    stbi_write_jpg(output_filename, output_width, output_height, 1, output_image, 100);

    return 0;
}