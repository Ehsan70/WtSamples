# DropletMeasurement
This repo performs droplet measurement using imaging processing. 

## Runing the code on Jetson TX1

Note that depending on the machine you are compiling, use one the following commands:  

Below is tested on Jetson TX1

```
sudo g++ -o nav10 nav10.cpp ./DropletMeasurement/CameraHandler.cpp ./DropletMeasurement/CameraHandler.h -L/usr/lib -I/usr/include -I/usr/include/opencv -L/usr/local/cuda-8.0/lib64 -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab -latomic -lrt -lpthread -lm -ldl -lueye_api -lwt -lwthttp -std=c++11 -lboost_signals -lboost_system
```

Below is tested on Ubuntu System 76 (Ehsan's Laptop)
```
sudo g++ -o nav10 nav10.cpp ./DropletMeasurement/CameraHandler.cpp ./DropletMeasurement/CameraHandler.h ./DropletMeasurement/FlashHandler.cpp ./DropletMeasurement/FlashHandler.h -L/usr/lib -I/usr/include -I/usr/include/opencv -L/usr/local/cuda-8.0/lib64 -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab -latomic -lrt -lpthread -lm -ldl -lueye_api -lwt -lwthttp -std=c++11 -lboost_signals -lboost_system 
```

```
sudo g++ -o nav10 nav10.cpp ./DropletMeasurement/CameraHandler.cpp ./DropletMeasurement/CameraHandler.h ./DropletMeasurement/FlashHandler.cpp ./DropletMeasurement/FlashHandler.h -L/usr/lib -I/usr/include -I/usr/include/opencv -L/usr/local/cuda-8.0/lib64 -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab -latomic -lrt -lpthread -lm -ldl -lueye_api -lwt -lwthttp -std=c++11 -lboost_signals -lboost_system `pkg-config opencv --cflags --libs`
```
Compiles all the Utills, camera, flash and config reader classes. Links the boosts and opencv classes.
```
sudo g++ -o nav10 nav10.cpp ./DropletMeasurement/CameraHandler.cpp ./DropletMeasurement/CameraHandler.h ./DropletMeasurement/FlashHandler.cpp ./DropletMeasurement/FlashHandler.h ./DropletMeasurement/MyUtils.cpp ./DropletMeasurement/MyUtils.h ./DropletMeasurement/ConfigReader.cpp ./DropletMeasurement/ConfigReader.h -L/usr/lib -I/usr/include -I/usr/include/opencv -L/usr/local/cuda-8.0/lib64 -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab -latomic -lrt -lpthread -lm -ldl -lueye_api -lwt -lwthttp -std=c++11 -lboost_signals -lboost_system -lboost_filesystem `pkg-config opencv --cflags --libs`
```

Compiles all the Utils, camera, flash, imageProcessing, and config reader classes. LInks boosts and opencv classes. 
```
sudo g++ -o nav10 nav10.cpp ./DropletMeasurement/CameraHandler.cpp ./DropletMeasurement/CameraHandler.h ./DropletMeasurement/FlashHandler.cpp ./DropletMeasurement/FlashHandler.h ./DropletMeasurement/MyUtils.cpp ./DropletMeasurement/MyUtils.h ./DropletMeasurement/ConfigReader.cpp ./DropletMeasurement/ConfigReader.h ./DropletMeasurement/ImageProcessor.cpp ./DropletMeasurement/ImageProcessor.h -L/usr/lib -I/usr/include -I/usr/include/opencv -L/usr/local/cuda-8.0/lib64 -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab -latomic -lrt -lpthread -lm -ldl -lueye_api -lwt -lwthttp -std=c++11 -lboost_signals -lboost_system -lboost_filesystem `pkg-config opencv --cflags --libs`
```

In order to run, execute:
`sudo ./nav10 --docroot . --http-address 0.0.0.0 --http-port 9090` 

Then use the link `0.0.0.0:9090`

## Files:
This section explains the purpose each file. 

### Resources Folder
Images and CSS formatting files are saved in this folder.

## Resources:

Installing OpenCV 3.1.0 on Ubuntu: http://embedonix.com/articles/image-processing/installing-opencv-3-1-0-on-ubuntu/

Setting up OpenCV 3.0.0 + JetBrains CLion on Debian-based Linux Distros: https://www.youtube.com/watch?v=i1K9rXiei9I 

## Tags/Releases:
This section explains the different tags that are created in the repo. 

### V0.1
This tag contains a stable version of canny edge detection. Tracker bars are added for th input parameters of the canny edge detection. It perfroms no GPU optimization yet. 

### v0.1.1
This tag runs an automated test in order to find the optimum parameters for canny edge detection. The input images should be saved in a directory and the address is required by the program. The output images and the report is stored in a fodler called `Results`. 

### v0.2
This tag contains a stable of Blob detection using [SimpleBlobDetector](https://www.learnopencv.com/blob-detection-using-opencv-python-c/) class. Tracker bars are added for th input parameters of the blob detection. It perfroms no GPU optimization yet. 

