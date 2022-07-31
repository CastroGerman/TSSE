#include "src/singly_linked_c.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










void test_SLNode_ctor(void){

    SLNode node;

    SLNode nextNode;

    SLNode_ctor(&nextNode, 

                          ((void *)0)

                              );

    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((nextNode.next)), (

   ((void *)0)

   ), (UNITY_UINT)(12), UNITY_DISPLAY_STYLE_INT);

    SLNode_ctor(&node, &nextNode);

    UnityAssertEqualNumber((UNITY_INT)((&nextNode)), (UNITY_INT)((node.next)), (

   ((void *)0)

   ), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);

}











void test_SLList_ctor(void){

    SLNode node;

    SLList list;

    SLNode_ctor(&node, 

                      ((void *)0)

                          );

    SLList_ctor(&list, &node);

    UnityAssertEqualNumber((UNITY_INT)((&node)), (UNITY_INT)((list.head)), (

   ((void *)0)

   ), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);

}











void test_SLList_append(void){

    SLNode node;

    SLList list;

    SLNode_ctor(&node, 

                      ((void *)0)

                          );





    SLList_ctor(&list, 

                      ((void *)0)

                          );

    UnityAssertEqualNumber((UNITY_INT)((SL_OK_SIG)), (UNITY_INT)((SLList_append(&list, &node))), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((&node)), (UNITY_INT)((list.head)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}











void test_SLList_appendTwice(void){

    SLNode node1;

    SLNode node2;

    SLList list;

    SLNode_ctor(&node1, 

                       ((void *)0)

                           );

    SLNode_ctor(&node2, 

                       ((void *)0)

                           );

    SLList_ctor(&list, 

                      ((void *)0)

                          );

    UnityAssertEqualNumber((UNITY_INT)((SL_OK_SIG)), (UNITY_INT)((SLList_append(&list, &node1))), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((&node1)), (UNITY_INT)((list.head)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((list.head->next)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((SL_OK_SIG)), (UNITY_INT)((SLList_append(&list, &node2))), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((&node2)), (UNITY_INT)((list.head->next)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}











void test_SLList_getLength(void){

    SLNode node1;

    SLNode node2;

    SLList list;

    SLNode_ctor(&node2, 

                       ((void *)0)

                           );

    SLNode_ctor(&node1, &node2);

    SLList_ctor(&list, &node1);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((SLList_getLength(&list))), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

}











void test_SLList_getNode(void){

    SLNode node;

    SLList list;

    SLNode_ctor(&node, 

                      ((void *)0)

                          );

    SLList_ctor(&list, &node);

    UnityAssertEqualNumber((UNITY_INT)((&node)), (UNITY_INT)((SLList_getNode(&list, 0))), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

}











void test_SLList_removeNode(void){

    SLNode node;

    SLList list;

    SLNode_ctor(&node, 

                      ((void *)0)

                          );

    SLList_ctor(&list, &node);



    UnityAssertEqualNumber((UNITY_INT)((&node)), (UNITY_INT)((SLList_removeByIndex(&list, 0))), (

   ((void *)0)

   ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((UNITY_INT)((

   ((void *)0)

   )), (UNITY_INT)((list.head)), (

   ((void *)0)

   ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

}
