### 项目介绍
本项目基于[libnetconf](https://github.com/CESNET/libnetconf) + [netopeer](https://github.com/CESNET/netopeer)的0.9.0版本构建，主要调整了编译工程。

### 依赖库
* libxml2-dev
* libxslt1-dev
* libcurl4-gnutls-dev
* libreadline-dev 
* libssh2-1-dev

### 编译
```
~$ cd netconf1.0/build
~/netconf1.0/build$ make
```

### 安装
```
~/netconf1.0/build$ sudo make install
~/netconf1.0/build$ cd /usr/local/etc
/usr/local/etc$ sudo mkdir -p netopeer/config
/usr/local/etc$ sudo mkdir -p netopeer/datastore
/usr/local/etc$ sudo mkdir -p netopeer/schema
/usr/local/etc$ sudo mkdir -p netopeer/transapi
/usr/local/etc$ sudo cp ~/netconf1.0/example/config/* netopeer/config
/usr/local/etc$ sudo cp ~/netconf1.0/example/datastore/* netopeer/datastore
/usr/local/etc$ sudo cp ~/netconf1.0/example/schema/* netopeer/schema
/usr/local/etc$ tree .
/usr/local/etc/
`-- netopeer
    |-- config
    |   |-- NETCONF-server.xml
    |   |-- Netopeer.xml
    |   `-- sshd_config
    |-- datastore
    |   |-- datastore-acm.xml
    |   |-- ietf-netconf-server.xml
    |   `-- netopeer.xml
    |-- schema
    |   |-- ietf-netconf-acm-data.rng
    |   |-- ietf-netconf-acm-gdefs.rng
    |   |-- ietf-netconf-acm-schematron.xsl
    |   |-- ietf-netconf-server.yin
    |   |-- ietf-x509-cert-to-name.yin
    |   |-- netopeer-cfgnetopeer.yin
    |   `-- relaxng-lib.rng
    `-- transapi
```

### 测试
```
~$ sudo netopeer-server -d
~$ netopeer-cli
netconf> connect --port 830 --login root 127.0.0.1
netconf> status
Current NETCONF session:
  ID          : 3
  Host        : 127.0.0.1
  Port        : 830
  User        : root
  Transport   : SSH
  Capabilities:
        urn:ietf:params:netconf:base:1.0
        urn:ietf:params:netconf:base:1.1
        urn:ietf:params:netconf:capability:writable-running:1.0
        urn:ietf:params:netconf:capability:candidate:1.0
        urn:ietf:params:netconf:capability:startup:1.0
        urn:ietf:params:netconf:capability:rollback-on-error:1.0
        urn:ietf:params:netconf:capability:interleave:1.0
        urn:ietf:params:netconf:capability:notification:1.0
        urn:ietf:params:netconf:capability:validate:1.0
        urn:ietf:params:netconf:capability:validate:1.1
        urn:ietf:params:netconf:capability:with-defaults:1.0?basic-mode=explicit&also-supported=report-all,report-all-tagged,trim,explicit
        urn:ietf:params:netconf:capability:url:1.0?scheme=scp,file
        urn:cesnet:tmc:netopeer:1.0?module=netopeer-cfgnetopeer&revision=2013-02-14
        urn:ietf:params:xml:ns:yang:ietf-netconf-server?module=ietf-netconf-server&revision=2014-01-24&features=ssh,inbound-ssh,outbound-ssh
        urn:ietf:params:xml:ns:yang:ietf-x509-cert-to-name?module=ietf-x509-cert-to-name&revision=2013-03-26
        urn:ietf:params:xml:ns:yang:ietf-netconf-acm?module=ietf-netconf-acm&revision=2012-02-22
        urn:ietf:params:xml:ns:yang:ietf-netconf-with-defaults?module=ietf-netconf-with-defaults&revision=2010-06-09
        urn:ietf:params:xml:ns:netconf:notification:1.0?module=notifications&revision=2008-07-14
        urn:ietf:params:xml:ns:netmod:notification?module=nc-notifications&revision=2008-07-14
        urn:ietf:params:xml:ns:yang:ietf-netconf-notifications?module=ietf-netconf-notifications&revision=2011-08-07
        urn:ietf:params:xml:ns:yang:ietf-netconf-monitoring?module=ietf-netconf-monitoring&revision=2010-10-04
        urn:ietf:params:xml:ns:netconf:base:1.0?module=ietf-netconf&revision=2011-03-08&features=writable-running,candidate,rollback-on-error,validate,startup,url
        urn:ietf:params:xml:ns:yang:ietf-yang-types?module=ietf-yang-types&revision=2013-07-15
        urn:ietf:params:xml:ns:yang:ietf-inet-types?module=ietf-inet-types&revision=2010-09-24
netconf> 
```