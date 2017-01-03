Network Provenance Functions (NPFs) concept was introduced in our paper "Transparent Web Service Auditing via Network Provenance Functions" presented in 26th International World Wide Web Conference (WWW) 2017, which allow to capture useful provenance of complex web services.

To install Network Provenance Functions, we need to install following three things on the server:

+ Modified version of Apache 2
+ NPFs Proxy
+ Provenance Recorder

We assume that kernel with Linux Provenance Modules (lpm) has been installed on the server. To install lpm visit the following link:

`https://bitbucket.org/uf_sensei/provenance-rhel-kernel`

First install all the following packages:

`yum install -y mysql mysql-devel php-mysql postgresql postgresql-devel unixODBC unixODBC-devel mysql-connector-odbc postgresql-odbc postgresql-server httpd httpd-devel php php-develphp-mysql php-odbc php-pgsql libxml2 libxml2-devel db4 db4-devel gdbm`

Then, move following configurations files to respective directories:

`mv conf/provmon_proto.h /usr/include/provmon_proto.h`

`mv conf/{my.cnf,odbc.ini,odbcinst.ini} /etc/{my.cnf,odbc.ini,odbcinst.ini}`

`mv conf/httpd.conf /usr/local/apache2/conf/httpd.conf`

Then, configure and install the modified version of Apache 2

```
  cd httpd-execution-partitions-2.2.31
  ./configure --prefix=/usr/local/apache \
  --enable-so \
  --enable-cgi	\
  --enable-info	\
  --enable-rewrite	\
  --enable-speling	\
  --enable-usertrack	\
  --enable-deflate \
  --enable-ssl	   \
  --enable-mime-magic

  make
  make install
  
```

To run modified Apache 2:

```
bash run.sh

```

Then, configure and install NPF proxy. By default, this proxy will listen on port 3360. You can port in `run.sh`. Currently, it will only parse SQL queries but it can be extended for XML, SOAP protocols ( details can be found in the paper).

```
 cd  npf_proxy
 bash run.sh

```

Finally, in order to compile provenance recorder, we need to install SNAP library and then copy provenance_recorder directory into the `snap/examples` directory and compile.
Run the following script inside provenance_recorder directory to start provenance recorder in background.
` bash install.sh `