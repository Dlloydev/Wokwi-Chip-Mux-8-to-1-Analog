/* 8:1 Analog Multiplexer Chip by Dlloydev*/

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_A1;
  pin_t pin_A2;
  pin_t pin_A3;
  pin_t pin_A4;
  pin_t pin_A5;
  pin_t pin_A6;
  pin_t pin_A7;
  pin_t pin_A8;
  pin_t pin_OUT;
  pin_t pin_LED;
  uint32_t Select_attr;
  uint32_t Select;
  float adcValue;
  uint8_t led;
} chip_state_t;

static void chip_timer_event(void *user_data);

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_A1 = pin_init("A1", ANALOG);
  chip->pin_A2 = pin_init("A2", ANALOG);
  chip->pin_A3 = pin_init("A3", ANALOG);
  chip->pin_A4 = pin_init("A4", ANALOG);
  chip->pin_A5 = pin_init("A5", ANALOG);
  chip->pin_A6 = pin_init("A6", ANALOG);
  chip->pin_A7 = pin_init("A7", ANALOG);
  chip->pin_A8 = pin_init("A8", ANALOG);
  chip->pin_OUT = pin_init("OUT", ANALOG);
  chip->pin_LED = pin_init("LED", OUTPUT);
  chip->Select_attr = attr_init("Select", 0);

  const timer_config_t timer_config = {
    .callback = chip_timer_event,
    .user_data = chip,
  };
  timer_t timer_id = timer_init(&timer_config);
  timer_start(timer_id, 500, true);
}

static void chip_timer_event(void *user_data) {
  chip_state_t *chip = (chip_state_t*)user_data;
  chip->Select = attr_read(chip->Select_attr);

  if (chip->Select == 8) chip->adcValue = pin_adc_read(chip->pin_A8);
  else if (chip->Select == 7) chip->adcValue = pin_adc_read(chip->pin_A7);
  else if (chip->Select == 6) chip->adcValue = pin_adc_read(chip->pin_A6);
  else if (chip->Select == 5) chip->adcValue = pin_adc_read(chip->pin_A5);
  else if (chip->Select == 4) chip->adcValue = pin_adc_read(chip->pin_A4);
  else if (chip->Select == 3) chip->adcValue = pin_adc_read(chip->pin_A3);
  else if (chip->Select == 2) chip->adcValue = pin_adc_read(chip->pin_A2);
  else if (chip->Select == 1) chip->adcValue = pin_adc_read(chip->pin_A1);
  else chip->adcValue = 0;
  pin_dac_write(chip->pin_OUT, chip->adcValue);
  
  if (chip->led < chip->adcValue * 10) pin_write(chip->pin_LED, 1);
  else pin_write(chip->pin_LED, 0);

  chip->led++;
  if (chip->led >= 50) chip->led = 0;
  //printf("A1 Value: %f\n", chip->adcValue);
}
