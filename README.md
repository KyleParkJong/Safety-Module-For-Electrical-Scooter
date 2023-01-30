# Hackaton_Feb_2023
Konkuk Univ. Hackaton (Feb 2023)

Main Topic of the Hackaton
==========================
> *Developing and upgrading ideas that can solve problems that arise in the process of implementing future transportation by establishing a team under the theme of future transportation. (electric vehicles, hydrogen vehicles, autonomous AI, drones, UAM, individual transportation, etc)*

0.Idea of our team
--------------------
> __Detachable safety module for personal transportation(Electrical scooter)__

<p align="center">
<img src="https://napiercbd.co.nz/wp-content/uploads/2022/11/Scooter-scaled.jpeg" width="60%" height="60%" title="e-scooter" alt=" e-scooter"></img><br/>
</p>

# 1. Conposition of the safty module
* Object detection module (Detecting bump, stop sign, child protection zone sign)
* Preventing drunk driving module
* Preventing one-handed driving module

# 2. Overall Block-diagram

<p align="center">
<img src="/images/block_diagram.jpg" width="70%" height="70%" title="block-diagram" alt="block-diagram"></img>
</p>

# 3. Technical elements used in the safty module
## Object detection module
  + Used light-weight AI model (__ssd-mobilenet-v2__)
  + Used Colab, Tensorflow to train the AI and transformed into Tensorflow-Lite
  + Labeled, 500 photos per class, a total of 2000 photos
    * 4 Classes (Bump1, bump2, stop sign, child protection zone sign)
    * Augmented image data by randomly applying light, contrast, tilt, and left-right inversion
  + Batch size = 16, Step number = 20,000 
  + Mounted the trained model on Raspberry Pi
  
  <img src="/images/4_classes.jpg" width="40%" height="40%" title="dataset" alt="dataset"></img>
  <img src="/images/data_augmentation.png" width="40%" height="40%" title="data augmentation" alt="data augmentation"></img>
  
  + Total Loss
  <img src="/images/total loss.png" width="60%" height="60%" title="total loss" alt="total loss"></img>
  
    
  
## Preventing drunk driving module & Preventing one-handed driving module
  + Used Arduino Uno to implement
  + Utilized Alcohol detect sensor (MQ-3) and force sensitive sensor (FSR 402)
  
## Hardware
  + Operated 3D printer to make case that is detachable to electrical scooter.
  + Utilized lazer cutter to produce the additional case of Arduino module. 

<img src="/images/3d_design_of_hardware.png" width="50%" height="50%" title="3d" alt="3d"></img>
<img src="/images/Lazer_cutter_design.png" width="30%" height="30%" title="lazer" alt="lazer"></img>

# 4. Conclusion
## Hardware for Raspberry Pi and battery 
  * Made by 3D printer 
  * Forward direction is the camera direction

![hardware](/images/hardware1.png "3d design of the hardware")
![hardware](/images/hardware2.png "3d design of the hardware")


## Hardware for Arduino Uno and sensors
  * Alcohol detect sensor(MQ-3), force sensitive sensor (FSR 402)
  * LED, buzzer for warning

<img src="/images/hardware3.jpg" width="40%" height="40%" title="used lazer cutter to make" alt="hardware3"></img>
<img src="/images/hardware4.jpg" width="40%" height="40%" title="used lazer cutter to make" alt="hardware4"></img>

## Object detected
  * bump, stop sign, child protection zone sign

<img src="/images/bump detected.png" width="50%" height="50%" title="bump" alt="bump"></img>
<img src="/images/stop.png" width="50%" height="50%" title="bump" alt="bump"></img>
<img src="/images/child.png" width="50%" height="50%" title="bump" alt="bump"></img>



