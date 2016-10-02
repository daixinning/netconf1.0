###########################################################
#                                                         #
#        Write by daixinning@gmail.com, 2016-09           #
#                                                         #
###########################################################

# 根据产品选择编译工具链
ifeq (test$(product), test)
    export CC := @gcc
    export AR := @ar
    export LD := @gcc
    export target_arch := $(shell dpkg --print-architecture)
else
    include $(product)/Makefile
endif

# 相关目录定义
project_dir := $(shell cd ..; pwd)
export release_dir := $(project_dir)/release/$(target_arch)
export objects_dir := $(release_dir)/obj

# 默认编译选项定义
export CFLAGS  := -g -Wall
export CFLAGS  += -I=/usr/include/libxml2
export CFLAGS  += -DNC_WORKINGDIR_PATH=\"/usr/local/etc/netopeer\"
export CFLAGS  += -DDS_DIR=\"/usr/local/etc/netopeer/datastore\"
export CFLAGS  += -DCFG_DIR=\"/usr/local/etc/netopeer/config\"
export CFLAGS  += -DSCHEMA_DIR=\"/usr/local/etc/netopeer/schema\"
export CFLAGS  += -DSETBIT=0 -DRCSID=\"0.9.0\" -DVERSION=\"0.9.0\"
export LDFLAGS := -L$(release_dir)

# dpkg包文件
bins := $(shell ls $(release_dir) | grep -v 'obj\|.*\..*')
libs := $(shell ls $(release_dir) | grep lib.*\.so)

# 子项目路径
subsystem_dir :=
subsystem_dir += $(project_dir)/src/libnetconf
subsystem_dir += $(project_dir)/src/server
subsystem_dir += $(project_dir)/src/client

.PHONY: all build clean install uninstall
build:
	@[ -d $(release_dir) ] || (mkdir -p $(release_dir))
	@[ -d $(objects_dir) ] || (mkdir -p $(objects_dir))
	@$(foreach dir, $(subsystem_dir), \
		echo "Begin to build $(dir)"; \
		make -k --no-print-directory -C $(dir) && echo;)
	@echo "<<< Build finished! >>>\n"

clean:
	@$(foreach dir, $(subsystem_dir), \
		echo "Begin to clean $(dir)"; \
		make -k --no-print-directory -C $(dir) clean && echo;)
	@!([ -d $(objects_dir) ]) || (rmdir $(objects_dir))
	@!([ -d $(release_dir) ]) || (rmdir $(release_dir))
	@echo "<<< Clean finished! >>>\n"

install:
	@cp $(addprefix $(release_dir)/, $(bins)) /usr/local/bin
	@cp $(addprefix $(release_dir)/, $(libs)) /usr/local/lib
	@echo "<<< Install finished! >>>\n"

uninstall:
	@rm $(addprefix /usr/local/bin/, $(bins))
	@rm $(addprefix /usr/local/lib/, $(libs))
	@echo "<<< Uninstall finished! >>>\n"

all: clean build
