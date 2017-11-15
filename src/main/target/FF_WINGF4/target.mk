F405_TARGETS    += $(TARGET)
FEATURES        += VCP

TARGET_SRC = \
             drivers/accgyro/accgyro_mpu6500.c \
             drivers/accgyro/accgyro_mpu9250.c \
             drivers/compass/compass_mpu9250.c \
             drivers/barometer/barometer_ms56xx.c \
             drivers/compass/compass_hmc5883l.c \
             drivers/rangefinder/rangefinder_hcsr04.c \
             drivers/serial_usb_vcp.c \
             drivers/max7456.c
             