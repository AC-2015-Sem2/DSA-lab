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

#include <stdio.h>
#include <string.h>

#include "dllist.h"

#define BUFFER_SIZE 1024

FILE *fpIn, *fpOut;

int main()
{
  char buffer[BUFFER_SIZE];
  int data;
  ListD *List;
  NodeD *pNode;

  List = createList();
  if ((fpIn = fopen("input.dat", "r")) == NULL)
    {
      perror("error opening input file!");
      return -1;
    }
  if ((fpOut = fopen("output.dat", "w")) == NULL)
    {
      perror("error opening output file!");
      return -1;
    }
  while (fscanf(fpIn, "%s", buffer) > 0)
    {
      if (strcmp(buffer, "AF") == 0)
	{
	  if (fscanf(fpIn, "%d", &data) > 0)
	    {
	      pNode = createNode(data);
	      addAtFirst(List, pNode);
	    }
	}
      if (strcmp(buffer, "AL") == 0)
	{
	  if (fscanf(fpIn, "%d", &data) > 0)
	    {
	      pNode = createNode(data);
	      addAtLast(List, pNode);
	    }
	}
      if (strcmp(buffer, "DF") == 0)
	deleteFirst(List);
      if (strcmp(buffer, "DL") == 0)
	deleteLast(List);
      if (strcmp(buffer, "DOOM_THE_LIST") == 0)
	deleteAll(List);
      if (strcmp(buffer, "DE") == 0)
	if (fscanf(fpIn, "%d", &data) > 0)
	  deleteNodeByValue(List, data);
      if (strcmp(buffer, "PRINT_ALL") == 0)
	printList(List);
      if (strcmp(buffer, "PRINT_F") == 0)
	if (fscanf(fpIn, "%d", &data) > 0)
	  printNFirst(List, data);
      if (strcmp(buffer, "PRINT_L") == 0)
	if (fscanf(fpIn, "%d", &data) > 0)
	  printNLast(List, data);
    }
  if (fclose(fpIn) != 0)
    {
      perror("error closing input file!");
      return -1;
    }
  if (fclose(fpOut) != 0)
    {
      perror("error closing output file!");
      return -1;
    }
  return 0;
}
