# How to setup dataset for the FisherFaces classifier

1. Get images and put them in respective folders, one folder per person. Around 20 different images per person seems to be the sweetspot.
2. Resize images using "python3 detect_faces_and_resize.py name_of_the_image_folder"
3. Check if all the images have faces in them (sometimes the classifier fails and detects a T-shirt crease as a face) and delete the original images
4. Create a tree file by running "python create_tree.py dataset > tree.csv"
5. Open a newly generated tree.csv file and check if it was generated correctly
6. Take note of a label for the person(s) you want to set as positive faces (ones which can unlock the lock)
7. Go to src/FaceRecognitionThread.cpp line 16 and adjust the code to unlock when a correct label is detected