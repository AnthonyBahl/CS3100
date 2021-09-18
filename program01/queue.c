// Anthony Bahl
// Program 1
// 9/4/2021

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

queue *createq(void){

    // Pointer to the newly created queue
    queue *newqueue;

    // Allocate space for newqueue in the heap
    newqueue = (queue *) malloc(sizeof(queue));
    // Initialize values in queue
    newqueue->head = NULL;
    newqueue->tail = NULL;

    return newqueue;
}

bool enqueue(queue *_queue, person _person){

    // Pointer our new node
    node *newnode;

    // Check to make sure the queue pointer points to something
    if (!_queue)
    {
        // Print Error Message
        printf("Error in enqueue function: Pointer to queue is null.");
        return false;
    }
    
    // Allocate space for newnode, a node type, in the heap
    newnode = (node *) malloc(sizeof(node));

    // Check to see if malloc function failed
    if (!newnode){
        // Print Error Message
        printf("Error in enqueue function: malloc function failed while allocating space for newnode.q  ");
        return false;
    }

    // Copy the person into the value field of the new node.
    newnode->value = _person;
    
    // If the queue is empty,
    if (_queue->head == NULL)
    {
        // Set the head to point to the newnode.
        _queue->head = newnode;
    } else
    {
        // Set the next filed of the node at the tail pointer to point to newnode 
        _queue->tail->next = newnode;
    }

    // Set the next field of newnode to NULL
    newnode->next = NULL;
    
    // Set the tail of the queue to point to newnode
    _queue->tail = newnode;

    return true;
}

person dequeue(queue * _queue){

    // Check to make sure the queue pointer points to something
    if (!_queue)
    {
        // Print Error Message
        printf("Error in dequeue: pointer is NULL.");
        
        // Create a fake person to return
        person fakePerson = {"", 0};

        return fakePerson;
    } else if ((*_queue).head == NULL)
    {
        // Print Error Message
        printf("Error in dequeue: pointer is NULL.");
        
        // Create a fake person to return
        person fakePerson = {"", 0};

        return fakePerson;
    } 

    // Copy the node at the stack head into return variable
    node returnNode = *_queue->head;

    // Set tempPointer to the value of the head
    node *tempPointer = _queue->head;

    // Set the value of head to the new head of the queue
    _queue->head = returnNode.next;

    // deallocate the memory previously allocated for the old node
    free(tempPointer);

    return returnNode.value;
}

bool isemptyqueue(queue *_queue){

    // Check to make sure the queue pointer points to something
    if (!_queue)
    {
        // Print Error Message
        printf("Error in isemptyqueue: pointer is NULL.");
        
        return true;
    }

    // If Queue is empty return true, otherwise return false
    return (_queue->head == NULL) ? true : false;
}

bool emptyq(queue *_queue){

    // Check to make sure the queue pointer points to something
    if (!_queue)
    {
        // Print Error Message
        printf("Error in emptyq function: Pointer to queue is null.");
        
        return false;
    }

    // Loop through everyone in the queue
    while (!isemptyqueue(_queue))
    {
        // Remove from queue
        dequeue(_queue);
    }

    return true;    
}

bool freeq(queue *_queue){

    // Check to make sure the queue pointer points to something
    if (!_queue)
    {
        // Print Error Message
        printf("Error in freeq function: Pointer to queue is null.");
        return true;
    }

    // Check to see if queue is empty
    if (isemptyqueue(_queue))
    {
        // deallocate the memory previously allocated for the queue
        free(_queue); 
        return true;
    } else
    {
        return false;
    }
}