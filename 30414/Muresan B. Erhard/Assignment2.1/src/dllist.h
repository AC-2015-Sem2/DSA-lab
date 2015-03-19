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

#ifndef DLLIST_H_INCLUDED
#define DLLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
  int data; /* the value it holds */
  struct _node *next; /* pointer to the next node */
  struct _node *prev; /* pointer to the previous node */
}NodeD;

typedef struct
{
  NodeD *head; /* pointer to first node of the list */
  NodeD *tail; /* pointer to last node of the list */
  int size; /* current size of the list */
}ListD;

NodeD *createNode(int);
ListD *createList();
void addAtFirst(ListD *, NodeD *);
void addAtLast(ListD *, NodeD *);
void deleteFirst(ListD *);
void deleteLast(ListD *);
void deleteNodeByValue(ListD *, int);
void deleteAll(ListD *);
void printList(ListD *);
void printNFirst(ListD *, int);
void printNLast(ListD *, int);

extern FILE *fpOut;

#endif // DLLIST_H_INCLUDED
