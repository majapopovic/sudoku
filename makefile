all: build gui input logic
.PHONY: build gui input logic

build:
	$(MAKE) -C build -all

gui:
	$(MAKE) -C gui -all

input:
	$(MAKE) -C input -all

logic:
	$(MAKE) -C logic -all

main:
	$(MAKE) -C main -all




