# this sample code is taken from pythonprogramming.net/raspberry-pi-camera-opencv-face-detection-tutorial
# it showcases the face detection (not recognition!) algorithm using RPi and PiCam on the hardware side and OpenCV2 and picamera libraries on the software side.
# input is an image taken with a PiCam and the output is a JPEG image named result.jpg

import numpy as np
import io
import picamera
import cv2

print('done importing')

stream = io.BytesIO()

# get a low res pic (should be fast)
with picamera.PiCamera() as camera:
	camera.resolution = (640, 480)
	camera.capture(stream, format='jpeg')

buff = np.frombuffer(stream.getvalue(), dtype=np.uint8)

# opencv image
image = cv2.imdecode(buff, 1)

# load cascade for detecting faces
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
# the cascade classifier can be downloaded from https://raw.githubusercontent.com/shantnu/Webcam-Face-Detect/master/haarcascade_frontalface_default.xml

# convert to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# look for faces matching descriptions from the cascade file
faces = face_cascade.detectMultiScale(gray, 1.1, 5)

#array_to_pickle = [faces, image]
#with open('faces.pickle', 'wb') as f:
#	pickle.dump(array_to_pickle, f)

print('Found' , len(faces), 'faces')

# draw a rectangle around every found face
for n, face in enumerate(faces):
	# get the coordinates of a face
	x, y, w, h = face
	
	# crop out each face and save it in a separate .jpg file
	face_image = image[y:y+h, x:x+w]
	cv2.imwrite('face%i.jpg' % n, face_image)
	
	# draw a rectangle around each face
	cv2.rectangle(image, (x, y), (x+w, y+h), (255, 255, 0), 2)
	
cv2.imwrite('result.jpg', image)

# cv2.imshow('output', image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()



