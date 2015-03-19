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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

FILE *fpIn; /* input file pointer */
FILE *fpOut; /* output file pointer */

int iflag, oflag;

int main(int argc, char *argv[])
{
  int opt;
  char *input, *output;

  while ((opt = getopt(argc, argv, "+i:o:")) != -1)
    switch (opt)
      {
      case 'i':
	strncpy(input, optarg, sizeof(input) - 1);
	break;
      case 'o':
	oflag = 1;
	strncpy(output, optarg, sizeof(input) - 1);
	break;
      default:
	fprintf(stderr, "usage: %s [-i FILE ] [-o FILE ]\n", argv[0]);
    }
  printf("test\n");
  exit(0);
}
