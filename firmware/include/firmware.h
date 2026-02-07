#ifndef FIRMWARE_H
#define FIRMWARE_H

void firmware_init(void);
void firmware_run(void);

int read_temperature(void);
int read_voltage(void);
void publish_data(const char* device,int temp, int volt);

#endif

