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
#include <chrono>
#include <opencv2/opencv.hpp>
using namespace Eigen;
using namespace std;
using namespace cv;

// Number of components to keep for the PCA:
const bool FPS_record = false;

//const int smallerNum = 90, cell_dimension = 30;
//const int smallerNum = 60, cell_dimension = 20;
const int smallerNum = 25, cell_dimension = 10;
//const int smallerNum = 10, cell_dimension = 5;
const int num_components = 7;

const int image_num = 899;      //120
const int image_width = 720;   //960
const int image_height = image_width;  //960

//const String oneImagePath = "/Users/yinghanxu/Study/Dissertation_ResultData/Data_Set/artifix_120/artifix1.png";
const String oneImagePath = "/Users/yinghanxu/Study/Dissertation_ResultData/Data_Set/head_900(resolution"+to_string(image_width)+")/head11.png";
const String d_name = "head";

const String m_name = to_string(smallerNum)+"_cells"+to_string(cell_dimension);
const String file_PCA_b = "/Users/yinghanxu/Study/Dissertation_ResultData/ResultPCA_cells/PCA"+m_name+"_b("+d_name+to_string(image_width)+").txt";
const String file_PCA_g = "/Users/yinghanxu/Study/Dissertation_ResultData/ResultPCA_cells/PCA"+m_name+"_g("+d_name+to_string(image_width)+").txt";
const String file_PCA_r = "/Users/yinghanxu/Study/Dissertation_ResultData/ResultPCA_cells/PCA"+m_name+"_r("+d_name+to_string(image_width)+").txt";
const String file_Scores_b = "/Users/yinghanxu/Study/Dissertation_ResultData/ResultPCA_cells/Scores"+m_name+"_b("+d_name+to_string(image_width)+").txt";
const String file_Scores_g = "/Users/yinghanxu/Study/Dissertation_ResultData/ResultPCA_cells/Scores"+m_name+"_g("+d_name+to_string(image_width)+").txt";
const String file_Scores_r = "/Users/yinghanxu/Study/Dissertation_ResultData/ResultPCA_cells/Scores"+m_name+"_r("+d_name+to_string(image_width)+").txt";

class PCA_{
    
public:
    int num;        // Number of images
    int cellImage_num; //Number of cells
    int dim;        // Dimension of one image
    int pca_dim;    // PCA dimension of the image
    string fileName;
    MatrixXd EigenVectors_Red, EigenVectors_Green, EigenVectors_Blue;
    MatrixXd oneImage_scores_Red, oneImage_scores_Green, oneImage_scores_Blue;
    vector<MatrixXd> wholeImage_scores_Red, wholeImage_scores_Green, wholeImage_scores_Blue;
    vector<MatrixXd> oneVecs_Red, oneVecs_Green, oneVecs_Blue;
    MatrixXd means_Red, means_Green, means_Blue;
    
    vector<PCA> pcas_b, pcas_g, pcas_r;
    Mat scores_b, scores_g, scores_r;
    
    void load();
    
    vector<unsigned char*> reconstruct(int imageIndex, unsigned char* newImage, unsigned char* smoothedNewImage, Mat bgr[3], int cell_num, int x, int y, bool isBlur, int kernelSize);
    
    unsigned char* CalculateEigen(vector<unsigned char*> images, int width, int height);
    
    void Mean(MatrixXd data_r, MatrixXd data_g, MatrixXd data_b, unsigned char* meanImage);
    
    MatrixXd Eigen(MatrixXd data, unsigned char* newImage, string name, string fileName);
    
    MatrixXd Reconstruction(MatrixXd data, string fileName);
    
    vector<MatrixXd> WholeReconstruction(string fileName, string meanFileName, string scoresFileName, int imageIndex, string channel);
    
    void SaveHighEigen(string newFileName, string oldFileName, int highDimension);
    
    void Mean(vector<MatrixXd> data, string fileName);
    
    void CalScores(vector<MatrixXd> whole_data, string fileName, string meanFileName, string newFileName);
    
    unsigned char* Reconstruction_RealTime(unsigned char* image, int imageIndex, int width, int height);
    
    vector<MatrixXd> WholeReconstruction_RealTime(string meanFileName, string scoresFileName, int imageIndex, string channel);
    
private:
    // Used for sortting eigen value
    MatrixXd BubbleSort(MatrixXd eigenValues, int num);
    
};

#endif /* PCA_hpp */





