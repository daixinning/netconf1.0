###########################################################
#                                                         #
#        Write by daixinning@gmail.com, 2016-09           #
#                                                         #
###########################################################

target := libnetconf.so

# 变量定义
objects_dir := $(objects_dir)/$(basename $(target))

# 源文件列表
source := callbacks.c                         \
          compat.c                            \
          datastore.c                         \
          error.c                             \
          internal.c                          \
          messages.c                          \
          nacm.c                              \
          notifications.c                     \
          session.c                           \
          ssh.c                               \
          transport.c                         \
          url.c                               \
          with_defaults.c                     \
          datastore/edit_config.c             \
          datastore/custom/datastore_custom.c \
          datastore/empty/datastore_empty.c   \
          datastore/file/datastore_file.c     \
          transapi/transapi.c                 \
          transapi/xmldiff.c                  \
          transapi/yinparser.c

objs   := $(patsubst %.c, $(objects_dir)/%.o, $(source))

# 编译选项
CFLAGS  += -fPIC -I.
LDFLAGS += -fPIC -shared -lxml2 -lxslt -lcurl -lrt -lpthread

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
