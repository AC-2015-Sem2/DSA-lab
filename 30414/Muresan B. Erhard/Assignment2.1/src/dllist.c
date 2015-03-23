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

#include "dllist.h"

/* creates double linked node */
NodeD *createNode(int data)
{
  NodeD *node = (NodeD *)malloc(sizeof(NodeD));
  if (node == NULL)
    perror("Couldn't allocate memory for the new node!");
  node->data = data;
  node->prev = node->next = NULL;
  return node;
}

/* creates empty double linked list */
ListD *createList()
{
  ListD *list = (ListD *)malloc(sizeof(ListD));
  if (list == NULL)
    perror("Couldn't allocate memory for the new list!");
  list->head = NULL;
  list->tail = NULL;
  return list;
}

/* add node to the head of the list */
void addAtFirst(ListD *L, NodeD *pNode)
{
  if (L == NULL || pNode == NULL)
    {
      perror("Invalid list or node!");
      return;
    }
  if (L->head == NULL)
    { /* head == tail == NULL. list is empty */
      L->head = pNode;
      L->tail = pNode;
    }
  else
    {
      pNode->next = L->head;
      L->head->prev = pNode;
      L->head = pNode;
    }
}

/* add node to the tail of the list */
void addAtLast(ListD *L, NodeD *pNode)
{
  if (L == NULL || pNode == NULL)
    {
      perror("Invalid list or node!");
      return;
    }
  if (L->head == NULL) /* list is empty */
    addAtFirst(L, pNode);
  else
    {
      L->tail->next = pNode;
      pNode->prev = L->tail;
      L->tail = pNode;
    }
}

/* remove first node from list */
void deleteFirst(ListD *L)
{
  if (L == NULL)
    {
      perror("Invalid list!");
      return;
    }
  if (L->head == NULL)
    { /* list is empty */
      perror("List is empty!");
      return;
    }
  if (L->head == L->tail)
    { /* list has only one element */
      NodeD *pNode = L->head;
      L->head = NULL;
      L->tail = NULL;
      free(pNode);
    }
  else
    {
      NodeD *pNode = L->head;
      L->head = pNode->next;
      pNode->next->prev = NULL;
      free(pNode);
    }
}

/* remove last node from list */
void deleteLast(ListD *L)
{
  if (L == NULL)
    {
      perror("Invalid list!");
      return;
    }
  if (L->head == NULL)
    { /* list is empty */
      perror("List is empty!");
      return;
    }
  if (L->head == L->tail)
    { /* list has only one element */
      NodeD *pNode = L->head;
      L->head = NULL;
      L->tail = NULL;
      free(pNode);
    }
  else
    {
      NodeD *pNode = L->tail;
      L->tail = pNode->prev;
      pNode->prev->next = NULL;
      free(pNode);
    }
}

/* remove node from list */
void deleteNodeByValue(ListD *L, int data)
{
  if (L == NULL)
    {
      perror("Invalid list or node");
      return;
    }
  if (L->head == NULL)
    { /* list is empty */
      perror("List is empty!");
      return;
    }

  NodeD *pNode = L->head;
  while (pNode != NULL)
    {
      if (pNode->data == data)
	break;
      pNode = pNode->next;
    }
  if (pNode != NULL)
    {
      if (pNode == L->head)
	{ /* first in the list */
	  L->head = L->head->next;
	  pNode->next->prev = NULL;
	  free(pNode);
	  if (L->head == NULL) /* list is empty */
	    L->tail = NULL;
	}
      else
	{
	  pNode->prev->next = pNode->next;
	  pNode->next->prev = pNode->prev;
	  if (pNode == L->tail)
	    L->tail = pNode->prev;
	  free(pNode);
	}
    }
}

/* remove all elements from list */
void deleteAll(ListD *L)
{
  if (L == NULL)
    {
      perror("Invalid list!");
      return;
    }

  while (L->head != NULL)
    {
      deleteFirst(L);
    }
}

/* print all elements of the list */
void printList(ListD *L)
{
  if (L == NULL)
    {
      perror("Invalid list!");
      return;
    }
  NodeD *pNode = L->head;
  while (pNode != NULL)
    {
      if (pNode == L->tail)
	fprintf(fpOut, "%d\n", pNode->data);
      else
	fprintf(fpOut, "%d ", pNode->data);
      pNode = pNode->next;
    }
}

/* print N first elements from list */
void printNFirst(ListD *L, int n)
{
  if (L == NULL)
    return;
  if (n <= 0)
    return;
  NodeD *pNode = L->head;
  while (pNode != NULL)
    {
      if (pNode == L->tail)
	fprintf(fpOut, "%d", pNode->data);
      else
	fprintf(fpOut, "%d ", pNode->data);
      pNode = pNode->next;
      n--;
      if (n == 0)
	{ /* no nodes left to print */
	  fprintf(fpOut, "\n");
	  break;
	}
    }
}

/* print N last elements from list */
void printNLast(ListD *L, int n)
{
  if (L == NULL)
    return;
  if (n <= 0) /* nothing to print */
    return;
  NodeD *pNode = L->tail;
  while (pNode != NULL)
    {
      n--;
      pNode = pNode->prev;
      if (n == 1) /* first node from sublist */
	break;
    }
  while (pNode != NULL)
    {
      if (pNode == L->tail)
	fprintf(fpOut, "%d\n", pNode->data);
      else
	fprintf(fpOut, "%d ", pNode->data);
      pNode = pNode->next;
    }
}
