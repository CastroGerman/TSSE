#include "unity.h"
#include "leds.h"

uint16_t leds_virtuales;

void setUp(void){
    LedsCreate(&leds_virtuales);
}

/* Con la inicializacion todos los leds quedan apagados */
void test_todos_los_leds_inician_apagados(void){
    uint16_t leds_virtuales = 0xFFFF;
    LedsCreate(&leds_virtuales);
    TEST_ASSERT_EQUAL(0x00, leds_virtuales);
    //TEST_FAIL_MESSAGE("Empezamos");
}

/* Crender un led individual */
void test_prender_un_led_individual(void){
    uint16_t leds_virtuales = 0;
    LedsCreate(&leds_virtuales);
    LedsSingleTurnOn(3);
    TEST_ASSERT_EQUAL(1 << 2, leds_virtuales);
}

/* Apagar un led individual */
void test_apagar_un_led_individual(void){
    uint16_t leds_virtuales = 0;
    LedsCreate(&leds_virtuales);
    LedsSingleTurnOn(3);
    LedsSingleTurnOff(3);
    TEST_ASSERT_EQUAL(0, leds_virtuales);
}

/* Prender y apagar un led individual */
void test_prender_y_apagar_varios_leds(void){
    setUp();
    LedsSingleTurnOn(3);
    LedsSingleTurnOn(7);
    LedsSingleTurnOff(7);
    TEST_ASSERT_EQUAL(1<<2, leds_virtuales);
}

/* Prender todos los leds */
void test_prender_todos_los_leds(void){
    setUp();
    LedsTurnOn();
    TEST_ASSERT_EQUAL(0xFFFF, leds_virtuales);
}

/* Apagar todos los leds */
void test_apagar_todos_los_leds(void){
    setUp();
    LedsTurnOn();
    LedsTurnOff();
    TEST_ASSERT_EQUAL(0x0, leds_virtuales);
}

/* Consultar el estado de un led que esta encendido */
void test_verificar_led_encendido(void){
    setUp();
    LedsSingleTurnOn(3);
    TEST_ASSERT_EQUAL(0x1, LedsGetLedState(3));
}

/* Consultar el estado de un led que esta apagado */
void test_verificar_led_apagado(void){
    setUp();
    LedsSingleTurnOn(3);
    LedsSingleTurnOff(3);
    TEST_ASSERT_EQUAL(0x0, LedsGetLedState(3));
}
