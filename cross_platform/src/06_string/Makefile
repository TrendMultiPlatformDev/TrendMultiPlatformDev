ROOT_DIR := ../..
include $(ROOT_DIR)/src/build_settings/linux/build.conf

SRC_LIST := $(wildcard *.cpp)
OBJ_LIST := $(SRC_LIST:.cpp=.o)
DEF_LIST := $(OBJ_LIST:.o=.d)

TARGET := ut 

all: $(TARGET)

release: $(TARGET)

$(TARGET): $(OBJ_LIST)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.d: %.cpp
	@set -e; $(RM) $@; \
	$(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	$(RM) $@.$$$$

-include $(DEF_LIST)
	
clean:
	$(RM) $(TARGET) $(OBJ_LIST)

distclean: clean
	$(RM) $(DEF_LIST)

test: $(TARGET)
	./$(TARGET) --show_progress

