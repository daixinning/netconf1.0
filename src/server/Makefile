###########################################################
#                                                         #
#        Write by daixinning@gmail.com, 2016-09           #
#                                                         #
###########################################################

target := netopeer-server

# 变量定义
objects_dir := $(objects_dir)/$(basename $(target))

# 源文件列表
agent_source  := agent.c                   \
                 agent_comm.c              \
                 agent_comm_socket.c       \
                 comm_socket.c

server_source := cfgnetopeer-transapi.c    \
                 comm_socket.c             \
                 netconf-server-transapi.c \
                 server.c                  \
                 server_comm_socket.c      \
                 server_operations.c

server_objs   := $(patsubst %.c, $(objects_dir)/%.o, $(server_source))
agent_objs   := $(patsubst %.c, $(objects_dir)/%.o, $(agent_source))

# 编译选项
CFLAGS  += -I../libnetconf -DDISABLE_DBUS
LDFLAGS += -lnetconf -lxml2 -lpthread

# 编译目标依赖关系定义
.PHONY: all clean
all: $(release_dir)/netopeer-server $(release_dir)/netopeer-agent

$(release_dir)/netopeer-server: $(server_objs)
	$(LD) -o $@ $(LDFLAGS) $^ 
	@echo "ld -o $(notdir $@)"

$(release_dir)/netopeer-agent: $(agent_objs)
	$(LD) -o $@ $(LDFLAGS) $^ 
	@echo "ld -o $(notdir $@)"

$(objects_dir)/%.o: %.c
	@[ -d $(dir $@) ] || (mkdir $(dir $@))
	$(CC) -o $@ $(CFLAGS) -c $<
	@echo "cc -o $(notdir $@) -c $(notdir $<)"

.PHONY: clean
clean:
	@-[ -d $(objects_dir) ] && (rm -fr $(objects_dir))
	@-[ -f $(release_dir)/netopeer-server ] && (rm $(release_dir)/netopeer-server)
	@-[ -f $(release_dir)/netopeer-agent ] && (rm $(release_dir)/netopeer-agent)
