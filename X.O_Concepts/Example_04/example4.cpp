


#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include "stb_image.h"
#include "stb_image_write.h"

int main() {

    const char* filename = "input.jpg";
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    if (image == NULL) {
        std::cout << "Failed to load image" << std::endl;
        return 1;
    }

    
     int small_height = 20;
     int small_width = 20;

   
     int output_height = height / small_height;
     int output_width = width / small_width;
     int output_channels = channels;

   
    unsigned char* output_image = new unsigned char[output_height * output_width * output_channels];

    
    for (int y = 0; y < output_height; y++) {
        for (int x = 0; x < output_width; x++) {
            for (int c = 0; c < output_channels; c++) {
                int sum = 0;
                for (int i = 0; i < small_height; i++) {
                    for (int j = 0; j < small_width; j++) {
                        int px = x * small_width + j;
                        int py = y * small_height + i;
                        sum += image[(py * width + px) * channels + c];
                    }
                }
                output_image[(y * output_width + x) * output_channels + c] = sum / (small_height * small_width);
            }
        }
    }

  
    const char* output_filename = "output.jpg";
    stbi_write_jpg(output_filename, output_width, output_height, output_channels, output_image, 100);

  
    

    return 0;
}