####

```shell
cmake .. -DCMAKE_C_COMPILER=D:/msys64/mingw64/bin/arm-none-eabi-gcc.exe \
-DCMAKE_CXX_COMPILER=D:/msys64/mingw64/bin/arm-none-eabi-c++.exe \
-DCMAKE_EXE_LINKER_FLAGS="-specs=nosys.specs" \
-DCMAKE_SYSTEM_NAME=Generic \
-DUA_BUILD_UNIT_TESTS:BOOL=OFF \
-DUA_BUILD_EXAMPLES:BOOL=OFF \
-DUA_BUILD_TOOLS:BOOL=ON \
-DUA_ENABLE_DISCOVERY:BOOL=ON \
-DUA_ENABLE_JSON_ENCODING:BOOL=OFF \
-DUA_ENABLE_SUBSCRIPTIONS:BOOL=ON \
-DUA_ENABLE_HISTORIZING:BOOL=OFF \
-DUA_ENABLE_DISCOVERY_MULTICAST:BOOL=OFF \
-DUA_NAMESPACE_ZERO:STRING=MINIMAL \
-DUA_ENABLE_NODEMANAGEMENT:BOOL=OFF \
-DUA_ENABLE_HISTORIZING:BOOL=OFF \
-DUA_ENABLE_QUERY:BOOL=ON \
-DUA_ENABLE_PUBSUB:BOOL=ON \
-DUA_ENABLE_PUBSUB_INFORMATIONMODEL:BOOL=OFF \
-DUA_ENABLE_PUBSUB_INFORMATIONMODEL_METHODS:BOOL=OFF \
-DUA_ENABLE_DA:BOOL=OFF \
-DUA_ENABLE_SUBSCRIPTIONS_EVENTS:BOOL=OFF \
-DPython3_EXECUTABLE=D:/msys64/mingw64/bin/python3.exe \
-DUA_AMALGAMATION_ARCHITECTURES=pico \
-DUA_ARCHITECTURE=pico \
-DUA_ENABLE_AMALGAMATION=ON \
-DUA_ARCH_FREERTOS_USE_OWN_MEMORY_FUNCTIONS=OFF \
-DUA_ARCHITECTURE_PICO=ON \
-DPICO_SDK_PATH=E:/GitHub/pico/pico-sdk \
-DPICO_BOARD=pico_w \
-DWIFI_SSID=example \
-DWIFI_PASSWORD=example \
-DFREERTOS_KERNEL_PATH=E:/GitHub/FreeRTOS/FreeRTOS-Kernel \
-DPICO_CYW43_ARCH_FREERTOS=1 \
-DLWIP_DEBUG=0 \
-DLWIP_RC_RELEASE=1
```
