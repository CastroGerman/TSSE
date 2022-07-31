#include "singly_linked_c.h"
#include <assert.h>
#include <stdlib.h>

void SLNode_ctor (SLNode * const me, SLNode * const next) {
    me->next = next;
}

static SinglyLinkedSignal SLList_append_R (SLNode ** const head, SLNode * const node) {
    if (*head != NULL) {
        SLList_append_R(&(*head)->next, node);
    } else {
        *head = node;
    }
    return SL_OK_SIG;
}

SinglyLinkedSignal SLList_append (SLList * const me, SLNode * const node) {
    assert(me);
    return SLList_append_R(&me->head, node);
}

static int SLList_getLength_R (SLNode * const head) {
    if (head != NULL) {
        return SLList_getLength_R(head->next) + 1; /* No TCO (Tail Call Optimization)*/
    }
    return 0;
}

int SLList_getLength (SLList * const me) {
    assert(me);
    return SLList_getLength_R(me->head);
}

static SLNode * const SLList_getNode_R (SLNode * const head, int idx){
	if (idx > 0) {
		return SLList_getNode_R(head->next, --idx);
	}
	return head;
}

SLNode * const SLList_getNode (SLList * const me, int idx){
	assert(me);
	if ((idx < 0) || (idx >= SLList_getLength(me))) return NULL;
	return SLList_getNode_R(me->head, idx);
}

SLNode * const SLList_removeByIndex(SLList * const me, int idx) {
	assert(me);
	if ((idx < 0) || (idx >= SLList_getLength(me))) return NULL;
	SLNode *node = SLList_getNode(me, idx);
	SLNode *prevNode = SLList_getNode(me, idx - 1);
	if(NULL == prevNode){
		me->head = node->next;
	}else{
		prevNode->next = node->next;
	}
	node->next = NULL;
	return node;
}

void SLList_ctor (SLList * const me, SLNode * const head) {
    me->head = head;
}
