# Building and Installing ABII-c-logging-plugin

To build ABII-c-logging-plugin, obtain
the <a href=https://github.com/fredjt/ABII-c-logging-plugin/releases/latest>latest sources</a>, unpack them, and
enter the source directory. Then,

```
mkdir build
cd build

cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr -GNinja
ninja
sudo ninja install
```

To install in a local directory instead of system-wide in /usr, change CMAKE_INSTALL_PREFIX to the directory of
choice.  
A 32-bit plugin can be created with the cmake option -DBIT32=ON and optionally -DCMAKE_INSTALL_LIBDIR=lib32. This is
required for building the plugin to be injected into 32-bit applications like steam. 
