BP38Ergonomie
=============

Bachelor Praktikum 38 - Tablet App zur Ergonomie-Dokumentation

NOTE:
This is an experimental build to include the camera.
It only works with iOS. The necessary libraries for android can be found in assets/opencv/android.
This does not work due to an issue with including dynamic android libraries.
The corresponding classes are:
- Capture: Capture a frame as a Matrix, emit a signal with the matrix when done
- Converter: Convert the Matrix to a QImage and apply the needed transformations. Emit a Signal with the QImage
- ImageViewer: Show the Image as QPixmap on a QLabel. 
The Instances of these classes are connected in the CameraPopUp.

There is still some work to do to include the video capturing functionality and writing the pictures to a certain path on the local filesystem.
