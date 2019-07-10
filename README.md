# ofxRadonTransform
Radon Transform(Sinogram) of Image for Openframeworks.

![sino example]( https://github.com/bemoregt/ofxRadonTransform/blob/master/sino.png "example")

![sino example2]( https://github.com/bemoregt/ofxRadonTransform/blob/master/sino2.png "example2")

![sino example3]( https://github.com/bemoregt/ofxRadonTransform/blob/master/test3.png "example3")

![sino example4]( https://github.com/bemoregt/ofxRadonTransform/blob/master/test4.png "example4")

### Algorithm
- Sinogram is the Hough Transform for Grayscale Image.
- Sinogram is a kind of Reciprocal Transform, like a Fourier Transform.
- From Fourier Slice Theorem, Sinogram can be implemented from Polar 1D FFT.

### Dependency
- OpenFrameworks 0.10.1
- ofxCv
- ofxOpenCv
- ofxGUI
- XCode 10.12.x
- OSX Mojave

### Next Plan
- inverse Radon Transform for reconstruction
- Fast Hough Transform using Radon Transform
- 1D Entropy Plot.

### Reference
- Original Code from : https://github.com/fan2fan/OpenCV-Radon.git


