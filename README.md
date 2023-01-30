# Hackaton_Feb_2023
Konkuk Univ. Hackaton (Feb 2023)

Main Topic of the Hackaton
==========================
> *Developing and upgrading ideas that can solve problems that arise in the process of implementing future transportation by establishing a team under the theme of future transportation. (electric vehicles, hydrogen vehicles, autonomous AI, drones, UAM, individual transportation, etc)*

Idea of our team
-----------------
> __Detachable safety module for personal transportation(Electrical scooter)__

<p align="center">
<img src="https://www.usfk.mil/portals/105/Images/Resources/Driving/eScooterKickboardSample2-SM_1.jpg" width="450px" height="300px" title="px(픽셀) 크기 설정" alt="personal transportation"></img><br/>
</p>

# Conposition of the safty module
* Object detection module (Detecting bump, stop sign, child protection zone sign)
* Preventing drunk driving module
* Preventing one-handed driving module

# Technical elements used in the safty module
## Object detection module
  + Used light-weight AI model (ssd-mobilenet-v2)
  + Used Colab, Tensorflow to train the AI and transformed into Tensorflow-Lite
  + Labeled, 500 photos per class, a total of 2000 photos
  > Augmented image data by randomly applying light, contrast, tilt, and left-right inversion
    * 4 Classes (Bump1, bump2, stop sign, child protection zone sign)
    * images
  + Mounted the trained model on Raspberry Pi
## Preventing drunk driving module & Preventing one-handed driving module
  + Used Arduino Uno to implement
  + Utilized Alcohol sensor (MQ-3) and force sensitive sensor (FSR 402)

## Hardware
  + Operated 3D printer to make case that is detachable to electrical scooter.
  + Utilized lazer cutter to produce the additional case of Arduino module. 

# Conclusion
# Hardware
![images](./images/hardware 1.png, "3d design of the hardware")
![images](./images/hardware 2.png, "3d design of the hardware")
