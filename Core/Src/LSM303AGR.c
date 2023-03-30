/*
 * LSM303AGR.c
 *
 *  Created on: Mar 30, 2023
 *      Author: ts213
 */
#include <LSM303AGR.h>
#include <main.h>
#include <stdio.h>
#include <math.h>
extern I2C_HandleTypeDef hi2c1;

void LSM303AGR_init(){



	 HAL_StatusTypeDef ret = HAL_I2C_IsDeviceReady(&hi2c1, (I_AM_LSM303AGR << 0) +1, 10, 100);
	  if(ret == HAL_OK){

		  printf("Acceleration sensor is ready \r\n");

	  }
	  else
	  {
		  printf("Acceleration sensor is not ready.Check Wires \r\n");
	  }
	  uint8_t pData= LSM303AGR_ACC_SENSITIVITY_4G ; // ???
	 ret =  HAL_I2C_Mem_Write(&hi2c1, (I_AM_LSM303AGR << 0) +1, ACC_I2C_ADDRESS , 1, &pData, 10,100);
	  if(ret == HAL_OK )
	  {
		  printf("Writing to Register 2F ");
	  }
	  else
	  {
		  printf("Failed to write to Register 2F");
	  }

	  //Magnetometer
	  HAL_StatusTypeDef rat = HAL_I2C_IsDeviceReady(&hi2c1, (I_AM_LSM303AGR << 0) +1, 10, 100);
	 	  if(rat == HAL_OK){

	 		  printf("Magnetometer sensor is ready \r\n");

	 	  }
	 	  else
	 	  {
	 		  printf("Magnetometer sensor is not ready.Check Wires \r\n");
	 	  }
	 	  uint8_t qData= LSM303AGR_FS_1_3_GA ; // ???
	 	 rat =  HAL_I2C_Mem_Write(&hi2c1, (I_AM_LSM303AGR << 0) +1, MAG_I2C_ADDRESS , 1, &qData, 10,100);
	 	  if(rat == HAL_OK )
	 	  {
	 		  printf("Writing to Register 2F ");
	 	  }
	 	  else
	 	  {
	 		  printf("Failed to write to Register 2F");
	 	  }



}
void LSM303AGR_read(){
	uint8_t data[2];
	int16_t x_acc;
	 HAL_I2C_Mem_Read(&hi2c1 , I_AM_LSM303AGR ,LSM303AGR_CTRL_REG1_A, 5, &data , 5, 100);

	x_acc = ((int16_t)data[0] << 8) + data[1];
	printf("X_Acceleration = %d", x_acc);
}

