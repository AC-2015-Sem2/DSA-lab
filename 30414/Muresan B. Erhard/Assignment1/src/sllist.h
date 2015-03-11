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

#ifndef SLLIST_H_INCLUDED
#define SLLIST_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
  int data; /* the value it holds */
  struct _node *next; /* pointer to the next node */
}Node;

typedef struct
{
  Node *head; /* pointer to first node of the list */
  Node *tail; /* pointer to the last node of the list */

}List;

Node *createNode(int);
List *createList();
void addAtFirst(List *, Node *);
void addAtLast(List *, Node *);
void deleteFirst(List *);
void deleteLast(List *);
void deleteNodeByValue(List *, int);
void deleteAll(List *);
void printList(List *);
void printNFirst(List *, int);
void printNLast(List *, int);

extern FILE *fpOut;

#endif // SLLIST_H_INCLUDED
