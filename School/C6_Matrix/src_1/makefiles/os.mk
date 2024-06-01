ifeq ($(UNAME_S),Linux)
    OS_VERSION := $(shell lsb_release -d)
endif
ifeq ($(UNAME_S),Darwin)
    OS_VERSION := $(shell sw_vers -productVersion)
endif

os:
	@echo "Operating System: $(UNAME_S)"
	@echo "$(OS_VERSION)"
