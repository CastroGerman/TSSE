#ifndef INC_SINGLY_LINKED_C_H_
#define INC_SINGLY_LINKED_C_H_

/**
 * Singly Linked List interface. Implemented without virtual tables.
 */

/*----------Singly Linked Node facilities----------*/
typedef struct SLNode SLNode;
struct SLNode {
    SLNode *next;
};
void SLNode_ctor (SLNode * const me, SLNode * const next);

/*----------Singly Linked List facilities----------*/
typedef enum SinglyLinkedSignal {
    SL_OK_SIG,
    SL_ERROR_SIG,
    SL_INVALIDATE_POINTER_SIG,
    SL_EMPTY_LIST_SIG,
    SL_END_OF_LIST_SIG,
    SL_UNIMPLEMENTED_SIG,
	SL_INVALID_PARAMETER_SIG
} SinglyLinkedSignal;

typedef struct SLList {
    SLNode *head;
}SLList;

void SLList_ctor (SLList * const me, SLNode * const head);
SinglyLinkedSignal SLList_append (SLList * const me, SLNode * const node);
int SLList_getLength (SLList * const me);
SLNode * const SLList_getNode (SLList * const me, int idx);
SLNode * const SLList_removeByIndex(SLList * const me, int idx);

#endif /* INC_SINGLY_LINKED_C_H_ */
