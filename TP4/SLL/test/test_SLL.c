#include "unity.h"
#include "singly_linked_c.h"

/**
 * @brief Test the SLNode class constructor.
 * 
 */
void test_SLNode_ctor(void){
    SLNode node;
    SLNode nextNode;
    SLNode_ctor(&nextNode, NULL);
    TEST_ASSERT_EQUAL(NULL, nextNode.next);
    SLNode_ctor(&node, &nextNode);
    TEST_ASSERT_EQUAL(&nextNode, node.next);
}

/**
 * @brief Test the SLList class constructor.
 * 
 */
void test_SLList_ctor(void){
    SLNode node;
    SLList list;
    SLNode_ctor(&node, NULL);
    SLList_ctor(&list, &node);
    TEST_ASSERT_EQUAL(&node, list.head);
}

/**
 * @brief Test adding a node at the last position of a list.
 * 
 */
void test_SLList_append(void){
    SLNode node;
    SLList list;
    SLNode_ctor(&node, NULL);
    /* List is created empty, so appending a 
    new node will make it the head node of the list */
    SLList_ctor(&list, NULL);
    TEST_ASSERT_EQUAL(SL_OK_SIG, SLList_append(&list, &node));
    TEST_ASSERT_EQUAL(&node, list.head);
}

/**
 * @brief Test appending a node twice.
 * 
 */
void test_SLList_appendTwice(void){
    SLNode node1;
    SLNode node2; 
    SLList list;
    SLNode_ctor(&node1, NULL);
    SLNode_ctor(&node2, NULL);
    SLList_ctor(&list, NULL);
    TEST_ASSERT_EQUAL(SL_OK_SIG, SLList_append(&list, &node1));
    TEST_ASSERT_EQUAL(&node1, list.head);
    TEST_ASSERT_EQUAL(NULL, list.head->next);    
    TEST_ASSERT_EQUAL(SL_OK_SIG, SLList_append(&list, &node2));
    TEST_ASSERT_EQUAL(&node2, list.head->next);
}

/**
 * @brief Test getting the amount of nodes in a list.
 * 
 */
void test_SLList_getLength(void){
    SLNode node1;
    SLNode node2;
    SLList list;
    SLNode_ctor(&node2, NULL);
    SLNode_ctor(&node1, &node2);
    SLList_ctor(&list, &node1);
    TEST_ASSERT_EQUAL(2, SLList_getLength(&list));
}

/**
 * @brief Test getting a node from a list.
 * 
 */
void test_SLList_getNode(void){
    SLNode node;
    SLList list;
    SLNode_ctor(&node, NULL);
    SLList_ctor(&list, &node);
    TEST_ASSERT_EQUAL(&node, SLList_getNode(&list, 0));
}

/**
 * @brief Test removing a node from a list.
 * 
 */
void test_SLList_removeNode(void){
    SLNode node;
    SLList list;
    SLNode_ctor(&node, NULL);
    SLList_ctor(&list, &node);
    /* Assert that the node removed is the node 'node' */
    TEST_ASSERT_EQUAL(&node, SLList_removeByIndex(&list, 0));
    /* Assert that the list is now empty */
    TEST_ASSERT_EQUAL(NULL, list.head);
}