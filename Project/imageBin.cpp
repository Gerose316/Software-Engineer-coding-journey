
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

// this will throw an error if you don't have the bitmap library installed
// so be sure to do that before uncommenting this #include line
#include "bitmap_image.hpp"






int main(int argc, char *argv[]) {
    // get a string containing the image name
    // this is necessary because the bitmap_image
    // class expects a string as an argument
    
    std::string input(argv[1]);

    std::string output(argv[2]);
    bitmap_image image(input);



    image.convert_to_grayscale();
    








  unsigned int brandNew = image.width() * image.height();
  int lard = 0;
  for (unsigned int i = 0; i < image.width(); i++){
    for (unsigned int j = 0; j < image.height(); j++){
        int  sting = (image.red_channel(i,j));;
        lard += sting;

           
    }

  }
  
double start =  lard / brandNew;

  for(unsigned int i = 0; i < image.width(); i++){
    for( unsigned int j = 0; j < image.height(); j++){
      int stingr = (image.red_channel(i,j));;
      
      if (stingr < start){
          image.set_pixel(i,j, 0 , 0 ,0);
        }else{
          image.set_pixel(i,j, 255 , 255 ,255);
        }
    }
  }


    // TODO:
    // your implementation of problem #4 should be done in this
    // file. Feel free to create functions etc. if you feel that
    // it will help you.
   
    
    image.save_image(output);
   

  // professor conti ----- >>>>>>>>> input The goal should be to export the black and white .bmp file, so at some point you will need to have the below statement at the end of your code. This is what gradescope is looking for!
    return 0;
}