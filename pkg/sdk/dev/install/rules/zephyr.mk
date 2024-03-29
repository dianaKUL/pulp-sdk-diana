ifdef runner_args
export RUNNER_ARGS=$(runner_args)
endif

ZEPHYR_SRCS = $(foreach dir,$(APP_SRCS),$(CURDIR)/$(dir))

BUILDDIR = build/zephyr$(build_dir_ext)

ifdef USE_PMSIS_BSP
ZEPHYR_OPT += -DZEPHYR_MODULES=$(PULP_SDK_HOME)/install/src/pmsis_bsp
endif

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	cd $(BUILDDIR) && cmake -DBOARD=gapuino $(PULP_SDK_HOME)/install/rules/zephyr -DCMAKE_C_FLAGS="$(APP_CFLAGS)" -DTEST_SRCS=$(ZEPHYR_SRCS) $(ZEPHYR_OPT)

clean:
	rm -rf $(BUILDDIR)

all: $(BUILDDIR)
	cd $(BUILDDIR) && make all

run:
	cd $(BUILDDIR) && make run

conf: