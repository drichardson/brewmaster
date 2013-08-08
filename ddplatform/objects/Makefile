CC=clang
LD=clang
CFLAGS=-Wall -Werror -g -O0

TARGET_LIBCOBJECTS=libcobjects.a
LIBCOBJECTS_OBJS=DDObjectBase.o DDObjectDefinition.o DDException.o

TARGET_UNITTEST=unittest
UNITTEST_OBJS=unittest.o

TARGETS=$(TARGET_LIBCOBJECTS) $(TARGET_UNITTEST)


all: $(TARGETS)

$(TARGET_LIBCOBJECTS): $(LIBCOBJECTS_OBJS) run_unit_test
	$(AR) rcs $@ $<

run_unit_test: $(TARGET_UNITTEST)
	./unittest

$(TARGET_UNITTEST): $(UNITTEST_OBJS)
	$(CC) -o $@ $<

clean:
	$(RM) $(TARGETS) $(TARGET_LIBCOBJECTS) $(LIBCOBJECTS_OBJS) $(TARGET_UNITTEST) $(UNITTEST_OBJS)
