How to use this sample:

1. Create your dataset consisting of at least two different persons, make sure you have more that one image.
	1.1 Place images of one person in one folder and images of another person in another folder.
2. Copy that folder to ./bin/Debug
3. Can use resize.py script to resize images because they all need to have matching dimensions. Just run "python3 resize_images.py" in the directory the images are in.
4. Open Terminal, navigate to ./bin/Debug and run "python create_csv.py > tree.csv". This will create a 'tree.csv" file where location of every picture is saved.
5. Again in Terminal, run "./FisherFaceDetector tree.csv". This will run the program and make one prediction of a random image. Result will be printed on screen.
6. The last command will also show three pictures - mean, eigenvector and attempt to reconstruc the face from the classifier.