import numpy as np
import os
import cv2
import sys


def make_paths(path_to_image_folder):
	paths_to_images = os.listdir(path_to_image_folder)
	paths_to_images = [a if ('.png' in a.lower()) or ('.jpg' in a.lower()) else '' for a in paths_to_images]
	while '' in paths_to_images:
		paths_to_images.remove('')
	paths_to_images = [os.path.join(path_to_image_folder, a) for a in paths_to_images]
	return paths_to_images


if __name__ == '__main__':

	no_of_args = len(sys.argv)

	if no_of_args != 2:
		print('Please provide only the path to a folder with images')
		
	else:

		path_to_image_folder = sys.argv[1]
		paths = make_paths(path_to_image_folder)
		counter = 1
		face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

		for path in paths:
			try:
				image = cv2.imread(path, 1)

				faces = face_cascade.detectMultiScale(cv2.cvtColor(image, cv2.COLOR_BGR2GRAY), 1.1, 5)

				print('Found' , len(faces), 'faces')
				for n, face in enumerate(faces):
					# get the coordinates of a face
					x, y, w, h = face		
					if w > 128 and h > 128:	
						# crop out each face and save it in a separate .jpg file
						face_image = image[y:y+h, x:x+w]
						face_image = cv2.resize(face_image, (128, 128), interpolation = cv2.INTER_AREA)
						cv2.imwrite(os.path.join(path_to_image_folder, 'face%i.jpg' % counter), face_image)
						counter += 1
			except Exception as e:
				print(e)
	