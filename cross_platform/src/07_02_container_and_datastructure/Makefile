ROOT_DIR := ../..
include $(ROOT_DIR)/src/build_settings/linux/build.conf

CURRENT_DIR := ./
APPS = $(shell find $(CURRENT_DIR)/ -maxdepth 1 -type d)
APPS := $(filter-out src build_settings, $(foreach i, $(APPS), $(notdir $(i))))

all: release
	@echo "**********************SUCCESS**************************"
	
release: 
	@echo "**********************$@**************************"
	@for i in $(APPS) ; do \
		echo "***$@ $$i" ; \
		if [ -f $$i/Makefile ]; then \
			make -C $$i 2>>$(ERRLOG) >>$(OUTLOG) || exit 1; \
		fi \
	done

clean:
	@echo "**********************$@**************************"
	@for i in $(APPS) ; do \
		echo "***$@ $$i" ; \
		if [ -f $$i/Makefile ]; then \
			make -C $$i $@ 2>>$(ERRLOG) >>$(OUTLOG) || exit 1; \
		fi \
	done
	

distclean:
	@echo "**********************$@**************************"
	@for i in $(APPS) ; do \
		echo "***$@ $$i" ; \
		if [ -f $$i/Makefile ]; then \
			make -C $$i $@ 2>>$(ERRLOG) >>$(OUTLOG) || exit 1; \
		fi \
	done
	

rebuild: clean release
	@echo "**********************SUCCESS**************************"

test:
	@echo "**********************$@**************************"
	@for i in $(APPS) ; do \
		echo "***$@ $$i" ; \
		if [ -f $$i/Makefile ]; then \
			make -C $$i $@ 2>>$(ERRLOG) >>$(OUTLOG) || exit 1; \
		fi \
	done
