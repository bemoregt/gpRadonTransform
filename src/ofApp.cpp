#include "ofApp.h"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;

using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    before.load("/Users/kerbal/Desktop/pp.png");
    Mat src = toCv(before);
    Mat src2;
    cvtColor(src, src2, CV_BGR2GRAY);
    
    double t = getTickCount();
    
    Mat dst = src2.clone();
    
    dst.convertTo(dst,CV_32FC1);
    int angle=360;
    Mat radon_image = Mat(dst.rows,angle,CV_32FC1);
    float center = (dst.rows/2.);
    
    float shift0[] = {  1, 0, -center,
        0, 1, -center,
        0, 0, 1};
    float shift1[] = {  1, 0, center,
        0, 1, center,
        0, 0, 1};
    Mat m0 = Mat(3,3,CV_32FC1,shift0);
    Mat m1 = Mat(3,3,CV_32FC1,shift1);
    float *theta = new float[angle];//旋转角度
    for(int t=0;t<360;t++)
    {
        theta[t]=t*CV_PI/angle;
        float R[] = {cos(theta[t]), sin(theta[t]), 0,
            -sin(theta[t]), cos(theta[t]), 0,
            0, 0, 1};
        Mat mR = Mat(3,3,CV_32FC1,R);
        Mat rotation = m1*mR*m0;
        Mat rotated;
        warpPerspective(dst,rotated,rotation,cv::Size(dst.rows,dst.cols),WARP_INVERSE_MAP);
        for(int j=0;j<rotated.cols;j++)
        {
            float *p1 = radon_image.ptr<float>(j);
            for(int i=0;i<rotated.rows;i++)
            {
                float *p2 = rotated.ptr<float>(i);
                p1[t] += p2[j];
            }
        }
        
        
    }
    cout<< (double)(getTickCount()-t)/getTickFrequency()<<endl;
    //normalize(radon_image,radon_image,0,1,CV_MINMAX);
    Mat radon2;
    normalize(radon_image, radon2, 255, 0, NORM_MINMAX, CV_8U);
    
    //imshow("My Radon Transform",radon_image);
    toOf(radon2, after);
    after.update();
    
    ofSetWindowTitle("Sinogram Of Image");
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    before.draw(0, 0, 512, 512);
    after.draw(512, 0, 512, 512);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
