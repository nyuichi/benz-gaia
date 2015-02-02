/**
 * See Copyright Notice in picrin.h
 */

#include "picrin.h"

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

int
xf_file_read(void *cookie, char *ptr, int size)
{
  int s = size;
  while (s-- > 0) {
    *ptr++ = getchar();
  }
  return size;
}

int
xf_file_write(void *cookie, const char *ptr, int size)
{
  int s = size;
  while (s-- > 0) {
    putchar(*ptr++);
  }
  return size;
}

long
xf_file_seek(void *cookie, long pos, int whence)
{
  return 0;
}

int
xf_file_flush(void *cookie)
{
  return 0;
}

int
xf_file_close(void *cookie)
{
  return 0;
}

xFILE *
xfopen()
{
  xFILE *file;

  file = xfunopen(NULL, xf_file_read, xf_file_write, xf_file_seek, xf_file_flush, xf_file_close);
  if (! file) {
    return NULL;
  }

  return file;
}

static void *
pic_default_allocf(void *ptr, size_t size)
{
  if (size == 0) {
    if (ptr) {
      free(ptr);
    }
    return NULL;
  }
  if (ptr) {
    return realloc(ptr, size);
  } else {
    return malloc(size);
  }
}

static int
pic_default_setjmpf(void *buf)
{
  return setjmp(*(jmp_buf *)buf);
}

static void
pic_default_longjmpf(void *buf, int val)
{
  if (buf == NULL) {
    abort();
  }
  longjmp(*(jmp_buf *)buf, val);
}

/* Simple REPL program */

int
main()
{
  pic_state *pic;
  pic_value expr;
  void *p;

  pic = pic_open(pic_default_allocf, pic_default_setjmpf, pic_default_longjmpf, sizeof(jmp_buf), 0, NULL, NULL, p = xfopen(), xfopen(), xfopen());

  while (1) {
    printf("> ");

    expr = pic_read(pic, pic->xSTDIN);

    if (pic_eof_p(expr)) {
      break;
    }

    pic_printf(pic, "~s\n", pic_eval(pic, expr, pic->lib));
  }

  pic_close(pic);

  return 0;
}
