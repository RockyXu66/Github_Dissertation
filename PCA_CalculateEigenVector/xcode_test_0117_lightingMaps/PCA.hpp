//
//  PCA.hpp
//  PCA_opengl_0522
//
//  Created by Yinghan Xu on 22/05/2017.
//  Copyright © 2017 Yinghan Xu. All rights reserved.
//

#ifndef PCA_hpp
#define PCA_hpp

#include <iostream>
#include <fstream>
#include <ctime>
#include <Eigen/Eigen>
using namespace Eigen;
using namespace std;

class PCA{
    
public:
    int num;        // Number of images
    int dim;        // Dimension of one image
    int pca_dim;    // PCA dimension of the image
    string fileName;
    
    unsigned char* CalculateEigen(vector<unsigned char*> images, int width, int height);
    void Mean(MatrixXd data_r, MatrixXd data_g, MatrixXd data_b, unsigned char* meanImage);
    MatrixXd Eigen(MatrixXd data, unsigned char* newImage, string name, string fileName);
    MatrixXd Reconstruction(MatrixXd data, string fileName);
    
private:
    // Used for sortting eigen value
    MatrixXd BubbleSort(MatrixXd eigenValues, int num);
    
};

#endif /* PCA_hpp */
