# Door State Change Notification System

The "Door State Change Notification System" is a comprehensive IoT project that utilizes a Particle Argon device, a Linux machine (Raspberry Pi), and a reed sensor to monitor the state of a door and send notifications via the IFTTT API when the door is opened.

Key Components:

1. **Hardware Setup**: A reed switch is connected to a Particle device and affixed to a door. When the door state changes (opened or closed), the sensor triggers the Particle device.
2. **Particle Device**: Connected to a WiFi network and powered up, this device is flashed with a custom code (provided in the repo) to track the reed sensor's state and publish changes.
3. **Raspberry Pi Server**: A Raspberry Pi connected to a buzzer runs a Node.js server (ExpressJS), with the script provided in this repository. The server listens for HTTP POST requests coming from the Particle device.
4. **Localtunnel**: A public URL is created using Localtunnel to allow the Particle device to publish door state changes to the Express server.
5. **Particle Webhooks**: A webhook is created on the Particle console to send a POST request to the Express server (via the Localtunnel URL) whenever the door state changes.
6. **IFTTT Integration**: The system is integrated with IFTTT. Whenever the Particle device publishes a state change, a flow triggers a notification on the user's phone.

This project illustrates a practical use case of IoT in home automation and security. The system could serve as a foundation for more sophisticated home security systems or other IoT-based applications.
