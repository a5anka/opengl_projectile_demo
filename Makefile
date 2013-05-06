PROGRAM = projectile2D
SRCS = projectile2D.c
OBJS = $(subst .c,.o,$(SRCS))

CFLAGS = -lGL -lGLU -lglut

$(PROGRAM): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	$(RM) $(OBJS) $(PROGRAM)
