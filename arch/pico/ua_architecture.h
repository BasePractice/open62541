#ifdef UA_ARCHITECTURE_PICO

#ifndef PLUGINS_ARCH_PICO_UA_ARCHITECTURE_H_
#define PLUGINS_ARCH_PICO_UA_ARCHITECTURE_H_

#include "ua_lwip.h"
#include "ua_freeRTOS.h"

#if UA_MULTITHREADING >= 100
#error Multithreading unsupported
#else
#define UA_LOCK_INIT(lock)
#define UA_LOCK_DESTROY(lock)
#define UA_LOCK(lock)
#define UA_UNLOCK(lock)
#define UA_LOCK_ASSERT(lock, num)
#endif
#define UA_INPROGRESS EINPROGRESS
#define UA_strncasecmp strncasecmp

// freeRTOS does not have getifaddr
#undef UA_HAS_GETIFADDR

#ifndef IN6_IS_ADDR_UNSPECIFIED
# define IN6_IS_ADDR_UNSPECIFIED(a) \
        (((const uint32_t *) (a))[0] == 0                                      \
         && ((const uint32_t *) (a))[1] == 0                                      \
         && ((const uint32_t *) (a))[2] == 0                                      \
         && ((const uint32_t *) (a))[3] == 0)
#endif

char *gai_strerror(int code);

#include <open62541/architecture_functions.h>

#endif /* PLUGINS_ARCH_PICO_UA_ARCHITECTURE_H_ */

#endif /* UA_ARCHITECTURE_PICO */
