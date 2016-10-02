###########################################################
#                                                         #
#        Write by daixinning@gmail.com, 2016-09           #
#                                                         #
###########################################################

target := netopeer-cli

# 变量定义
objects_dir := $(objects_dir)/$(basename $(target))

# 源文件列表
source := commands.c      \
          configuration.c \
          main.c          \
          readinput.c

objs   := $(patsubst %.c, $(objects_dir)/%.o, $(source))

# 编译选项
CFLAGS  += -I../libnetconf
LDFLAGS += -lnetconf -lxml2 -lreadline -lpthread

# 编译目标依赖关系定义
$(release_dir)/$(target): $(objs)
	$(LD) -o $@ $(LDFLAGS) $^
	@echo "ld -o $(notdir $@)"

$(objects_dir)/%.o: %.c
	@[ -d $(dir $@) ] || (mkdir $(dir $@))
	$(CC) -o $@ $(CFLAGS) -c $<
	@echo "cc -o $(notdir $@) -c $(notdir $<)"

.PHONY: clean
clean:
	@-[ -d $(objects_dir) ] && (rm -fr $(objects_dir))
	@-[ -f $(release_dir)/$(target) ] && (rm $(release_dir)/$(target))
