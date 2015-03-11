/* Copyright 2015 Erhard Muresan.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "sllist.h"

/* creates single linked node */
Node *createNode(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL)
    perror("Couldn't allocate memory for the new node!");
  node->data = data;
  node->next = NULL;
  return node;
}

/* creates empty single linked list */
List *createList()
{
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL)
    perror("Couldn't allocate memory for the new list!");
  list->head = NULL;
  list->tail = NULL;
  return list;
}

/* add node to the head of the list */
void addAtFirst(List *L, Node *pNode)
{
  if(L == NULL || pNode == NULL)
    {
      perror("Invalid list or node!");
      return;
    }
  if(L->head == NULL) /* list is empty */
    { /* head == tail == NULL */
      L->head = pNode;
      L->tail = pNode;
    }
  else
    {
      pNode->next = L->head;
      L->head = pNode;
    }
}

/* add node to the tail of the list */
void addAtLast(List *L, Node *pNode)
{
  if(L == NULL || pNode == NULL)
    {
      perror("Invalid list or node!");
      return;
    }
  if(L->tail == NULL) /* list is empty */
    addAtFirst(L, pNode);
  else
    {
      L->tail->next = pNode;
      L->tail = pNode;
    }
}

/* remove first node from list */
void deleteFirst(List *L)
{
  if(L == NULL)
    {
      perror("Invalid list");
      return;
    }
  if(L->head == NULL) /* the list is empty */
    {
      perror("List is empty!");
      return;
    }
  else if(L->head == L->tail) /* list has only one element */
    {
      Node *pNode = L->head;
      L->head = NULL;
      L->tail = NULL;
      free(pNode);
    }
  else
    {
      Node *pNode = L->head;
      L->head = L->head->next;
      free(pNode);
    }
}

/* remove last node from list*/
void deleteLast(List *L)
{
  if(L == NULL)
    {
      perror("Invalid list!");
      return;
    }
  if(L->tail == NULL) /* list is empty */
    {
      perror("List is empty!");
      return;
    }
  else if(L->head == L->tail) /* list has only one element*/
    {
      Node *pNode = L->tail;
      L->head = NULL;
      L->tail = NULL;
      free(pNode);
    }
  else
    {
      Node *pNode = NULL;
      Node *current = L->head;
      while(current->next != L->tail)
	{
	  current = current->next;
	}
      pNode = current->next;
      current->next = NULL;
      L->tail = current;
      free(pNode);
    }
}

/* remove node from list */
void deleteNodeByValue(List *L, int data)
{
  if(L == NULL)
    {
      perror("Invalid list or node");
      return;
    }
  if(L->head == NULL) /* list is empty */
    {
      perror("List is empty!");
      return;
    }

  Node *previous = NULL;
  Node *current = L->head;
  while(current != NULL)
    {
      if(current->data == data)
	break;
      previous = current;
      current = current->next;
    }
  if(current != NULL)
    {
      if(current == L->head)
	{/* first in the list */
	  L->head = L->head->next;
	  free(current);
	  if(L->head == NULL)
	    L->tail = NULL;
	}
      else
	{
	  previous->next = current->next;
	  if(current == L->tail)
	    L->tail = previous;
	  free(current);
	}
    }
}

/* remove all elements from list */
void deleteAll(List *L)
{
  if(L == NULL)
    {
      perror("Invalid list!");
      return;
    }
  while(L->head != NULL)
    {
      deleteFirst(L);
    }
}

/* print all elements of the list */
void printList(List *L)
{
  if(L == NULL)
    {
      perror("Invalid list!");
      return;
    }

  Node *pNode = L->head;
  while(pNode != NULL)
    {
      if(pNode == L->tail)
	fprintf(fpOut, "%d\n", pNode->data);
      else
	fprintf(fpOut, "%d ", pNode->data);
      pNode = pNode->next;
    }
}

/* print first n elements of the list */
void printNFirst(List *L, int n)
{
  if(L == NULL)
    return;
  if(n <= 0)
    return;
  int ne = 0;
  Node *pNode = L->head;
  while(pNode != NULL)
    {
      ne++;
      if(ne <= n)
	{
	  if(ne == n)
	    fprintf(fpOut, "%d\n", pNode->data);
	  else
	    fprintf(fpOut, "%d ", pNode->data);
	}
      pNode = pNode->next;
    }
}

/* print last n elements of the list */
void printNLast(List *L, int n)
{
  if(L == NULL)
    return;
  if(n <= 0)
    return;

  int nc, ns;
  nc = 0;
  Node *pNode = L->head;
  while(pNode != NULL)
    {
      nc++;
      pNode = pNode->next;
    }
  if(n > nc)
    n = nc;
  ns = nc - n + 1;
  nc = 0;
  pNode = L->head;
  while(pNode != NULL)
    {
      nc++;
      if(nc >= ns)
	{
	  if(pNode == L->tail)
	    fprintf(fpOut, "%d\n", pNode->data);
	  else
	    fprintf(fpOut, "%d ", pNode->data);
	}
      pNode = pNode->next;
    }
}
