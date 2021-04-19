# Code::Blocks setup

1. Open "ComplicatedBikeLock.cbp" file using Code::Blocks IDE
2. In the top row click Project->Build options...
3. On the left hand pane of the new window left-click on ComplicatedBikeLock
4. Under "Linker settings" tab make sure the "/usr/lib/libWiringPi.so" is added to the "Link libraries " text field and "`pkg-config --libs --cflags opencv4`" are there (note the quotes in the second setting) is in "Other linker options".
5. Under "Search directories" tab select "Compiler subtab" and make sure the "/usr/local/include/opencv4" is added.
6. On the left-hand pane, just under ComplicatedBikeLock, select "Debug" by left-clicking it.
7. Under "Compiler Settings" tab go to "Other compiler options" and make sure "-pthread" is added. If not present, add it there by copying or typing.
8. Under "Linker settings" tab go to "Other linker options" window and make sure lines "-pthread" and "`pkg-config --libs --cflags opencv4`" are there (note the quotes in the second setting)
9. Under "Search directories" tab "Compiler" subtab ensure that "include" and "/usr/include/opencv2" libraries are linked and present.
10. That's it! Code::Blocks is set up and ready to go! Only ting left to set up is the FisherFaceRecognizer...


# How to setup dataset for the FisherFaces classifier

1. Get images and put them in respective folders, one folder per person. Around 20 different images per person seems to be the sweetspot.
2. Resize images using "python3 detect_faces_and_resize.py name_of_the_image_folder"
3. Check if all the images have faces in them (sometimes the classifier fails and detects a T-shirt crease as a face) and delete the original images
4. Create a tree file by running "python create_tree.py dataset > tree.csv"
5. Open a newly generated tree.csv file and check if it was generated correctly - it should contain a bunch of lines looking something like this - "resources/dataset/Name1/pic1_of_name1.jpg;0"
6. Take note of a label for the person(s) you want to set as positive faces (ones which can unlock the lock)
7. Go to src/FaceRecognitionThread.cpp line 16 and adjust the code accordingly to unlock when a correct label is detected
