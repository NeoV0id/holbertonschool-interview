#ifndef __SLIDE_LINE_H__
#define __SLIDE_LINE_H__

#define __SLIDE_LEFT__ 2
#define __SLIDE_RIGHT__ 1

#include <stdio.h>
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
int to_left(int *line, size_t size);
int to_right(int *line, size_t size);

#endif /* SLIDE_LINE_H */
