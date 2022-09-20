import cv2 as cv
import numpy as np
import tensorflow as tf
import serial
import time

cam = cv.VideoCapture(0)

pb = './saved-models/model1.5.h5'
classes = ['fork', 'neither', 'spoon']

#arduino = serial.Serial("/dev/cu.usbmodem1401", baudrate=2000000)

model = tf.keras.models.load_model(pb)
model.summary()

color = (0,0,255)
scale = 1.5
font = cv.FONT_HERSHEY_SIMPLEX
prev = ''
count = 0

while True:

    re_val, img = cam.read()

    blob = cv.dnn.blobFromImage(img, size=(250,250), swapRB=True, crop=True)
    arr = np.array([blob])
    arr = arr.reshape(1,250,250,3)
    data = tf.constant(arr)

    preds = model.predict(data, verbose='auto')
    pred = np.argmax(preds)

    if prev == classes[pred]:
        count += 1
    prev = classes[pred]

    if count == 15:
        #arduino.write(str(pred + 1).encode())
        count = 0
        time.sleep(0.1)

    cv.putText(img,classes[pred],(30,30),font ,scale,color, 1, cv.LINE_AA)
    cv.imshow('Spoon vs Fork', img)

    if cv.waitKey(1) == 27:
        break

cam.release()
cv.destroyAllWindows()
