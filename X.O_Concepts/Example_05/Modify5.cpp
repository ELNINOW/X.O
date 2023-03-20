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

    int output_height = height/50 ;
    int output_width = width/50 ;

unsigned char *imageOut  = new unsigned char[height/40];
int sum {} ;


for (int a=0 ; a< output_height/50 ; a++){

    for (int k=0 ;k<output_height/50 ; k++){
   
    sum = 0;

        for (int j=0 ; j < output_width/50 ; j++ ){
        
            for (int i = 0; i < 50 ; i++) {

            sum = sum + image[i*j] ;

            } 

            

  imageOut[k*(output_height/50)]= sum 

        }
    }
}
    

        

    const char* output_filename = "output.jpg";
    stbi_write_jpg(output_filename, output_width, output_height, 1, output_image, 100);

    return 0;
}