/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: <your class>
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			P. Bauer
* Due Date:		January 9, 2015
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

enum Type{
  AIXAM,
  FIAT_MULTIPLA,
  JEEP
};

enum Color{
  RED,
  GREEN,
  BLUE,
  ORANGE,
  SILVER,
  BLACK
};

typedef struct CarType* Car;

void init();


int get_speed(Car car);

Type get_type(Car car);

Color get_color(Car car);

double get_fill_level(Car car);

double get_acceleration_rate(Car car);

Car get_car(Type type);

void set_acceleration_rate(Car car, double acceleration);

void accelerate(Car car);

#endif
