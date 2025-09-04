#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>


int main() {
   
    int testcase;
    std::cin >> testcase;
    std::vector<double> x1;
    std::vector<double> y2;
    for(int i = testcase; i > 0; i--){
        double x = 0.0 ,y = 0.0;
        double angle = 90.0;

        int segment;
        std::cin >> segment;
        double direction, rotation;

        for(int j = 0; j < segment; j++){
            std::cin >> rotation >> direction;
            angle += rotation;
            double rad = angle * M_PI / 180.0;
            x += direction * cos(rad);
            y += direction * sin(rad);

        }
       


    x1.push_back(x);
    y2.push_back(y);
    }
    for(int i = 0; i < x1.size(); i++ ){
        std::cout << std::fixed << std::setprecision(6) << x1[i] << " " << y2[i] << std::endl;
    }
}