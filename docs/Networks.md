# WiFi and Ethernet Connectivity

HomeSpan can connect to your home network either via WiFi or Ethernet. All of the ESP32 chips supported by HomeSpan come with built-in WiFi so no additional hardware is needed. Only a small number of ESP32 development boards come with an Ethernet interface (such as this [Silicognition wESP32](https://wesp32.com)) so additional hardware (such as this [Adafruit Ethernet FeatherWing](https://www.adafruit.com/product/3201)) would be needed to connect via Ethernet.

## HomeSpan WiFi connectivity

Unless HomeSpan detects that you installed and configured an Ethernet interface (see below), it will default to using WiFi to connect to your home network.  To make the connection HomeSpan requires the SSID and password for your network (your "WiFi Credentials"), which it saves in non-volatile storage (NVS) for retention even when power is lost.  At start-up HomeSpan checks its NVS for your WiFi Credentials.  If found, they are used to make the WiFi connection.  If not, HomeSpan outputs a message to the Serial Interface (if your device is connected to a computer) and flashes the HomeSpan Status LED (if you've added one) indicating that it requires you to provide your WiFi Credentials.  There are three ways of doing so:

1. **Entering your WiFi Credentials via the Serial Monitor**

    * If your device is connected to a computer via USB you can type 'W' into the Serial Monitor Command-Line Interface (the "CLI").  HomeSpan will scan your WiFi environment and display all network SSIDs found.  You can then choose which SSID to use, or type your own, and provide its password.  HomeSpan stores this information in NVS, reboots, and then uses these WiFi Credentials to connect to your network.

1. **Entering your WiFi Credentials via the HomeSpan Setup Access Point**

    * If your device is not connected to a computer but you've added both a HomeSpan Control Button and a HomeSpan Status LED you can activate the HomeSpan Command Mode (see the [User Guide](UserGuide.md) for details) and start the HomeSpan Setup Access Point. This launches a captive WiFi Access Point on your device that hosts the HomeSpan Setup web form into which you can enter the WiFi Credentials for your home network.  Once entered HomeSpan uses these credentials to connect to your network, and if successful saves the credentials in NVS, reboots, and proceeds as per above.  Some things to note:

      * you can alternatively launch the HomeSpan Setup Access Point from the CLI by typing 'A'.  However, this is primarily for testing purposes since if your device is already connected to a computer via USB you might as well use the 'W' method above
      * you can change the name, password, and time-out of the HomeSpan Setup Access Point using the following homeSpan methods: `setApSSID()`, `setApPassword()`, and `setApTimeout()` (see the [API Reference](Reference.md) page for details on all homeSpan methods)
      * if you add the homeSpan `enableAutoStartAP()` method to your sketch, HomeSpan will *automatically* launch its Setup Access Point if it does not find any WiFi Credentials stored in NVS upon start-up
      * if you really don't like the look and feel of the HomeSpan Setup Access Point you can create your own method of having HomeSpan acquire your WiFi Credentials by implementing the homeSpan `setApFunction()` method in your sketch
      * yes, Apple does have a more robust method for WiFi-based HomeKit devices to seemlessly acquire WiFi Credentials from your iPhone, but no, this can't be used by HomeSpan because Apple restricts this method to only licensed commercial HomeKit devices
    
1. **Hardcoding your WiFi Credentials in your HomeSpan sketch**

    * If neither of the above methods is appealing, you have the option of hardcoding your WiFi Credentials directly into your sketch using the homeSpan `setWifiCredentials()` method, though this is not considered a good practice for security reasons.

When HomeSpan tries to connect to your home network using your WiFi Credentials, it makes the requests and then waits for a response.  If after a certain time it does not connect, it makes another request and waits a bit longer for a response.  After each failed attempt, HomeSpan increases the wait time using a specified pattern, after which the pattern repeats.  The default pattern is to start by waiting 5 seconds, then 8, 14, 22, 36, and 60 seconds, after which the pattern starts over again with 5 seconds.  If desired, you can create your own request/response wait-time pattern using the homeSpan `setConnectionTimes()` method.

Once connected, HomeSpan automatically manages all reconnects if connectivity is lost (using the same request/response wait pattern as above).  If you have enabled Web Logging, all disconnects and reconnects are logged.

If your home network is based on a mesh router with multiple access points sharing the same SSID, HomeSpan automatically connects the access point with the strongest RSSI signal.  As an option, you can add the homeSpan `enableWiFiRescan()` method to your sketch to have HomeSpan periodically recan your WiFi network to see if there is a stronger access point with the same SSID.  If one is found, HomeSpan disconnects from the existing access point and reconnects to the stronger one.  In both the Serial Monitor and the Web Log (if enabled), HomeSpan indicates the BSSID (i.e. the 6-byte MAC address) of the specific access point to which it is connected.  As an option, you can map BSSIDs to custom display names using the homeSpan `addBssidName()` method.  When specified, HomeSpan will show these display names next to any BSSID in a log file to make it easier to track which access point is being used.

Internally, HomeSpan manages WiFi connectivity using the Arduino-ESP32 library's global `WiFi` object and initiates connections using the `WiFi.begin()` method.  This method assumes connectivity to standard WiFi network requiring an SSID and password.  If you are trying to connect to an enterprise WiFi network, or if you have other specialized configuration requirements that need to be made while connecting to your WiFi network (such as changing the power of your WiFi antenna), you can create your own "begin" function for HomeSpan will call instead by implementing the homeSpan `setWifiBegin()` method in your sketch.

Lastly, if you need to call any other functions either once, or every time, a WiFi connection is established (or re-established after a disconnect) you can implement the homeSpan `setConnectionCallback()` method in your sketch.

## HomeSpan Ethernet connectivity

HomeSpan utilizes the Arduino-ESP32 library's global `ETH` object to manage Ethernet connectivity and thus supports any Ethernet board that is supported by the Arduino-ESP32 library.  To establish an Ethernet connection, simply add `ETH.begin()` in the `setup()` section of your sketch somewhere before calling `homeSpan.begin()`.  The `ETH.begin()` function requires different parameters depending the specific Ethernet interface, or external board, you are using.  Please consult the instructions that came with your Ethernet interface/board and work with the Ethernet examples Espressif provides in the Arduino-ESP32 library to determine the correct parameters for your board.

There is nothing you need to add in your HomeSpan sketch to inform it that you will be using an Ethernet connection instead of WiFi.  Rather, at startup, if HomeSpan detects an Ethernet interface device has been *properly* configured and initialized using `ETH.begin()`, HomeSpan will automatically switch into "Ethernet mode" and use Ethernet instead of WiFi for all communications to and from your home network.  Note that the Ethernet cable itself does not need to be plugged into your router for HomeSpan to switch into "Ethernet mode" during start-up.

Similar to WiFi connectivity, HomeSpan automatically handles all Ethernet disconnects/reconnects (e.g. if you unplug the Ethernet cable and then plug it back into the router, or if the router itself reboots) and records such events in the Web Log (if enabled).  Also similar to using WiFi, to run a custom function either once, or every time, an Ethernet connection is established (or re-established after a disconnect) you can implement the homeSpan `setConnectionCallback()` method in your sketch.

---

[↩️](../README.md) Back to the Welcome page


