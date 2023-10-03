#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define DMA_FREQ			120000			// DMA stepgen frequency = 2 x 500kHz
#define PRU_BASEFREQ    	40000    		// PRU Base thread ISR update frequency (hz)
#define PRU_SERVOFREQ       1000            // PRU Servo thread ISR update freqency (hz)

#define FREQ_RATIO 			DMA_FREQ/ PRU_SERVOFREQ
#define DMA_BUFFER_SIZE		2 * FREQ_RATIO
#define RESOLUTION			1000				// multiply and divide resolution for integer calculations
#define BUFFER_COUNTS		FREQ_RATIO * RESOLUTION

#define STEPBIT     		22            	// bit location in DDS accum
#define STEP_MASK   		(1L<<STEPBIT)

#define JOINTS			    6				// Number of joints - set this the same as LinuxCNC HAL compenent
#define VARIABLES           2             	// Number of command values - set this the same as the LinuxCNC HAL compenent

#define PRU_DATA			0x64617461 		// "data" payload
#define PRU_READ          	0x72656164  	// "read" payload
#define PRU_WRITE         	0x77726974  	// "writ" payload
#define PRU_ACKNOWLEDGE		0x61636b6e		// "ackn" payload
#define PRU_ERR		        0x6572726f		// "erro" payload
#define PRU_ESTOP           0x65737470  	// "estp" payload
#define PRU_NVMPG			0x6D706764

#define BUFFER_SIZE			68

#define DATA_ERR_MAX		5

// Connection LED
#define LED 				"P3_00"

#define JSON_BUFF_SIZE	    10000			// Jason dynamic buffer size

// Location for storage of JSON config file in Flash
#define XIP_BASE						0x60000000
#define JSON_UPLOAD_ADDRESS				0x001F0000	// beginning of Block 31
#define JSON_STORAGE_ADDRESS 			0x00200000	// beginning of Block 32

