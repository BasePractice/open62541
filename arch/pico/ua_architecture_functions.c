#ifdef UA_ARCHITECTURE_PICO

#include <open62541/types.h>

char *gai_strerror(int code) {
    return 0;
}

unsigned int UA_socket_set_blocking(UA_SOCKET sockfd){
  int on = 0;
  if(lwip_ioctl(sockfd, FIONBIO, &on) < 0)
    return UA_STATUSCODE_BADINTERNALERROR;
  return UA_STATUSCODE_GOOD;
}

unsigned int UA_socket_set_nonblocking(UA_SOCKET sockfd){
  int on = 1;
  if(lwip_ioctl(sockfd, FIONBIO, &on) < 0)
    return UA_STATUSCODE_BADINTERNALERROR;
  return UA_STATUSCODE_GOOD;
}

int gethostname_lwip(char* name, size_t len){
  /* gethostname() returns the null-terminated hostname in the
   * character array name, which has a length of len bytes.  If the
   * null-terminated hostname is too large to fit, then the name is
   * truncated, and no error is returned (but see NOTES below).
   */
#if LWIP_NETIF_HOSTNAME
  if ( (netif_default != NULL) && (netif_get_hostname(netif_default) != NULL) ) {
    /* LWIP has one hostname per netif. However majority of embedded systems using LWIP
     * use a single netif anyway (LWIP_SINGLE_NETIF).
     * Use the default netif for retrieving hostname. */
    const char * hostname = netif_get_hostname(netif_default);
    int result = 0;

#if LWIP_TCPIP_CORE_LOCKING
    /* Lock TCP/IP thread */
    LOCK_TCPIP_CORE();
#endif
    /* The GNU C library does not employ the gethostname() system call;
     * instead, it implements gethostname() as a library function that
     * calls uname(2) and copies up to len bytes from the returned
     * nodename field into name.  Having performed the copy, the
     * function then checks if the length of the nodename was greater
     * than or equal to len, and if it is, then the function returns -1
     * with errno set to ENAMETOOLONG; in this case, a terminating null
     * byte is not included in the returned name. */
    strncpy(name, hostname, len);

    if (strlen(hostname) >= len) {
      /* Error ENAMETOOLONG, hostname is larger than given buffer */
      result = -1;
    }

#if LWIP_TCPIP_CORE_LOCKING
    /* Unlock TCP/IP thread */
   UNLOCK_TCPIP_CORE();
#endif

    return result;
  }
#endif /* LWIP_NETIF_HOSTNAME */

  /* No valid hostname, due to one of the following
   *   1. LWIP_NETIF_HOSTNAME not defined
   *   2. no default netif set
   *   3. no hostname on default netif set.
   * use UA_ServerConfig_set_customHostname to set your hostname as the IP manually */
  return -1;
}

void UA_initialize_architecture_network(void){
  return;
}

void UA_deinitialize_architecture_network(void){
  return;
}

#if UA_IPV6
# if LWIP_VERSION_IS_RELEASE //lwip_if_nametoindex is not yet released
unsigned int lwip_if_nametoindex(const char *ifname){
  return 1; //TODO: assume for now that it only has one interface
}
# endif //LWIP_VERSION_IS_RELEASE
#endif //UA_IPV6

#endif /* UA_ARCHITECTURE_PICO */
