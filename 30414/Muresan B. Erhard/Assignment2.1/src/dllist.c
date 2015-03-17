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
