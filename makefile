all: input logic gui main build

.PHONY: input logic gui main build

input:
	$(MAKE) -C input all

logic:
	$(MAKE) -C logic all

gui:
	$(MAKE) -C gui all

main:
	$(MAKE) -C main all

build:
	$(MAKE) -C build all







