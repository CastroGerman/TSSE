#include "src/leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


uint16_t leds_virtuales;



void setUp(void){

    LedsCreate(&leds_virtuales);

}





void test_todos_los_leds_inician_apagados(void){

    uint16_t leds_virtuales = 0xFFFF;

    LedsCreate(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);



}





void test_prender_un_led_individual(void){

    uint16_t leds_virtuales = 0;

    LedsCreate(&leds_virtuales);

    LedsSingleTurnOn(3);

    UnityAssertEqualNumber((UNITY_INT)((1 << 2)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}





void test_apagar_un_led_individual(void){

    uint16_t leds_virtuales = 0;

    LedsCreate(&leds_virtuales);

    LedsSingleTurnOn(3);

    LedsSingleTurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_varios_leds(void){

    setUp();

    LedsSingleTurnOn(3);

    LedsSingleTurnOn(7);

    LedsSingleTurnOff(7);

    UnityAssertEqualNumber((UNITY_INT)((1<<2)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_todos_los_leds(void){

    setUp();

    LedsTurnOn();

    UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}





void test_apagar_todos_los_leds(void){

    setUp();

    LedsTurnOn();

    LedsTurnOff();

    UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}





void test_verificar_led_encendido(void){

    setUp();

    LedsSingleTurnOn(3);

    UnityAssertEqualNumber((UNITY_INT)((0x1)), (UNITY_INT)((LedsGetLedState(3))), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}





void test_verificar_led_apagado(void){

    setUp();

    LedsSingleTurnOn(3);

    LedsSingleTurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((LedsGetLedState(3))), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

}
