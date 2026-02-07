#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <firmware.h>
void firmware_init(void){
	srand(time(NULL));
}
int read_temperature(void){
	return 20+ rand() % 15;
}
int read_voltage(void){
	return 3300+ rand()%200;
}
void publish_data(const char* device, int temp ,int volt){
	printf("{\"device\":\"%s\",\"temp\":%d,\"volt\":%d}\n",device, temp, volt);
}
void firmware_run(void){
	for(int i=0;i<10 ;i++){
		int temp=read_temperature();
		int volt=read_voltage();
		publish_data("DEV001",temp,volt);
	}
}
