#include <stdio.h>
#include "car.h"

struct CarType {
Type type;
Color color;
int current_speed;
double fill_level;
int accelerate;
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
  
  return &aixam;
}

double get_fill_level(Car car){
  return car->fill_level;
}

double get_acceleration_rate(Car car){
  return 0;
}

double set_acceleration_rate(Car car, double acceleration){
  return 0;
}

void accelerate(Car car){

}
