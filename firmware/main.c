#include <stdio.h>
#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL));
  for (int i=0;i<10;i++){
    int temp=20+ rand() %15;
    int volt=3300 + rand()%200;
    printf("{\"device\":\"DEV001\",\"temp\":%d,\"volt\":%d}\n",temp,volt);
  }
  return 0;
}