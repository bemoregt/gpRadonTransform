# ofxRadonTransform
Radon Transform(Sinogram) of Image for Openframeworks.

![sino example]( https://github.com/bemoregt/ofxRadonTransform/blob/master/sino.png "example")

![sino example2]( https://github.com/bemoregt/ofxRadonTransform/blob/master/sino2.png "example2")

![sino example3]( https://github.com/bemoregt/ofxRadonTransform/blob/master/test3.png "example3")

![sino example4]( https://github.com/bemoregt/ofxRadonTransform/blob/master/test4.png "example4")

### Algorithm
- Sinogram is the Radon Transform for Grayscale Image.
- Sinogram is a kind of Reciprocal Transform, like a Fourier Transform.
- From Fourier Slice Theorem, Sinogram can be implemented from Polar 1D FFT.
- Like the Fourier space, Phase space, and Hough space, Thess second spaces are very important to get more detailed features by post processing. But most opensource libraries(OpenCV, etc) does not give 2nd spaces.
- This Second space is also images. so image processing for this 2nd space is very important. but most people just satisfied to get automatic (some imcomplet and many) output from libraries.
- In addition, This second spaces can be used to datasets for Deep learning to get invariantness, data compression, domain converting, data augmentation, etc.

### Dependency
- OpenFrameworks 0.10.1
- ofxCv
- ofxOpenCv
- ofxGUI
- XCode 10.12.x
- OSX Mojave

### Next Plan
- Elapsed Time Display per resolution.
- inverse Radon Transform for reconstruction
- Fast Hough Transform using Radon Transform
- 1D Entropy Plot.
- Blob Detection for labeling the peaks.

### Reference
- Original Code from : https://github.com/fan2fan/OpenCV-Radon.git


