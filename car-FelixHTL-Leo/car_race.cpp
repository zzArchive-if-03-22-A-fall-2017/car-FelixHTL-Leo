#include <stdio.h>
#include "car.h"

struct CarType {
Type type;
int count;
double speed;
};
struct CarRace{
  Car car;
};
static CarType aixam = {AIXAM, 0, 0};
static CarType multipla = {FIAT_MULTIPLA, 0, 0};
static CarType multipla2 = {FIAT_MULTIPLA, 0, 0};
static CarType multipla3 = {FIAT_MULTIPLA, 0, 0};
static CarType jeep = {JEEP, 0, 0};
static CarType jeep2 = {JEEP, 0, 0};

static struct CarRace racetrack[6] = { (&aixam), (&multipla), (&multipla2), (&multipla3), (&jeep), (&jeep2)};



int main(int argc, char const *argv[]) {

  return 0;
}
