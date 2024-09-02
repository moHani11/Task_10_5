# Plan: 
To use Arduino and MPU6050 IMU and code a program in Arduino IDE to calculate the yaw.

## Details

----

### Accelemoteres:

the MPU6050 Accelerometer measures acceleration. It can also measure gravitational acceleration along the three axes and using trigonometry we can calculate the angle at which the sensor is positioned. 
 
- But since we are using gravity to get the angle we can only get the roll and pitch angles using the accelemotere but cant calculate the yaw as its orientation is not related to gravity.

### Gyroscopes:

The gyroscope measures the angular velocity along the three axes. So it is not directly able to predict roll, pitch or yaw. But integrating angular velocity over time gives us the angle. which can be used to measure the change in roll, pitch and yaw

### Integration 
By doing simple integration to the velocity with respect to time we get the following equation:

> YAW = gyroZ*time_diffrence

---

## Notes:
- Important code parts are explained in the code comments 
- All Registers addresses in the code is taken from the data sheet
[MPU6050 daatsheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)
[MPU6050 Registers daatsheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf)