#define DEFAULT_CONFIG {0x7B, 0x0A, 0x09, 0x22, 0x42, 0x6F, 0x61, 0x72, 0x64, 0x22, 0x3A, 0x20, 0x22, 0x4E, 0x4F, 0x56, 0x55, 0x53, 0x55, 0x4E, 0x22, 0x2C, 0x0A, 0x09, 0x22, 0x4D, 0x6F, 0x64, 0x75, 0x6C, 0x65, 0x73, 0x22, 0x3A, 0x5B, 0x0A, 0x09, 0x7B, 0x0A, 0x09, 0x22, 0x54, 0x68, 0x72, 0x65, 0x61, 0x64, 0x22, 0x3A, 0x20, 0x22, 0x42, 0x61, 0x73, 0x65, 0x22, 0x2C, 0x0A, 0x09, 0x22, 0x54, 0x79, 0x70, 0x65, 0x22, 0x3A, 0x20, 0x22, 0x53, 0x74, 0x65, 0x70, 0x67, 0x65, 0x6E, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x43, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x58, 0x20, 0x2D, 0x20, 0x4A, 0x6F, 0x69, 0x6E, 0x74, 0x20, 0x30, 0x20, 0x73, 0x74, 0x65, 0x70, 0x20, 0x67, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x74, 0x6F, 0x72, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x4A, 0x6F, 0x69, 0x6E, 0x74, 0x20, 0x4E, 0x75, 0x6D, 0x62, 0x65, 0x72, 0x22, 0x3A, 0x09, 0x09, 0x30, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x53, 0x74, 0x65, 0x70, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x20, 0x09, 0x09, 0x22, 0x50, 0x31, 0x5F, 0x32, 0x32, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x44, 0x69, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x20, 0x09, 0x22, 0x50, 0x31, 0x5F, 0x31, 0x37, 0x22, 0x0A, 0x09, 0x7D, 0x2C, 0x0A, 0x09, 0x7B, 0x0A, 0x09, 0x22, 0x54, 0x68, 0x72, 0x65, 0x61, 0x64, 0x22, 0x3A, 0x20, 0x22, 0x42, 0x61, 0x73, 0x65, 0x22, 0x2C, 0x0A, 0x09, 0x22, 0x54, 0x79, 0x70, 0x65, 0x22, 0x3A, 0x20, 0x22, 0x53, 0x74, 0x65, 0x70, 0x67, 0x65, 0x6E, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x43, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x59, 0x20, 0x2D, 0x20, 0x4A, 0x6F, 0x69, 0x6E, 0x74, 0x20, 0x31, 0x20, 0x73, 0x74, 0x65, 0x70, 0x20, 0x67, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x74, 0x6F, 0x72, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x4A, 0x6F, 0x69, 0x6E, 0x74, 0x20, 0x4E, 0x75, 0x6D, 0x62, 0x65, 0x72, 0x22, 0x3A, 0x09, 0x09, 0x31, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x53, 0x74, 0x65, 0x70, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x20, 0x09, 0x09, 0x22, 0x50, 0x31, 0x5F, 0x32, 0x34, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x44, 0x69, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x20, 0x09, 0x22, 0x50, 0x31, 0x5F, 0x33, 0x31, 0x22, 0x0A, 0x09, 0x7D, 0x2C, 0x0A, 0x09, 0x7B, 0x0A, 0x09, 0x22, 0x54, 0x68, 0x72, 0x65, 0x61, 0x64, 0x22, 0x3A, 0x20, 0x22, 0x42, 0x61, 0x73, 0x65, 0x22, 0x2C, 0x0A, 0x09, 0x22, 0x54, 0x79, 0x70, 0x65, 0x22, 0x3A, 0x20, 0x22, 0x53, 0x74, 0x65, 0x70, 0x67, 0x65, 0x6E, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x43, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x5A, 0x20, 0x2D, 0x20, 0x4A, 0x6F, 0x69, 0x6E, 0x74, 0x20, 0x32, 0x20, 0x73, 0x74, 0x65, 0x70, 0x20, 0x67, 0x65, 0x6E, 0x65, 0x72, 0x61, 0x74, 0x6F, 0x72, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x4A, 0x6F, 0x69, 0x6E, 0x74, 0x20, 0x4E, 0x75, 0x6D, 0x62, 0x65, 0x72, 0x22, 0x3A, 0x09, 0x09, 0x32, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x53, 0x74, 0x65, 0x70, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x20, 0x09, 0x09, 0x22, 0x50, 0x31, 0x5F, 0x31, 0x38, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x44, 0x69, 0x72, 0x65, 0x63, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x20, 0x09, 0x22, 0x50, 0x31, 0x5F, 0x32, 0x35, 0x22, 0x0A, 0x09, 0x7D, 0x2C, 0x0A, 0x09, 0x7B, 0x0A, 0x09, 0x22, 0x54, 0x68, 0x72, 0x65, 0x61, 0x64, 0x22, 0x3A, 0x20, 0x22, 0x53, 0x65, 0x72, 0x76, 0x6F, 0x22, 0x2C, 0x0A, 0x09, 0x22, 0x54, 0x79, 0x70, 0x65, 0x22, 0x3A, 0x20, 0x22, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6C, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x43, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x58, 0x5F, 0x4C, 0x69, 0x6D, 0x69, 0x74, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x09, 0x22, 0x50, 0x34, 0x5F, 0x32, 0x36, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x4D, 0x6F, 0x64, 0x65, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x09, 0x22, 0x49, 0x6E, 0x70, 0x75, 0x74, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x44, 0x61, 0x74, 0x61, 0x20, 0x42, 0x69, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x30, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x49, 0x6E, 0x76, 0x65, 0x72, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x46, 0x61, 0x6C, 0x73, 0x65, 0x22, 0x0A, 0x09, 0x7D, 0x09, 0x2C, 0x0A, 0x09, 0x7B, 0x0A, 0x09, 0x22, 0x54, 0x68, 0x72, 0x65, 0x61, 0x64, 0x22, 0x3A, 0x20, 0x22, 0x53, 0x65, 0x72, 0x76, 0x6F, 0x22, 0x2C, 0x0A, 0x09, 0x22, 0x54, 0x79, 0x70, 0x65, 0x22, 0x3A, 0x20, 0x22, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6C, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x43, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x59, 0x5F, 0x4C, 0x69, 0x6D, 0x69, 0x74, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x09, 0x22, 0x50, 0x34, 0x5F, 0x32, 0x37, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x4D, 0x6F, 0x64, 0x65, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x09, 0x22, 0x49, 0x6E, 0x70, 0x75, 0x74, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x44, 0x61, 0x74, 0x61, 0x20, 0x42, 0x69, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x31, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x49, 0x6E, 0x76, 0x65, 0x72, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x46, 0x61, 0x6C, 0x73, 0x65, 0x22, 0x0A, 0x09, 0x7D, 0x2C, 0x0A, 0x09, 0x7B, 0x0A, 0x09, 0x22, 0x54, 0x68, 0x72, 0x65, 0x61, 0x64, 0x22, 0x3A, 0x20, 0x22, 0x53, 0x65, 0x72, 0x76, 0x6F, 0x22, 0x2C, 0x0A, 0x09, 0x22, 0x54, 0x79, 0x70, 0x65, 0x22, 0x3A, 0x20, 0x22, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6C, 0x20, 0x50, 0x69, 0x6E, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x43, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x5A, 0x5F, 0x4C, 0x69, 0x6D, 0x69, 0x74, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x50, 0x69, 0x6E, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x09, 0x22, 0x50, 0x34, 0x5F, 0x32, 0x31, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x4D, 0x6F, 0x64, 0x65, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x09, 0x22, 0x49, 0x6E, 0x70, 0x75, 0x74, 0x22, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x44, 0x61, 0x74, 0x61, 0x20, 0x42, 0x69, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x32, 0x2C, 0x0A, 0x09, 0x09, 0x22, 0x49, 0x6E, 0x76, 0x65, 0x72, 0x74, 0x22, 0x3A, 0x09, 0x09, 0x09, 0x22, 0x46, 0x61, 0x6C, 0x73, 0x65, 0x22, 0x0A, 0x09, 0x7D, 0x0A, 0x09, 0x5D, 0x0A, 0x7D, 0x0A}


#endif
