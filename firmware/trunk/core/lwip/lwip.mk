# List of the required lwIP files.
LWNETIFSRC = \
        ${LWIP}/src/netif/etharp.c \
        ${LWIP}/src/netif/loopif.c

LWCORESRC = \
        ${LWIP}/src/core/dhcp.c \
        ${LWIP}/src/core/dns.c \
        ${LWIP}/src/core/init.c \
        ${LWIP}/src/core/mem.c \
        ${LWIP}/src/core/memp.c \
        ${LWIP}/src/core/netif.c \
        ${LWIP}/src/core/pbuf.c \
        ${LWIP}/src/core/raw.c \
        ${LWIP}/src/core/stats.c \
        ${LWIP}/src/core/sys.c \
        ${LWIP}/src/core/tcp.c \
        ${LWIP}/src/core/tcp_in.c \
        ${LWIP}/src/core/tcp_out.c \
        ${LWIP}/src/core/udp.c

LWIPV4SRC = \
        ${LWIP}/src/core/ipv4/autoip.c \
        ${LWIP}/src/core/ipv4/icmp.c \
        ${LWIP}/src/core/ipv4/igmp.c \
        ${LWIP}/src/core/ipv4/inet.c \
        ${LWIP}/src/core/ipv4/inet_chksum.c \
        ${LWIP}/src/core/ipv4/ip.c \
        ${LWIP}/src/core/ipv4/ip_addr.c \
        ${LWIP}/src/core/ipv4/ip_frag.c

LWAPISRC = \
        ${LWIP}/src/api/api_lib.c \
        ${LWIP}/src/api/api_msg.c \
        ${LWIP}/src/api/err.c \
        ${LWIP}/src/api/netbuf.c \
        ${LWIP}/src/api/netdb.c \
        ${LWIP}/src/api/netifapi.c \
        ${LWIP}/src/api/sockets.c \
        ${LWIP}/src/api/tcpip.c

LWINC = \
        ${LWIP}/src/include \
        ${LWIP}/src/include/ipv4 \
        ${LWIP}/src/include/lwip \
        ${LWIP}/contrib/chibios \
        ${LWIP}/contrib/chibios/arch
