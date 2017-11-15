/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <platform.h>
#include "drivers/io.h"
#include "drivers/bus.h"

#if !defined(USE_TARGET_HARDWARE_DESCRIPTORS)

#if !defined(MPU_INT_EXTI)
#define MPU_INT_EXTI NONE
#endif

#if defined(USE_GYRO_L3GD20)
    BUSDEV_REGISTER_SPI(busdev_l3gd20,      DEVHW_L3GD20,       L3GD20_SPI_BUS,     L3GD20_CS_PIN,      NONE,           DEVFLAGS_NONE);
#endif

#if defined(USE_ACC_LSM303DLHC)
    BUSDEV_REGISTER_I2C(busdev_lsm303,      DEVHW_LSM303DLHC,   LSM303DLHC_I2C_BUS, 0x19,               NONE,           DEVFLAGS_NONE);
#endif

#if defined(USE_GYRO_MPU6000)
    BUSDEV_REGISTER_SPI(busdev_mpu6000,     DEVHW_MPU6000,      MPU6000_SPI_BUS,    MPU6000_CS_PIN,     MPU_INT_EXTI,   DEVFLAGS_NONE);
#endif

#if defined(USE_GYRO_MPU6050)
    BUSDEV_REGISTER_I2C(busdev_mpu6050,     DEVHW_MPU6050,      MPU6050_I2C_BUS,    0x68,               MPU_INT_EXTI,   DEVFLAGS_NONE);
#endif

#if defined(USE_GYRO_MPU6500)
    #if defined(MPU6500_SPI_BUS)
    BUSDEV_REGISTER_SPI(busdev_mpu6500,     DEVHW_MPU6500,      MPU6500_SPI_BUS,    MPU6500_CS_PIN,     MPU_INT_EXTI,   DEVFLAGS_NONE);
    #elif defined(MPU6500_I2C_BUS)
    BUSDEV_REGISTER_I2C(busdev_mpu6500,     DEVHW_MPU6500,      MPU6500_I2C_BUS,    0x68,               MPU_INT_EXTI,   DEVFLAGS_NONE);
    #endif
#endif

#if defined(USE_GYRO_MPU9250)
    #if defined(MPU9250_SPI_BUS)
    BUSDEV_REGISTER_SPI(busdev_mpu9250,     DEVHW_MPU9250,      MPU9250_SPI_BUS,    MPU9250_CS_PIN,     MPU_INT_EXTI,   DEVFLAGS_NONE);
    #elif defined(MPU9250_I2C_BUS)
    BUSDEV_REGISTER_I2C(busdev_mpu9250,     DEVHW_MPU9250,      MPU9250_I2C_BUS,    0x68,               MPU_INT_EXTI,   DEVFLAGS_NONE);
    #endif
#endif

#if defined(USE_BARO_BMP085)
    #if !defined(BMP085_I2C_BUS)
        #define BMP085_I2C_BUS BARO_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_bmp085,      DEVHW_BMP280,       BMP085_I2C_BUS,     0x77,               NONE,           DEVFLAGS_NONE);
#endif

#if defined(USE_BARO_BMP280)
    #if defined(BMP280_SPI_BUS)
    BUSDEV_REGISTER_SPI(busdev_bmp280,      DEVHW_BMP280,       BMP280_SPI_BUS,     BMP280_CS_PIN,      NONE,           DEVFLAGS_NONE);
    #elif defined(BMP280_I2C_BUS) || defined(BARO_I2C_BUS)
    #if !defined(BMP280_I2C_BUS)
        #define BMP280_I2C_BUS BARO_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_bmp280,      DEVHW_BMP280,       BMP280_I2C_BUS,     0x76,               NONE,           DEVFLAGS_NONE);
    #endif
#endif

#if defined(USE_BARO_MS5607)
    #if !defined(MS5607_I2C_BUS)
        #define MS5607_I2C_BUS BARO_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_ms5607,      DEVHW_MS5607,       MS5607_I2C_BUS,     0x77,               NONE,           DEVFLAGS_USE_RAW_REGISTERS);
#endif

#if defined(USE_BARO_MS5611)
    #if defined(MS5611_SPI_BUS)
    BUSDEV_REGISTER_SPI(busdev_ms5611,      DEVHW_MS5611,       MS5611_SPI_BUS,     MS5611_CS_PIN,      NONE,           DEVFLAGS_USE_RAW_REGISTERS);
    #elif defined(MS5611_I2C_BUS) || defined(BARO_I2C_BUS)
    #if !defined(MS5611_I2C_BUS)
        #define MS5611_I2C_BUS BARO_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_ms5611,      DEVHW_MS5611,       MS5611_I2C_BUS,     0x77,               NONE,           DEVFLAGS_USE_RAW_REGISTERS);
    #endif
#endif

#if defined(USE_MAG_HMC5883)
    #if !defined(HMC5883_I2C_BUS)
        #define HMC5883_I2C_BUS MAG_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_hmc5883,     DEVHW_HMC5883,      HMC5883_I2C_BUS,    0x1E,               NONE,           DEVFLAGS_NONE);
#endif

#if defined(USE_MAG_QMC5883)
    #if !defined(QMC5883_I2C_BUS)
        #define QMC5883_I2C_BUS MAG_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_qmc5883,     DEVHW_QMC5883,      QMC5883_I2C_BUS,    0x0D,               NONE,           DEVFLAGS_NONE);
#endif

#if defined(USE_MAG_MAG3110)
    #if !defined(MAG3110_I2C_BUS)
        #define MAG3110_I2C_BUS MAG_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_mag3110,     DEVHW_MAG3110,      MAG3110_I2C_BUS,    0x0E,               NONE,           DEVFLAGS_NONE);
#endif

#if defined(USE_MAG_IST8310)
    #if !defined(IST8310_I2C_BUS)
        #define IST8310_I2C_BUS MAG_I2C_BUS
    #endif
    BUSDEV_REGISTER_I2C(busdev_ist8310,     DEVHW_IST8310,      IST8310_I2C_BUS,    0x0C,               NONE,           DEVFLAGS_NONE);
#endif

#if defined(USE_MAX7456)
    BUSDEV_REGISTER_SPI(busdev_max7456,     DEVHW_MAX7456,      MAX7456_SPI_BUS,    MAX7456_CS_PIN,     NONE,           DEVFLAGS_USE_RAW_REGISTERS);
#endif

#if defined(USE_RANGEFINDER_SRF10)
    BUSDEV_REGISTER_I2C(busdev_srf10,       DEVHW_SRF10,        SRF10_I2C_BUS,      0x70,               NONE,           DEVFLAGS_NONE);
#endif

#endif  // USE_TARGET_HARDWARE_DESCRIPTORS




/* This file is not compiled in and only holds example HW descriptors for supported hardware  */
#if 0
// MS5607 / MS5611
BUSDEV_REGISTER_I2C(busdev_ak8963,      DEVHW_AK8963,       MAG_I2C_BUS,        0x0C,               NONE,           DEVFLAGS_NONE);
BUSDEV_REGISTER_I2C(busdev_ak8975,      DEVHW_AK8975,       MAG_I2C_BUS,        0x0C,               NONE,           DEVFLAGS_NONE);
BUSDEV_REGISTER_SPI(busdev_hmc5883,     DEVHW_HMC5883,      MAG_SPI_BUS,        HMC5883_CS_PIN,     NONE,           DEVFLAGS_NONE);
#endif