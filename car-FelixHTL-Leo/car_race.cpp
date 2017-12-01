#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "car.cpp"
#include "time.h"

#define FINISHLINE 10
#define MAX_CARS 6

struct CarRace{
  Car car;
  int position;
  char name[2];
};

static struct CarRace racetrack[6];

void init_racetrack();
void get_random_accelration();
void highest_accelration();
bool check_if_reached_finishline();


int main(int argc, char const *argv[]) {
  srandom(time(NULL));
  init_racetrack();
  bool check = false;
  while (check == false) {
    get_random_accelration();
    highest_accelration();
    check = check_if_reached_finishline();
  }
  return 0;
}

void init_racetrack(){
  int count_fm = 0;
  int count_j = 0;
  for (int i = 0; i < MAX_CARS; i++) {
    racetrack[i].car = car_park[i].car;
    racetrack[i].position = 0;
    if(racetrack[i].car->type == AIXAM){
      strcpy(racetrack[i].name, "A1");
    }
    else if(racetrack[i].car->type == FIAT_MULTIPLA){
      if(count_fm == 0){
        strcpy(racetrack[i].name, "F1");
        count_fm++;
      }
      else if(count_fm == 1){
        strcpy(racetrack[i].name, "F2");
        count_fm++;
      }
      else{
        strcpy(racetrack[i].name, "F3");
        count_fm++;
      }
    }
    else{
      if(count_j == 0){
        strcpy(racetrack[i].name, "J1");
        count_j++;
      }
      else if(count_j == 1){
        strcpy(racetrack[i].name, "J2");
        count_j++;
      }
  }

}
}
void get_random_accelration(){
  for (int i = 0; i < MAX_CARS; i++) {
    racetrack[i].car->accelerate = random();
  }
}

void highest_accelration(){
  for (int i = 0; i < MAX_CARS; i++) {
    bool check = true;
    for (int e = i + 1; e < MAX_CARS; e++) {
      if(racetrack[i].car->accelerate < racetrack[e].car->accelerate){
        check = false;
      }
    }
    if(check == true){
      racetrack[i].position++;
      return;
    }
  }
}

bool check_if_reached_finishline(){
  for (int i = 0; i < MAX_CARS; i++) {
    if(racetrack[i].position == FINISHLINE){
      printf("The Winner is %s\n", racetrack[i].name);
      return true;
    }
  }
  return false;
}
