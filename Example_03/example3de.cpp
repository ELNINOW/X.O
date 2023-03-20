#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>

using namespace std;

int main() {
    int width1, height1, channels1;
    unsigned char* img1 = stbi_load("large_image.jpg", &width1, &height1, &channels1, 0);

    int width2, height2, channels2;
    unsigned char* img2 = stbi_load("small_image.jpg", &width2, &height2, &channels2, 0);

    int row, col;
    cout << "Enter the row and column values for the smaller image: ";
    cin >> row >> col;

    if (row + height2 > height1 || col + width2 > width1) {
        cout << "Error: the smaller image is out of bounds." << endl;
        exit(1);
    }  

    unsigned char* img2_flipped = new unsigned char[width2 * height2 * channels2];
    for (int i = 0; i < height2; i++) {
        memcpy(&img2_flipped[i * width2 * channels2], &img2[(height2 - i - 1) * width2 * channels2], width2 * channels2);
    }

    for (int i = 0; i < height2; i++) {
        for (int j = 0; j < width2; j++) {
            for (int k = 0; k < channels2; k++) {
                img1[((row + i) * width1 + (col + j)) * channels1 + k] = img2_flipped[(i * width2 + j) * channels2 + k];
            }
        }
    }

    stbi_write_png("output.jpg", width1, height1, channels1, img1, width1 * channels1);


    return 0;
}