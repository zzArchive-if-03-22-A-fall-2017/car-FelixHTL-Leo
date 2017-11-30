#include <stdio.h>
#include "car.h"

#define car_park_length 6
#define AIXAM_MAX_ACCELERATE 1.0
#define MULTIPLA_MAX_ACCELERATE 2.26
#define JEEP_MAX_ACCELERATE 3.14
#define LOWEST_ACCELERATION -8

struct CarType {
Type type;
Color color;
int current_speed;
double fill_level;
double accelerate;
};
struct RentalRecord{
  bool isRent;
  Car car;
};
static CarType aixam = {AIXAM, RED, 0, 16.0, 0};
static CarType multipla = {FIAT_MULTIPLA, GREEN, 0, 65.0, 0};
static CarType multipla2 = {FIAT_MULTIPLA, BLUE, 0, 65.0, 0};
static CarType multipla3 = {FIAT_MULTIPLA, ORANGE, 0, 65.0, 0};
static CarType jeep = {JEEP, SILVER, 0, 80.0, 0};
static CarType jeep2 = {JEEP, BLACK, 0, 80.0, 0};

static struct RentalRecord car_park[6] = {{false, &aixam}, {false, &multipla}, {false, &multipla2}, {false, &multipla3}, {false, &jeep}, {false, &jeep2}};

void init(){
  aixam.current_speed = 0;
  aixam.fill_level = 16.0;
  aixam.accelerate = 0;
  car_park[0].isRent = false;

  multipla.current_speed = 0;
  multipla.fill_level = 65.0;
  multipla.accelerate = 0;
  car_park[1].isRent = false;

  multipla2.current_speed = 0;
  multipla2.fill_level = 65.0;
  multipla2.accelerate = 0;
  car_park[2].isRent = false;

  multipla3.current_speed = 0;
  multipla3.fill_level = 65.0;
  multipla3.accelerate = 0;
  car_park[3].isRent = false;

  jeep.current_speed = 0;
  jeep.fill_level = 80.0;
  jeep.accelerate = 0;
  car_park[4].isRent = false;

  jeep2.current_speed = 0;
  jeep2.fill_level = 80.0;
  jeep2.accelerate = 0;
  car_park[5].isRent = false;
}

int get_speed(Car car){
  return car->current_speed;
}

Type get_type(Car car){
  return car->type;
}

Color get_color(Car car){
  return car->color;
}

Car get_car(Type type){
  for (int i = 0; i < car_park_length; i++) {
    if(!car_park[i].isRent && car_park[i].car->type == type){
      car_park[i].isRent = true;
      return car_park[i].car;
    }
  }
  return 0;
}

double get_fill_level(Car car){
  return car->fill_level;
}

double get_acceleration_rate(Car car){
  return car->accelerate;
}

void set_acceleration_rate(Car car, double acceleration){
  if(acceleration < LOWEST_ACCELERATION){
    car->accelerate = -8;
    return;
  }
  if(car->type == AIXAM){
    if(acceleration < AIXAM_MAX_ACCELERATE){
      car->accelerate = acceleration;
    }
    else{
      car->accelerate = AIXAM_MAX_ACCELERATE;
    }
  }
  else if(car->type == FIAT_MULTIPLA){
    if(acceleration < MULTIPLA_MAX_ACCELERATE){
      car->accelerate = acceleration;
    }
    else{
      car->accelerate = MULTIPLA_MAX_ACCELERATE;
    }
  }
  else if(car->type == JEEP){
    if(acceleration < JEEP_MAX_ACCELERATE){
      car->accelerate = acceleration;
    }
    else{
      car->accelerate = JEEP_MAX_ACCELERATE;
    }
  }
}

void accelerate(Car car){

}
